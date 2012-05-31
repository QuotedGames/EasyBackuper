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
    const QString & profileLastSourceDir();

    bool            isActive();

    QList<QString>  profileFiles();



    void setProfileName             (const QString &name);
    void setProfileDescription      (const QString &description);
    void setDestinationDir          (const QString &dir);
    void setProfileLastSourceDir    (const QString &dir);

    void setActive(bool active);

    void setFiles(QList<QString> list);
    void addFile(const QString &file);

    void removeFileAtIndex(const int index);
    void removeAllFiles();


signals:
    
public slots:


private:

    QString mProfileName;
    QString mProfileDescription;
    QString mDistanationDirectory;
    QString mLastSourceDirectory;


    QList<QString>  mFilesToCopy;

    bool mIsActive;

};

#endif // EBPROFILE_H
