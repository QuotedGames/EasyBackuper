#include "ebdialogprofile.h"
#include "ui_ebdialogprofile.h"

#include <QDebug>

EBDialogProfile::EBDialogProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EBDialogProfile)
{
    ui->setupUi(this);
    this->mProfile = 0;
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
    this->mProfile = profile;
    this->prepareLayout();
}

void EBDialogProfile::prepareLayout()
{
    Q_ASSERT(this->mProfile);

    ui->pTitle->setText(this->mProfile->profileName());
    ui->pDescription->setText(this->mProfile->profileDescription());
    ui->pDestination->setText(this->mProfile->profileDestinationDir());

    for(int i = 0; i < this->mProfile->profileFiles().size(); ++i) {
        ui->pFiles->addItem(this->mProfile->profileFiles().at(i));
    }

    if(this->mProfile->profileFiles().size() == 0) {
        ui->bRemoveAll->setEnabled(false);
        ui->bRemoveFile->setEnabled(false);
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


    }
}
