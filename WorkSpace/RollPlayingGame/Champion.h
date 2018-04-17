#ifndef CHAMPION_H
#define CHAMPION_H
#include <QString>

class Champion
{
public:
    Champion(const QString name);

    QString getName() const;
    void setName(const QString &value);
    double getHealth() const;
    void setHealth(double value); 
    bool isInvincibleChampion();

private:
    QString name;
    double health;
    void assignHealth();
};

#endif // CHAMPION_H
