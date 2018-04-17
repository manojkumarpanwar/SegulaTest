#ifndef TESTING_H
#define TESTING_H
#include <QList>
#include "Champion.h"


class Testing
{
public:
    Testing();
    QList<QDateTime *> *createDateTimeList();
    Champion *createNewChampion();

private:
    Champion *newChampion;
    quint64 getRandomNo(int low, int high);
    QList<QDateTime *> *dateTimeList;
    int deallocateNewMemory(QList<QDateTime *> *dateTimeList);
};

#endif // TESTING_H
