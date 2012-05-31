#include "ebdialogprofile.h"
#include "ui_ebdialogprofile.h"

#include <QDebug>

EBDialogProfile::EBDialogProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EBDialogProfile)
{
    ui->setupUi(this);
    this->mProfile = 0;
    this->mIsNewProfile = true;

}

EBDialogProfile::~EBDialogProfile()
{
    delete ui;
}

void EBDialogProfile::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void EBDialogProfile::setProfile(EBProfile *profile)
{
    if(profile == 0) {
        this->mProfile = new EBProfile();
    } else {
        this->mProfile = profile;
    }
    this->prepareLayout();
}

void EBDialogProfile::prepareLayout()
{
    Q_ASSERT(this->mProfile);

    ui->pTitle->setText(this->mProfile->profileName());
    ui->pDescription->setText(this->mProfile->profileDescription());
    ui->pDestination->setText(this->mProfile->profileDestinationDir());

    this->buildList();

}

void EBDialogProfile::updateLayout()
{
    // Update only list of files and "remove"-buttons

    this->buildList();
}

void EBDialogProfile::buildList()
{
    ui->pFiles->clear();
    for(int i = 0; i < this->mProfile->profileFiles().size(); ++i) {
        ui->pFiles->addItem(this->mProfile->profileFiles().at(i));
        ui->pFiles->item(i)->setSizeHint(QSize(ui->pFiles->size().width()-10, 20));
    }

    if(this->mProfile->profileFiles().size() == 0) {
        ui->bRemoveAll->setEnabled(false);
    } else {
        ui->bRemoveAll->setEnabled(true);
    }

}

void EBDialogProfile::on_bCancel_clicked()
{
    this->mProfile = 0;
    emit this->profileModified(this->mProfile);

    this->close();
}

void EBDialogProfile::on_bAddFile_clicked()
{
    QStringList fNames = QStringList();

    fNames = QFileDialog::getOpenFileNames(this, tr("Select files"), this->mProfile->profileLastSourceDir());

    if(fNames.size() > 0) {
        for(int i = 0; i < fNames.size(); ++i) {
            this->mProfile->addFile(fNames.at(i));
            this->mProfile->setProfileLastSourceDir(QDir(fNames.at(i)).absolutePath());
        }

        // Update window-layout
        this->updateLayout();

    }


}

void EBDialogProfile::setIsNewProfile(bool isNew)
{
    this->mIsNewProfile = isNew;
}

bool EBDialogProfile::isNewProfile()
{
    return this->mIsNewProfile;
}
