#ifndef ICOLONY_H
#define ICOLONY_H

#include <icountry.h>
#include <QList>

class IEmpire
{
private:
    ICountry *emperialist;
    QList<ICountry*> colonies;

public:
    IEmpire();
    ~IEmpire();

    ICountry *getEmperialist() const;
    void setEmperialist(ICountry *value);

    QList<ICountry *> getColonies() const;
    void setColonies(const QList<ICountry *> &value);

    virtual void revolution() = 0;
    virtual double getFitnessValue() = 0;
    virtual void chooseNewEmperialist() = 0;
    virtual bool colapsCondition() = 0;
};

#endif // ICOLONY_H
