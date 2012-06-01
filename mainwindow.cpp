#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->mDialogProfile = new EBDialogProfile(this);
    this->mDialogSettings = new EBDialogSettings(this);

    connect(this->mDialogProfile,   SIGNAL(profileModified(EBProfile*)),
            this,                   SLOT  (onProfileModified(EBProfile*)));

    connect(ui->profileList,        SIGNAL(itemPressed(QListWidgetItem*)),
            this,                   SLOT  (onProfileSelected(QListWidgetItem*)));

    connect(ui->profileList,        SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this,                   SLOT(onProfileEntered(QListWidgetItem*)));

    this->mProfiles = new QList<EBProfile *>();

    ui->mainToolBar->actions().at(1)->setEnabled(false);

    this->loadProfiles();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->mDialogProfile;
    delete this->mDialogSettings;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void MainWindow::loadProfiles()
{


    QSettings settings("com.QuotedGames", "EasyBackuperSettings");

    //settings.clear();

    int profilesCount = settings.beginReadArray("settings/profiles");
    for(int i = 0; i < profilesCount; ++i) {
        settings.setArrayIndex(i);

        if(settings.value("uniqueId", 0).toInt() == 0)
            continue;

        EBProfile *p = new EBProfile();
        p->setProfileName           (settings.value("name",             tr("Unknown")).toString());
        p->setProfileDescription    (settings.value("description",      tr("Unknown")).toString());
        p->setDestinationDir        (settings.value("destination",      "").toString());
        p->setActive                (settings.value("isActive",         false).toBool());
        p->setProfileLastSourceDir  (settings.value("lastSourceDir",    "").toString());
        p->setUniqueId              (settings.value("uniqueId",         0).toInt());
        p->setIntervalValue         (settings.value("intervalValue",    1).toInt());
        p->setIntervalType          (settings.value("intervalType",     1).toInt());
        p->setInternId              (i);

        // read profile's files to copy
        int filesCount = settings.beginReadArray("files");
        for(int j = 0; j < filesCount; ++j) {
            settings.setArrayIndex(j);
            p->addFile(settings.value("file", "").toString());
        }
        settings.endArray();

        this->mProfiles->push_back(p);
    }
    settings.endArray();


    // Build listWinget

    for(int i = 0; i < this->mProfiles->size(); ++i) {

        EBProfile       *p = this->mProfiles->at(i);
        ProfileWidget   *pw = new ProfileWidget(this);

        pw->setProfile(p);

        QListWidgetItem *lw = new QListWidgetItem();

        lw->setSizeHint(QSize(ui->profileList->sizeHintForColumn(i), 44));
        pw->resize(QSize(ui->profileList->sizeHint().width(), 44));

        ui->profileList->addItem(lw);
        ui->profileList->setItemWidget(lw, pw);
    }

    ui->profileList->setCurrentRow(-1);

    ui->statusBar->showMessage(tr("Profiles loaded: %1").arg(this->mProfiles->size()));

}

void MainWindow::onProfileModified(EBProfile *profile)
{
    //Q_ASSERT(profile);

    if(profile == 0)
        return;

    if(this->mDialogProfile->isNewProfile()) {
        // add profile
        profile->setParent(this);
        this->insertProfile(profile);

    } else {
        // update profile
        this->updateProfile(profile);
    }
}


// Add new profile
void MainWindow::on_actionNew_profile_triggered()
{
    this->mDialogProfile->setProfile(0);

    this->mDialogProfile->setIsNewProfile(true);
    this->mDialogProfile->show();
}

void MainWindow::on_actionSettings_triggered()
{
    this->mDialogSettings->show();
}


void MainWindow::insertProfile(EBProfile *profile)
{
    qDebug() << profile;
    this->mProfiles->push_back(profile);

    this->saveNewProfile(profile);

    // insert new profile in the list
    ProfileWidget *w = new ProfileWidget(this);
    w->setProfile(this->mProfiles->last());

    QListWidgetItem *l = new QListWidgetItem();

    l->setSizeHint(QSize(ui->profileList->sizeHintForColumn(0), 44));
    w->resize(QSize(ui->profileList->sizeHint().width(), 44));

    ui->profileList->addItem(l);
    ui->profileList->setItemWidget(l, w);

}

