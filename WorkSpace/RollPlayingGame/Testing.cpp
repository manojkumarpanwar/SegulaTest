#include "Testing.h"
#include <QDateTime>
#include <QtCore>
#include <QRandomGenerator>

Testing::Testing()
{
    dateTimeList = new QList<QDateTime *>;
    this->newChampion = NULL;
}

/**
 * @brief Testing::createDateTimeList
 * @return
 */
QList<QDateTime *> *Testing::createDateTimeList()
{
    QDateTime nextDateTime;
    QDateTime *tempDateTime = new QDateTime(QDateTime::currentDateTime().addSecs(getRandomNo(0,3600)));
    QMap<QDateTime, QDateTime *> *dateTimeMap = new QMap<QDateTime, QDateTime *>(); //No duplicate entry and date time in increasing order

    qint64 timeToadd = 0;
    nextDateTime = *tempDateTime;

    for (int count = 0; count < 12; ) {
       // qDebug()<< tempDateTime->toString()<<timeToadd;
        dateTimeMap->insert(*tempDateTime, tempDateTime);
        timeToadd = getRandomNo(1,7199); //Form 1 sec till less than 2 hours
        tempDateTime = new QDateTime(nextDateTime.addSecs(timeToadd));
        tempDateTime->addSecs(timeToadd);
        if(timeToadd >= 3600){//Make sure at least one time is greater then equal to 1 hour
            count++;
            nextDateTime = *tempDateTime;
        }//end if
    }//end for

    if (!dateTimeList->isEmpty())
        deallocateNewMemory(dateTimeList);

    QMap<QDateTime, QDateTime *>::const_iterator i;
    for (i = dateTimeMap->constBegin(); i != dateTimeMap->constEnd(); ++i){
        dateTimeList->push_back(i.value());
    }
    dateTimeMap->clear();

    return dateTimeList;
}

/**
 * @brief Testing::getRandomNo
 * @param low
 * @param high
 * @return
 */
quint64 Testing::getRandomNo(int low, int high)
{
    QRandomGenerator randomGenrator; //This class is new in Qt 5.10
    return randomGenrator.global()->bounded(low, high+1);
}//end getRandomNo


/**
 * @brief Testing::createNewChampion
 * @return
 */
Champion *Testing::createNewChampion(){

    if (this->newChampion != NULL) {
        delete this->newChampion;
    }
    this->newChampion = NULL;

    switch (getRandomNo(0,4)) {
    case 0:
        this->newChampion = new Champion("Human");
        break;
    case 1:
        this->newChampion = new Champion("Wizard");
        break;
    case 2:
        this->newChampion = new Champion("Spirit");
        break;
    case 3:
        this->newChampion = new Champion("Giant");
        break;
    case 4:
        this->newChampion = new Champion("Vampire");
    }//end switch

    qDebug()<<"The champiobn is "<<newChampion->getName()<<"HP"<<newChampion->getHealth();

    return this->newChampion;
}//end createNewChampion



/**
 * @brief Testing::deallocateNewMemory
 * @param dateTimeList
 * @return
 */
int Testing::deallocateNewMemory(QList<QDateTime *> *dateTimeList)
{

    QMutableListIterator<QDateTime *> i(*dateTimeList);
    QDateTime *tempDateTime;
    while (i.hasNext()){
        i.next();
        tempDateTime = i.value();
        delete tempDateTime;
        tempDateTime = NULL;
        i.remove();
    }//end while
    dateTimeList = NULL;
    return 0;
}
