#ifndef EBDIALOGPROFILE_H
#define EBDIALOGPROFILE_H

#include <QDialog>
#include <QFile>

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
    
protected:
    void changeEvent(QEvent *e);

signals:
    void profileModified(EBProfile *);
    
private:
    Ui::EBDialogProfile *ui;
    EBProfile           *mProfile;


    void prepareLayout();
};

#endif // EBDIALOGPROFILE_H
