#ifndef ICOLONY_H
#define ICOLONY_H

#include <icountry.h>
#include <QList>

class IEmpire
{
protected:
    ICountry *_emperialist;
    QList<ICountry*> _colonies;

public:
    IEmpire();
    IEmpire(ICountry *emperialist, QList<ICountry*> colonies);
    ~IEmpire();

    ICountry *getEmperialist() const;
    void setEmperialist(ICountry *value);

    QList<ICountry *> getColonies() const;
    void setColonies(const QList<ICountry *> &value);

    virtual void revolution() = 0;
    virtual double getFitnessValue() = 0;
    virtual void chooseNewEmperialist() = 0;
    virtual bool colapsCondition() = 0;
    virtual ICountry* popWorstCountry() = 0;
    virtual void addNewCountry(ICountry* c);
    virtual void addNewCountry(QList<ICountry*> c);
    virtual void startAssimilation();
};

#endif // ICOLONY_H
