#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QList>

#include "profilewidget.h"
#include "ebdialogprofile.h"
#include "ebprofile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
protected:
    void changeEvent(QEvent *e);
    
private slots:
    void on_actionNew_profile_triggered();


    void onProfileModified(EBProfile *);

private:
    Ui::MainWindow *ui;

    EBDialogProfile *mDialogProfile;

    QList<EBProfile *> *mProfiles;


    void loadProfiles();
};

#endif // MAINWINDOW_H
