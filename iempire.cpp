#include "iempire.h"


ICountry *IEmpire::getEmperialist() const
{
    return emperialist;
}

void IEmpire::setEmperialist(ICountry *value)
{
    emperialist = value;
}

QList<ICountry *> IEmpire::getColonies() const
{
    return colonies;
}

void IEmpire::setColonies(const QList<ICountry *> &value)
{
    colonies = value;
}

void IEmpire::revolution()
{

}

double IEmpire::getFitnessValue()
{

}

void IEmpire::chooseNewEmperialist()
{

}

IEmpire::IEmpire()
{

}

IEmpire::~IEmpire()
{

}

