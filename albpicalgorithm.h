#ifndef ALBPICALGORITHM_H
#define ALBPICALGORITHM_H

#include "iicalgorithm.h"

class ALBPICAlgorithm : public IICAlgorithm
{
public:
    ALBPICAlgorithm();
    ~ALBPICAlgorithm();    


    virtual void initColonies();
    virtual void startAssimilation();
    virtual bool stopCondition();
    virtual void imperialisticCompetition();
    virtual void startRevolutions();
    virtual void colapsAndFindNewOwner(IEmpire* );
    virtual ICountry* getBest();
};

#endif // ALBPICALGORITHM_H
