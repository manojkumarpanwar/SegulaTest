#include "Champion.h"
#include <QDebug>


Champion::Champion(const QString name)
{
    this->name = name;
    this->assignHealth();
}

/**
 * @brief Champion::assignHealth
 */
void Champion::assignHealth()
{
    this->health = 0;
    if (!(QString::compare(this->name, "Human" , Qt::CaseInsensitive)) || !(QString::compare(this->name, "Spirit" , Qt::CaseInsensitive)) || !(QString::compare(this->name, "Wizard" , Qt::CaseInsensitive))){
        this->health = 100;
    }else {
        if (!QString::compare(this->name, "Vampire" , Qt::CaseInsensitive)){
            this->health = 110;
        }else {
            if (!QString::compare(this->name, "Giant" , Qt::CaseInsensitive)){
                this->health = 150;
            }else{
                qDebug()<<"******************************************";
                qDebug()<<"**** Error: No such champion exist :( ****";
                qDebug()<<"******************************************";
            }//end if
        }//end if
    }//end if
}

/**
 * @brief Champion::isInvincibleChampion
 * @return
 */
bool Champion::isInvincibleChampion()
{
    if (!(QString::compare(this->name, "Spirit" , Qt::CaseInsensitive)) || !(QString::compare(this->name, "Wizard" , Qt::CaseInsensitive))){
        qDebug()<<"***************************************************";
        qDebug()<<"**** The Champion is  Invincible "<<this->name<<" ****";
        qDebug()<<"***************************************************";
        return true;
    }
    return false;
}


QString Champion::getName() const
{
    return name;
}

void Champion::setName(const QString &value)
{
    name = value;
}

double Champion::getHealth() const
{
    return health;
}

void Champion::setHealth(double value)
{
    health = value;
}



