#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>
#include <QFont>

#include "ebprofile.h"

namespace Ui {
class ProfileWidget;
}

class ProfileWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit ProfileWidget(QWidget *parent = 0);
    ~ProfileWidget();
    
    void setProfile(EBProfile *profile);

protected:
    void changeEvent(QEvent *e);
    
private:
    Ui::ProfileWidget *ui;
    EBProfile         *mProfile;


    void configureWidget();
};

#endif // PROFILEWIDGET_H
