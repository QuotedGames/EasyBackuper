#include "ebprofile.h"





EBProfile::EBProfile(QObject *parent) :
    QObject(parent)
{
    intervalTypes.insert(0, tr("Minute(s)"));
    intervalTypes.insert(1, tr("Hour(s)"));
    intervalTypes.insert(2, tr("Day(s)"));

    this->mIsActive             = false;
    this->mProfileName          = "";
    this->mProfileDescription   = "";
    this->mFilesToCopy          = QList<QString>();
    this->mDistanationDirectory = "";
    this->mLastSourceDirectory  = "";
    this->mUniqueId             = 0;
    this->mIntervalValue        = 1;
    this->mIntervalType         = 1; // default is hours
    this->mInternalId           = -1;

}

const QString & EBProfile::profileName()
{
    return this->mProfileName;
}

const QString & EBProfile::profileDescription()
{
    return this->mProfileDescription;
}

const QString & EBProfile::profileDestinationDir()
{
    return this->mDistanationDirectory;
}

const QString & EBProfile::profileLastSourceDir()
{
    return this->mLastSourceDirectory;
}

bool EBProfile::isActive()
{
    return this->mIsActive;
}

int EBProfile::uniqueId()
{
    return this->mUniqueId;
}

int EBProfile::intervalValue()
{
    return this->mIntervalValue;
}

int EBProfile::intervalType()
{
    return this->mIntervalType;
}

const QString & EBProfile::intervalDescription()
{
    return intervalTypes[this->mIntervalType];
}


QList<QString> EBProfile::profileFiles()
{
    return this->mFilesToCopy;
}

int EBProfile::internId()
{
    return this->mInternalId;
}

void EBProfile::setProfileName(const QString &name) {
    this->mProfileName = name;
}

void EBProfile::setProfileDescription(const QString &description) {
    this->mProfileDescription = description;
}

void EBProfile::setDestinationDir(const QString &dir)
{
    this->mDistanationDirectory = dir;
}

void EBProfile::setProfileLastSourceDir(const QString &dir)
{
    this->mLastSourceDirectory = dir;
}

void EBProfile::setActive(bool active) {
    this->mIsActive = active;
}

void EBProfile::setFiles(QList<QString> list) {
    this->mFilesToCopy.clear();
    this->mFilesToCopy = list;
}

void EBProfile::addFile(const QString &file) {
    this->mFilesToCopy.append(file);
}


void EBProfile::removeFileAtIndex(const int index)
{
    if(!this->mFilesToCopy.at(index).isNull())
        this->mFilesToCopy.removeAt(index);
}

void EBProfile::removeAllFiles()
{
    this->mFilesToCopy.clear();
}

void EBProfile::setUniqueId(int id)
{
    this->mUniqueId = id;
}

void EBProfile::setIntervalType(int type)
{
    this->mIntervalType = type;
}

void EBProfile::setIntervalValue(int value)
{
    this->mIntervalValue = value;
}

void EBProfile::setInternId(int id)
{
    this->mInternalId = id;
}
