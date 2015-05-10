#include "albpicalgorithm.h"
#include <cstdlib>
#include <QMap>

ALBPICAlgorithm::ALBPICAlgorithm(int coloniesCount) :
    IICAlgorithm(coloniesCount)
{

}

ALBPICAlgorithm::~ALBPICAlgorithm()
{

}

void ALBPICAlgorithm::initColonies()
{
    QMap<ICountry*, double> _countriesAndFitness;
    for(int i = 0; i < _COLONIES_COUNT; ++i) {
        ICountry* country = ALBPCountry::createRandom();
        _countriesAndFitness.insert(country, country->getFitnessValue());
    }
    //ToDO:: I'm here

}

bool ALBPICAlgorithm::stopCondition()
{
    if (_empires.size() < 2) {
        return true;
    } else {
        return false;
    }
}

void ALBPICAlgorithm::imperialisticCompetition()
{
    IEmpire* loser = nullptr;
    QMap<IEmpire*, int> fitnessValues;

    double maxValue = -1;
    //count fitness and find loser
    foreach (IEmpire* epmire, _empires) {
        double value = epmire->getFitnessValue();
        fitnessValues.insert(epmire, value);
        if (value > maxValue) {
            maxValue = value;
        }
        if (fitnessValues.contains(loser) && (value < fitnessValues.value(loser))) {
            loser = epmire;
        }
    }

    //find winner
    IEmpire* winner = nullptr;
    double maxMagic = -1;
    foreach (IEmpire* empire, _empires) {
        double magic = fitnessValues.value(empire) * std::rand();
        if (magic > maxMagic) {
            maxMagic = magic;
            winner = empire;
        }
    }

    ICountry* worstCountry = loser->popWorstCountry();
    winner->addNewCountry(worstCountry);
}

void ALBPICAlgorithm::startRevolutions()
{
    double p = (double)std::rand() / (double)RAND_MAX;
    if (p < REVOLUTION_RATE) {
        int empireIndex = std::rand() % _empires.size();
        _empires.at(empireIndex)->revolution();
    }
}

void ALBPICAlgorithm::colapsAndFindNewOwner(IEmpire *empire)
{
    _empires.removeOne(empire);
    QList<ICountry*> _countries = empire->getColonies();
    _countries.append(empire->getEmperialist());
}

ICountry *ALBPICAlgorithm::getBest()
{
    _empires.first()->chooseNewEmperialist();
    return _empires.first()->getEmperialist();
}

