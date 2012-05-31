#ifndef EBPROFILE_H
#define EBPROFILE_H

#include <QObject>
#include <QList>
#include <QTime>
#include <QHash>

class EBProfile : public QObject
{
    Q_OBJECT
public:

    QHash<int, QString> intervalTypes;

    explicit EBProfile(QObject *parent = 0);

    // Getters
    // -------
    const QString & profileName();
    const QString & profileDescription();
    const QString & profileDestinationDir();
    const QString & profileLastSourceDir();
    bool            isActive();
    int             uniqueId();
    int             intervalValue();
    int             intervalType();
    const QString & intervalDescription();
    QList<QString>  profileFiles();

    // Setters
    // -------
    void setProfileName             (const QString &name);
    void setProfileDescription      (const QString &description);
    void setDestinationDir          (const QString &dir);
    void setProfileLastSourceDir    (const QString &dir);
    void setUniqueId                (int id);
    void setIntervalValue           (int value);
    void setIntervalType            (int type);

    void setActive                  (bool active);

    void setFiles                   (QList<QString> list);
    void addFile                    (const QString &file);

    // Methods
    // -------
    void removeFileAtIndex          (const int index);
    void removeAllFiles();


signals:
    
public slots:


private:

    // Name displayed in the list
    QString mProfileName;

    // Generated description (num of files, interval usw.)
    QString mProfileDescription;

    // Destination folder
    QString mDistanationDirectory;

    // Stores last selected folder
    QString mLastSourceDirectory;

    // List of filepaths to copy
    QList<QString>  mFilesToCopy;

    // Indicates if profile is currently active
    bool mIsActive;

    // Id of the profile (unix_timestamp)
    int  mUniqueId;

    //
    int  mIntervalValue;

    // interval-type (0: min, 1: hours, 2: days)
    int mIntervalType;


};

#endif // EBPROFILE_H
