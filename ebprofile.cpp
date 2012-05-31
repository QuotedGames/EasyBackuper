#include "ebprofile.h"

EBProfile::EBProfile(QObject *parent) :
    QObject(parent)
{
    this->mIsActive             = false;
    this->mProfileName          = "";
    this->mProfileDescription   = "";
    this->mFilesToCopy          = QList<QString>();
    this->mDistanationDirectory = "";
    this->mLastSourceDirectory  = "";

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

QList<QString> EBProfile::profileFiles()
{
    return this->mFilesToCopy;
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

