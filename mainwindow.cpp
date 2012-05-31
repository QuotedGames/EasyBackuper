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
            this,                   SLOT(onProfileModified(EBProfile*)));

    connect(ui->profileList,        SIGNAL(itemPressed(QListWidgetItem*)),
            this,                   SLOT(onProfileSelected(QListWidgetItem*)));

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
    // Dummy
    // -----
    QSettings settings("com.QuotedGames", "EasyBackuperSettings");


    int profilesCount = settings.beginReadArray("settings/profiles");
    for(int i = 0; i < profilesCount; ++i) {
        settings.setArrayIndex(i);

        EBProfile *p = new EBProfile();
        p->setProfileName           (settings.value("name",             tr("Unknown")).toString());
        p->setProfileDescription    (settings.value("description",      tr("Unknown")).toString());
        p->setDestinationDir        (settings.value("destination",      "").toString());
        p->setActive                (settings.value("isActive",         false).toBool());
        p->setProfileLastSourceDir  (settings.value("lastSourceDir",    "").toString());

        // read profile's files to copy
        int filesCount = settings.beginReadArray("settings/profiles/files");
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

        // pw -> setProfile

        QListWidgetItem *lw = new QListWidgetItem();

        lw->setSizeHint(QSize(ui->profileList->sizeHintForColumn(i), 44));
        pw->resize(QSize(ui->profileList->sizeHint().width(), 44));

        ui->profileList->addItem(lw);
        ui->profileList->setItemWidget(lw, pw);
    }

    ui->profileList->setCurrentRow(-1);

    ui->statusBar->showMessage(tr("Profiles loaded: %1").arg(this->mProfiles->size()));

/*
    for(int i = 0; i < 5; ++i) {
        ProfileWidget *w1 = new ProfileWidget(this);
        QListWidgetItem *i1 = new QListWidgetItem();

        qDebug() << "size before resizing:" << w1->size();

        i1->setSizeHint(QSize(ui->profileList->sizeHintForColumn(i), 44));
        w1->resize(QSize(ui->profileList->sizeHint().width(), 44));

        qDebug() << "size after resizing:" << w1->size();

        ui->profileList->addItem(i1);
        ui->profileList->setItemWidget(i1, w1);
    }
*/

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
    msgBox.setInformativeText(tr("Profile: %1 (files: %2, interval: %3)").arg(this->mProfiles->at(row)->profileName(), "10", "5 Hours"));
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    msgBox.setIcon(QMessageBox::Question);

    if(msgBox.exec() == QMessageBox::Ok) {

        // remove it

        ui->profileList->takeItem(row);
        ui->profileList->clearSelection();
        ui->profileList->doItemsLayout();
        this->mProfiles->removeAt(row);

        ui->mainToolBar->actions().at(1)->setEnabled(false);
    }
}
