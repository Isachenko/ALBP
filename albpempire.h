#ifndef ALBPEMPIRE_H
#define ALBPEMPIRE_H

#include "iempire.h"

class ALBPEmpire : IEmpire
{
private:


public:
    ALBPEmpire();
    ~ALBPEmpire();

    virtual void revolution();
    virtual double getFitnessValue();
    virtual void chooseNewEmperialist();
    virtual bool colapsCondition();
    virtual ICountry* popWorstCountry();
};

#endif // ALBPEMPIRE_H
