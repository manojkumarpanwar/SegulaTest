#include "TheGateOfIshtar.h"
#include <QtCore>

TheGateOfIshtar::TheGateOfIshtar()
{

}

/**
 * @brief TheGateOfIshtar::calculateChampionHealth
 * @param champion
 * @param dateStringIntervals
 * @return
 */
double TheGateOfIshtar::calculateChampionHealth(Champion *champion, const QList<QDateTime *> *dateStringIntervals)
{
    double totalDamage = 0, interval = 0, nextDamage = 0;
    QDateTime *previousDate, *tempDate;
    QList<QDateTime *>::const_iterator i = dateStringIntervals->constBegin();
    previousDate = *i;
    int count =1;

    if (!champion->isInvincibleChampion()){
        qDebug()<< "S. No"<<" & "<<" Time "<<" & "<<"Guard"<<" & "<<" Interval "<<" & "<< " Damage "<<" & "<<"Cumulative Damage";
        while (i != dateStringIntervals->constEnd()){
            tempDate = (*i);
            nextDamage = this->calculateDamageTaken(tempDate);
            interval = (previousDate->secsTo(*tempDate));
            if (interval >= 3600 || i == dateStringIntervals->begin()) {
                totalDamage += nextDamage; //lose HP once every hour assumption
                previousDate = tempDate;
            }//end if
            qDebug()<<count++<<" & "<< (*i)->toString()<<" & "<<this->guardName<<" & "<<interval<<" & "<< ((interval >= 3600 ||  i == dateStringIntervals->begin())? (QString::number(-1*nextDamage)):"0")<<" & "<<totalDamage<<"\\\\ \\hline";
            if (totalDamage >= champion->getHealth()) {
                qDebug()<<"*************************************************************************";
                qDebug()<<"** The Champion "<<champion->getName()<<" died after bravely taking damage "<<totalDamage<<" **";
                qDebug()<<"*************************************************************************";
                break;//Champion is dead
            }
            ++i;
        }//end for
    }//end if

    return totalDamage;
}


/**
 * @brief TheGateOfIshtar::calculateDamageTaken
 * @param currentDate
 * @param champion
 * @return
 */
double TheGateOfIshtar::calculateDamageTaken(QDateTime *currentDate)
{
    if (this->hollyDay(currentDate)){
        guardName = "Hollyday";
        return 0;
    }//end if

    //Janna" demon of Wind spawned
    if (currentDate->time().hour() == 6 && currentDate->time().minute() >= 0 && currentDate->time().minute() <= 29){
        guardName = "Janna";
        return 7;
        //"Tiamat" goddess of Oceans spawned
    }else if(currentDate->time().hour() == 6 && currentDate->time().minute() >= 30 && currentDate->time().minute() <= 59){
        guardName = "Tiamat";
        return 18;
        //"Mithra" goddess of sun spawned
    }else if(currentDate->time().hour() == 7 && currentDate->time().minute() >= 0 && currentDate->time().minute() <= 59){
        guardName = "Mithra";
        return 25;
        //"Warwick" God of war spawned
    }else if(currentDate->time().hour() == 8 && currentDate->time().minute() >= 0 && currentDate->time().minute() <= 29){
        guardName = "Warwick";
        return 18;
        //"Kalista" demon of agony spawned
    }else if((currentDate->time().hour() >= 8 && currentDate->time().minute() >= 0 && currentDate->time().hour() <= 14  && currentDate->time().minute() <= 59)){
        guardName = "Kalista";
        return 7;
        //"Ahri" goddess of wisdom spawned
    }else if(currentDate->time().hour() == 15 && currentDate->time().minute() >= 0 && currentDate->time().minute() <= 29){
        guardName = "Ahri";
        return 13;
        // "Brand" god of fire spawned
    }else if((currentDate->time().hour() == 15 && currentDate->time().minute() <= 59) || (currentDate->time().hour() == 16 && currentDate->time().minute() >= 0 && currentDate->time().minute() <= 59)){
        guardName = "Brand";
        return 25;
        //"Rumble" god of lightning spawned
    }else if(currentDate->time().hour() == 17 && currentDate->time().minute() >= 0 && currentDate->time().minute() <= 59){
        guardName = "Rumble";
        return 18;
        //"Skarner" the scorpion demon spawned
    }else if(currentDate->time().hour() >= 18 && currentDate->time().hour() <= 19 && currentDate->time().minute() >= 0 && currentDate->time().minute() <= 59){
        guardName = "Skarner";
        return 7;
        //"Luna" The goddess of the moon spawned
    }else if(currentDate->time().hour() == 20 && currentDate->time().minute() <=59){
        guardName = "Luna";
        return 13;
    }else{
        guardName = "No Guard";
        return 12; //Average Damage for hourly damage ()
    }
}//end calculateDamageTaken


/**
 * @brief TheGateOfIshtar::hollyDay
 * @param currentDate
 * @return
 */
bool TheGateOfIshtar::hollyDay(QDateTime *currentDate)
{
    enum Day { Monday = 1, Tuesday, Wednesday, Thrusday, Friday, Saturday, Sunday };
    if ((currentDate->date().dayOfWeek() == Monday) || (currentDate->date().dayOfWeek() == Thrusday))//Holly (Tuesday or Thuresday)
        return true;

    return false;
}//end hollyDay




