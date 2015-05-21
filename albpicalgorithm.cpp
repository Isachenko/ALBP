#include "albpicalgorithm.h"
#include <cstdlib>
#include <QMap>

#define EMPIRES_COUNT 10

ALBPICAlgorithm::ALBPICAlgorithm(int coloniesCount, ALBPGraph *graph) :
    IICAlgorithm(coloniesCount),
    _graph(graph)
{
    ALBPCountry::setGraph(graph);
}

ALBPICAlgorithm::~ALBPICAlgorithm()
{

}

void ALBPICAlgorithm::initColonies()
{
    QMap<ICountry*, double> countriesAndFitness;
    for(int i = 0; i < _COUNTRIES_COUNT; ++i) {
        ICountry* country = ALBPCountry::createRandom();
        countriesAndFitness.insert(country, country->getFitnessValue());
    }
    QMap<ICountry*, double>::iterator cf;

    //need to be optimized
    QMap<ICountry*, double> emperialistsAndFitness;
    int totlaEmpiraliststFitness = 0;
    for(int i = 0; i < EMPIRES_COUNT; ++i) {
        double bestFitness = -1;
        ICountry* bestCountry = nullptr;
        for (cf = countriesAndFitness.begin(); cf != countriesAndFitness.end(); ++cf) {
            if (cf.value() > bestFitness) {
                bestFitness = cf.value();
                bestCountry = cf.key();
            }
        }
        if (bestCountry) {
            countriesAndFitness.remove(bestCountry);
            emperialistsAndFitness.insert(bestCountry, bestFitness);
            totlaEmpiraliststFitness += bestFitness;
        }
    }
    QMap<ICountry*, double>::iterator ef = countriesAndFitness.begin();
    for (ef = emperialistsAndFitness.begin(); ef != emperialistsAndFitness.end(); ++ef) {
        int coloniesCount = qRound((double)countriesAndFitness.size() * ((double)ef.value() / (double)totlaEmpiraliststFitness));
        QList<ICountry*> colonies;
        for(int i = 0; i < coloniesCount; ++i) {
            colonies.append(countriesAndFitness.firstKey());
            countriesAndFitness.remove(countriesAndFitness.firstKey());
        }
        if ((ef + 1) == emperialistsAndFitness.end()) {
            colonies.append(countriesAndFitness.keys());
        }
        _empires.append(new ALBPEmpire(ef.key(), colonies));
    }



}

bool ALBPICAlgorithm::stopCondition()
{
    if (_empires.size() < 2) {
        return true;
    } else if (curIteration >= MAX_ITERATION_COUNT){
        return true;
    }
    return false;
}

void ALBPICAlgorithm::imperialisticCompetition()
{
    IEmpire* loser = nullptr;
    QMap<IEmpire*, double> fitnessValues;

    double maxValue = -1;
    //count fitness and find loser
    foreach (IEmpire* epmire, _empires) {
        double value = epmire->getFitnessValue();
        fitnessValues.insert(epmire, value);
        if (value > maxValue) {
            maxValue = value;
        }
        if ((loser == nullptr) || (fitnessValues.contains(loser) && (value < fitnessValues.value(loser)))) {
            loser = epmire;
        }
    }
    //normalize
    QMap<IEmpire*, double>::iterator i;
    for(i = fitnessValues.begin(); i != fitnessValues.end(); ++i) {
        fitnessValues.insert(i.key(), i.value() / maxValue);
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
    //colaps
    _empires.removeOne(empire);
    QList<ICountry*> vocantCountries = empire->getColonies();
    vocantCountries.append(empire->getEmperialist());
    delete empire;

    //find new owner
    QMap<IEmpire*, double> empiresAndFitness;
    double totalEmperiesFitness = 0;
    foreach(IEmpire* empire, _empires) {
        double fitness = empire->getFitnessValue();
        empiresAndFitness.insert(empire, fitness);
        totalEmperiesFitness += fitness;
    }

    QMap<IEmpire*, double>::iterator ef;
    for(ef = empiresAndFitness.begin(); ef != empiresAndFitness.end(); ++ef) {
        double fitness = ef.key()->getFitnessValue();
        int coloniesCount = qRound((double)vocantCountries.size() * ((double)fitness / (double)totalEmperiesFitness));
        QList<ICountry*> colonies;
        for(int i = 0; i < coloniesCount; ++i) {
            colonies.append(vocantCountries.first());
            vocantCountries.removeFirst();
        }
        if ((ef + 1) == empiresAndFitness.end()) {
            colonies.append(vocantCountries);
        }
        ef.key()->addNewCountry(colonies);
    }


}

ICountry *ALBPICAlgorithm::getBest()
{
    _empires.first()->chooseNewEmperialist();
    return _empires.first()->getEmperialist();
}

