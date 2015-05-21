#include "albpempire.h"

ALBPEmpire::ALBPEmpire() :
    IEmpire()
{

}


ALBPEmpire::ALBPEmpire(ICountry* emperialist, QList<ICountry*> colonies) :
    IEmpire(emperialist, colonies)
{
}

void ALBPEmpire::revolution()
{
    ICountry* wortsCountry = popWorstCountry();
    delete wortsCountry;
    _colonies.append(ALBPCountry::createRandom());
}

double ALBPEmpire::getFitnessValue()
{
    //stub
    double fitnessValue;
    foreach(ICountry* colony, _colonies) {
        fitnessValue += colony->getFitnessValue();
    }
    fitnessValue /= _colonies.size();
    fitnessValue += _emperialist->getFitnessValue();
    return fitnessValue;
}

void ALBPEmpire::chooseNewEmperialist()
{
    //need to be optimized
    double bestFitness = -1;
    ICountry* bestColony = nullptr;
    foreach (ICountry* colony, _colonies) {
        double fitness = colony->getFitnessValue();
        if (fitness > bestFitness) {
            bestColony = colony;
            bestFitness = fitness;
        }
    }

    if (bestColony && (bestFitness > _emperialist->getFitnessValue())) {
        _colonies.removeOne(bestColony);
        _colonies.append(_emperialist);
        _emperialist = bestColony;
    }
}

bool ALBPEmpire::colapsCondition()
{
    //stub
    if (_colonies.size() < 2) {
        return true;
    }
    return false;
}

ICountry* ALBPEmpire::popWorstCountry()
{
    //neet to be optimized
    double worstFitness = 999999;
    ICountry* worstColony = nullptr;
    foreach (ICountry* colony, _colonies) {
        double fitness = colony->getFitnessValue();
        if (fitness < worstFitness) {
            worstColony = colony;
            worstFitness =  fitness;
        }
    }

    if (worstColony) {
        _colonies.removeOne(worstColony);
    }
    return worstColony;
}

