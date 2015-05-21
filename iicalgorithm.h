#ifndef IECALGORITHM_H
#define IECALGORITHM_H

#include <QVector>

#include "icountry.h"
#include "iempire.h"

class IICAlgorithm
{
protected:
    const int _COUNTRIES_COUNT = 0;

    QList<IEmpire*> _empires;
    int curIteration = 0;


public:
    IICAlgorithm(int coloniesCount);
    ~IICAlgorithm();

    void run();

    virtual void initColonies() = 0;
    virtual bool stopCondition() = 0;
    virtual void imperialisticCompetition() = 0;
    virtual void startRevolutions() = 0;
    virtual void colapsAndFindNewOwner(IEmpire* ) = 0;
    virtual ICountry* getBest() = 0;

};

#endif // IECALGORITHM_H
