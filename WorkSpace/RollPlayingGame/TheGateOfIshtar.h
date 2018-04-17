#ifndef THEGATEOFISHTAR_H
#define THEGATEOFISHTAR_H
#include <QDateTime>
#include <QList>
#include "Champion.h"

class TheGateOfIshtar
{
public:
    TheGateOfIshtar();
    double calculateChampionHealth(Champion *champion, const QList<QDateTime *> *dateStringIntervals);

private:
    double calculateDamageTaken(QDateTime * currentDate);
    bool hollyDay(QDateTime * currentDate);
    QString guardName;
};

#endif // THEGATEOFISHTAR_H
