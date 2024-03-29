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
    delete this->mProfile;
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
        // "generate" id
        this->mProfile->setUniqueId(QTime::currentTime().msec());
    } else {
        this->mProfile = profile;
    }
    this->prepareLayout();
}

void EBDialogProfile::prepareLayout()
{
    Q_ASSERT(this->mProfile);

    ui->pTitle->setText                 (this->mProfile->profileName());
    ui->pDestination->setText           (this->mProfile->profileDestinationDir());
    ui->pIntervalValue->setValue        (this->mProfile->intervalValue());
    ui->pIntervalMode->setCurrentIndex  (this->mProfile->intervalType());

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
        ui->bRemoveFile->setEnabled(false);
    } else {
        ui->bRemoveAll->setEnabled(true);
        ui->bRemoveFile->setEnabled(true);
    }

    if(ui->pFiles->count() > 0) {
        ui->pFiles->item(0)->setSelected(true);
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
            if(!this->fileExist(fNames.at(i))) {
                this->mProfile->addFile(fNames.at(i));
                this->mProfile->setProfileLastSourceDir(QDir(fNames.at(i)).absolutePath());
            }
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


bool EBDialogProfile::fileExist(const QString &file)
{
    return this->mProfile->profileFiles().contains(file);
}

void EBDialogProfile::on_bRemoveFile_clicked()
{
    if(ui->pFiles->selectedItems().size() == 0) {
        // no files selected, nothing to delete
        return;
    }

    QList<QListWidgetItem *> items = ui->pFiles->selectedItems();

    for(int i = 0; i < items.size(); ++i) {
        QListWidgetItem *item = items.at(i);
        int index = ui->pFiles->row(item);
        this->mProfile->removeFileAtIndex(index);
    }

    this->updateLayout();

}

void EBDialogProfile::on_bRemoveAll_clicked()
{
    this->mProfile->removeAllFiles();
    this->updateLayout();
}

void EBDialogProfile::on_bOk_clicked()
{
    // 1. Check if title is set
    if(ui->pTitle->text().isEmpty()) {
        ui->pTitle->setFocus();
        return;
    }

    if(this->mProfile->profileFiles().size() == 0) {
        // no files selected - notify user
        QMessageBox msgBox;
        msgBox.setText(tr("You should specify which files you want to backup."));
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        return;

    }

    if(ui->pDestination->text().isEmpty()) {
        // no destination - notify user
        QMessageBox msgBox;
        msgBox.setText(tr("You should specify destination folder."));
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        return;
    }

    this->mProfile->setProfileName      (ui->pTitle->text());
    this->mProfile->setDestinationDir   (ui->pDestination->text());
    this->mProfile->setIntervalValue    (ui->pIntervalValue->value());
    this->mProfile->setIntervalType     (ui->pIntervalMode->currentIndex());

    this->mProfile->setProfileDescription(tr("Files: %1, Interval: %2 %3. Destination: %4").arg(QString::number(this->mProfile->profileFiles().size()),
                                                                                                QString::number(this->mProfile->intervalValue()),
                                                                                                this->mProfile->intervalDescription(),
                                                                                                this->mProfile->profileDestinationDir()));

    emit this->profileModified(this->mProfile);
    this->close();
}

void EBDialogProfile::on_bSelectDest_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select destination folder"), this->mProfile->profileDestinationDir());

    if(dir.isEmpty())
        return;

    this->mProfile->setDestinationDir(QDir(dir).absolutePath());
    ui->pDestination->setText(this->mProfile->profileDestinationDir());
}

void EBDialogProfile::on_bAddFolder_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select source folder"), this->mProfile->profileDestinationDir());

    if(dir.isEmpty())
        return;

    // Check if directory has some sub-directory

    QDir folder(dir);

    bool hasSubdirs = false;

    QFileInfoList subItems = folder.entryInfoList();
    for(int i = 0; i < subItems.size(); ++i) {
        QFileInfo fileInfo = subItems.at(i);

        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir()) {
            qDebug() << "Subdir found: " << fileInfo.path();
            hasSubdirs = true;

            // Don't need to scan more
            break;
        }
    }

    if(hasSubdirs) {
        // Ask user if he wants recursive add subdirs with files
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setText(tr("The selected folder contains subfolders."));
        msgBox.setInformativeText(tr("Do you want include all subfolders?"));
        msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);

        if(msgBox.exec() == QMessageBox::Yes) {

            this->parseDirectory(dir, true);
        } else {
            this->parseDirectory(dir, false);
        }


    } else {
        this->parseDirectory(dir);
    }
    this->mProfile->setProfileLastSourceDir(QDir(dir).absolutePath());
    this->updateLayout();

}

void EBDialogProfile::parseDirectory(const QString &dir, bool recursive)
{
    qDebug() << "parsing directory" << dir << ", recursive:" << recursive;
    QDir folder(dir);
    QFileInfoList items = folder.entryInfoList();


    for(int i = 0; i < items.size(); ++i) {
        QFileInfo item = items.at(i);

        if(item.fileName() == "." || item.fileName() == "..")
            continue;

        if(item.isDir() && recursive) {
            qDebug() << i << "   -- dir found:" << item.absoluteFilePath();
            this->parseDirectory(item.absoluteFilePath(), true);
        } else {
            qDebug() << i << "   -- file added:" << item.absoluteFilePath();
            if(!this->fileExist(item.absoluteFilePath()))
                this->mProfile->addFile(item.absoluteFilePath());
        }

    }
}
