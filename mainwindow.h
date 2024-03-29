#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QList>
#include <QListWidgetItem>
#include <QMessageBox>

#include "profilewidget.h"
#include "ebdialogsettings.h"
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

    void on_actionSettings_triggered();


    void onProfileSelected(QListWidgetItem *);
    void onProfileEntered(QListWidgetItem *);

    void on_actionRemove_selected_triggered();

private:
    Ui::MainWindow      *ui;

    EBDialogProfile     *mDialogProfile;
    EBDialogSettings    *mDialogSettings;

    QList<EBProfile *>  *mProfiles;


    void loadProfiles();

    void insertProfile(EBProfile *profile);
    void updateProfile(EBProfile *profile);
    void removeProfile(EBProfile *profile);

    void updateList();

    void saveNewProfile(EBProfile *profile);
    void saveExistingProfile(EBProfile *profile);
};

#endif // MAINWINDOW_H
