#ifndef IECALGORITHM_H
#define IECALGORITHM_H

#include <QVector>

#include "icountry.h"
#include "iempire.h"

class IICAlgorithm
{
private:

    QList<IEmpire*> _empires;


public:
    IICAlgorithm();
    ~IICAlgorithm();

    void run();

    virtual void initColonies() = 0;
    virtual void startAssimilation() = 0;
    virtual bool stopCondition() = 0;
    virtual void imperialisticCompetition() = 0;
    virtual void startRevolutions() = 0;
    virtual void colapsAndFindNewOwner(IEmpire* ) = 0;

};

#endif // IECALGORITHM_H
