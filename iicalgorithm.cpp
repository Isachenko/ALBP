#include "iicalgorithm.h"

IICAlgorithm::IICAlgorithm()
{

}

IICAlgorithm::~IICAlgorithm()
{

}

void IICAlgorithm::run()
{
    initColonies();
    while (!stopCondition()) {
        startAssimilation();
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
    }

}

