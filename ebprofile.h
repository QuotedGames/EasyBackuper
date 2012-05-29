#ifndef EBPROFILE_H
#define EBPROFILE_H

#include <QObject>
#include <QList>

class EBProfile : public QObject
{
    Q_OBJECT
public:
    explicit EBProfile(QObject *parent = 0);

    const QString & profileName();
    const QString & profileDescription();
    const QString & profileDestinationDir();

    bool            isActive();

    QList<QString>  profileFiles();



    void setProfileName(const QString &name);
    void setProfileDescription(const QString &description);
    void setDestinationDir(const QString &dir);

    void setActive(bool active);

    void setFiles(QList<QString> list);
    void addFile(const QString &file);




signals:
    
public slots:


private:

    QString mProfileName;
    QString mProfileDescription;
    QString mDistanationDirectory;


    QList<QString>  mFilesToCopy;

    bool mIsActive;

};

#endif // EBPROFILE_H
