#ifndef ALBPICALGORITHM_H
#define ALBPICALGORITHM_H

#include "iicalgorithm.h"
#include "albpempire.h"
#include "albpcountry.h"
#include "albpgraph.h"

class ALBPICAlgorithm : public IICAlgorithm
{
private:
    double REVOLUTION_RATE = 0.3;
    ALBPGraph* _graph;
    int MAX_ITERATION_COUNT = 50;

public:
    ALBPICAlgorithm(int coloniesCount, ALBPGraph* graph);
    ~ALBPICAlgorithm();    


    virtual void initColonies();
    virtual bool stopCondition();
    virtual void imperialisticCompetition();
    virtual void startRevolutions();
    virtual void colapsAndFindNewOwner(IEmpire* empire);
    virtual ICountry* getBest();
};

#endif // ALBPICALGORITHM_H
