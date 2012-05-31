#ifndef EBDIALOGSETTINGS_H
#define EBDIALOGSETTINGS_H

#include <QDialog>

namespace Ui {
class EBDialogSettings;
}

class EBDialogSettings : public QDialog
{
    Q_OBJECT
    
public:
    explicit EBDialogSettings(QWidget *parent = 0);
    ~EBDialogSettings();
    
protected:
    void changeEvent(QEvent *e);
    
private:
    Ui::EBDialogSettings *ui;
};

#endif // EBDIALOGSETTINGS_H
