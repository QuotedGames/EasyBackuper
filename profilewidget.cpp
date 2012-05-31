#include "profilewidget.h"
#include "ui_profilewidget.h"

ProfileWidget::ProfileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileWidget)
{
    ui->setupUi(this);
    this->mProfile = 0;

#ifdef Q_OS_MAC
    ui->labelName->setFont(QFont("Lucida Grande", 12, 75));
    ui->labelDescription->setFont(QFont("Lucida Grande", 11));


#else

#endif
}

void ProfileWidget::setProfile(EBProfile *profile)
{
    this->mProfile = profile;
    this->configureWidget();
}

ProfileWidget::~ProfileWidget()
{
    delete ui;
}

void ProfileWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void ProfileWidget::configureWidget()
{
    ui->labelName->setText(this->mProfile->profileName());
    ui->labelDescription->setText(this->mProfile->profileDescription());
}
