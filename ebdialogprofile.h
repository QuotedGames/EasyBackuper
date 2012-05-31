#ifndef EBDIALOGPROFILE_H
#define EBDIALOGPROFILE_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QDir>


#include <ebprofile.h>


namespace Ui {
class EBDialogProfile;
}

class EBDialogProfile : public QDialog
{
    Q_OBJECT
    
public:
    explicit EBDialogProfile(QWidget *parent = 0);
    ~EBDialogProfile();

    void setProfile(EBProfile *profile);
    void setIsNewProfile(bool isNew);

    bool isNewProfile();
    
protected:
    void changeEvent(QEvent *e);

signals:
    void profileModified(EBProfile *);

    
private slots:
    void on_bCancel_clicked();

    void on_bAddFile_clicked();

    void on_bRemoveFile_clicked();

    void on_bRemoveAll_clicked();

    void on_bOk_clicked();

private:
    Ui::EBDialogProfile *ui;
    EBProfile           *mProfile;
    bool                 mIsNewProfile;

    void prepareLayout();
    void updateLayout();
    void buildList();

    bool fileExist(const QString & file);
};

#endif // EBDIALOGPROFILE_H