void MainWindow::updateProfile(EBProfile *profile)
{

}

void MainWindow::updateList()
{
    // clear list first

    // then update
    for(int i = 0; i < this->mProfiles->size(); ++i) {
        ProfileWidget *w = new ProfileWidget(this);
        w->setProfile(this->mProfiles->at(i));

        QListWidgetItem *l = new QListWidgetItem();

        l->setSizeHint(QSize(ui->profileList->sizeHintForColumn(i), 44));
        w->resize(QSize(ui->profileList->sizeHint().width(), 44));

        ui->profileList->addItem(l);
        ui->profileList->setItemWidget(l, w);
    }
}


void MainWindow::onProfileSelected(QListWidgetItem *listItem)
{
    int row = ui->profileList->row(listItem);
    if(this->mProfiles->at(row) != 0) {
        ui->mainToolBar->actions().at(1)->setEnabled(true);
    } else {
        ui->mainToolBar->actions().at(1)->setEnabled(false);

    }
}

void MainWindow::on_actionRemove_selected_triggered()
{
    int row = ui->profileList->currentRow();
    if(this->mProfiles->at(row) == 0)
        return;


    // Ask user first

    QMessageBox msgBox;
    msgBox.setText(tr("Do you really want to delete this profile?"));
    msgBox.setInformativeText(tr("Profile: <b>%1</b><br>Files: %2, Interval: %3 %4").arg(this->mProfiles->at(row)->profileName(),
                                                                                QString::number(this->mProfiles->at(row)->profileFiles().size()),
                                                                                QString::number(this->mProfiles->at(row)->intervalValue()),
                                                                                 this->mProfiles->at(row)->intervalDescription()));
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    msgBox.setIcon(QMessageBox::Question);

    if(msgBox.exec() == QMessageBox::Ok) {

        // remove it

        ui->profileList->takeItem(row);
        ui->profileList->clearSelection();
        ui->profileList->doItemsLayout();

        this->removeProfile(this->mProfiles->at(row));

        this->mProfiles->takeAt(row);

        ui->mainToolBar->actions().at(1)->setEnabled(false);
    }
}

void MainWindow::onProfileEntered(QListWidgetItem *item)
{
    int row = ui->profileList->row(item);

    if(this->mProfiles->at(row) == 0)
        return;

    this->mDialogProfile->setProfile(this->mProfiles->at(row));
    this->mDialogProfile->setIsNewProfile(false);
    this->mDialogProfile->show();
}

void MainWindow::saveNewProfile(EBProfile *profile)
{

    QSettings settings("com.QuotedGames", "EasyBackuperSettings");

    int profilesCount = settings.beginReadArray("settings/profiles");
    settings.endArray();

    settings.beginWriteArray("settings/profiles");
    settings.setArrayIndex(profilesCount);

    profile->setInternId(profilesCount);

    settings.setValue("name", profile->profileName());
    settings.setValue("description", profile->profileDescription());
    settings.setValue("destination", profile->profileDestinationDir());
    settings.setValue("isActive",   profile->isActive());
    settings.setValue("lastSourceDir", profile->profileLastSourceDir());
    settings.setValue("uniqueId", profile->uniqueId());
    settings.setValue("intervalValue", profile->intervalValue());
    settings.setValue("intervalType", profile->intervalType());

    settings.endArray();

    // Write files:
    settings.beginWriteArray("settings/profiles/" + QString::number(profilesCount + 1) + "/files");
    for(int i = 0; i < profile->profileFiles().size(); ++i) {
        settings.setArrayIndex(i);
        settings.setValue("file", profile->profileFiles().at(i));
    }
    settings.endArray();
}


void MainWindow::removeProfile(EBProfile *profile)
{
    int index = profile->internId();

    QSettings settings("com.QuotedGames", "EasyBackuperSettings");

    settings.beginReadArray("settings/profiles");

    settings.setArrayIndex(index);
    settings.remove("");

    settings.endArray();
}
