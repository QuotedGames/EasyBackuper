#include "ebdialogsettings.h"
#include "ui_ebdialogsettings.h"

EBDialogSettings::EBDialogSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EBDialogSettings)
{
    ui->setupUi(this);
}

EBDialogSettings::~EBDialogSettings()
{
    delete ui;
}

void EBDialogSettings::changeEvent(QEvent *e)
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
