#include "iicalgorithm.h"

IICAlgorithm::IICAlgorithm(int coloniesCount) :
    _COUNTRIES_COUNT(coloniesCount)
{

}

IICAlgorithm::~IICAlgorithm()
{

}

void IICAlgorithm::run()
{
    initColonies();
    while (!stopCondition()) {
        foreach (IEmpire* empire, _empires) {
            empire->startAssimilation();
        }
        startRevolutions();
        foreach (IEmpire* empire, _empires) {
            empire->chooseNewEmperialist();
        }
        imperialisticCompetition();
        foreach (IEmpire* empire, _empires) {
            if (empire->colapsCondition()) {
                colapsAndFindNewOwner(empire);
            }
        }
        ++curIteration;
    }

}

