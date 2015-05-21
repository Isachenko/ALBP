#ifndef ALBPEMPIRE_H
#define ALBPEMPIRE_H

#include "iempire.h"
#include "albpcountry.h"

class ALBPEmpire : public IEmpire
{
private:


public:
    ALBPEmpire();
    ALBPEmpire(ICountry *emperialist, QList<ICountry *> colonies);
    ~ALBPEmpire();

    virtual void revolution();
    virtual double getFitnessValue();
    virtual void chooseNewEmperialist();
    virtual bool colapsCondition();
    virtual ICountry* popWorstCountry();
};

#endif // ALBPEMPIRE_H
