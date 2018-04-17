#include <QApplication>


#include "Champion.h"
#include "TheGateOfIshtar.h"
#include "Testing.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    static TheGateOfIshtar *theGateOfIshtar = new TheGateOfIshtar;

    int i=0;
    Testing testing;
    while (i++<=2) {
    theGateOfIshtar->calculateChampionHealth(testing.createNewChampion(), testing.createDateTimeList());
    }
    return a.exec();
}//end Main
