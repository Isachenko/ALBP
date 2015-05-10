#ifndef ALBPEMPIRE_H
#define ALBPEMPIRE_H

#include "iempire.h"

class ALBPEmpire : IEmpire
{
public:
    ALBPEmpire();
    ~ALBPEmpire();

    virtual void revolution();
    virtual double getFitnessValue();
    virtual void chooseNewEmperialist();
    virtual bool colapsCondition();
};

#endif // ALBPEMPIRE_H
