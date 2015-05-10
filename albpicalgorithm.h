#ifndef ALBPICALGORITHM_H
#define ALBPICALGORITHM_H

#include "iicalgorithm.h"
#include "albpempire.h"
#include "albpcountry.h"

class ALBPICAlgorithm : public IICAlgorithm
{
private:
    double REVOLUTION_RATE = 0.3;

public:
    ALBPICAlgorithm(int coloniesCount);
    ~ALBPICAlgorithm();    


    virtual void initColonies();
    virtual bool stopCondition();
    virtual void imperialisticCompetition();
    virtual void startRevolutions();
    virtual void colapsAndFindNewOwner(IEmpire* empire);
    virtual ICountry* getBest();
};

#endif // ALBPICALGORITHM_H
