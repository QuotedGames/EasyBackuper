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
