#include "iempire.h"


ICountry *IEmpire::getEmperialist() const
{
    return _emperialist;
}

void IEmpire::setEmperialist(ICountry *value)
{
    _emperialist = value;
}

QList<ICountry *> IEmpire::getColonies() const
{
    return _colonies;
}

void IEmpire::setColonies(const QList<ICountry *> &value)
{
    _colonies = value;
}

void IEmpire::addNewCountry(ICountry *c)
{
    _colonies.append(c);
}

void IEmpire::addNewCountry(QList<ICountry *> c)
{
    _colonies.append(c);
}

void IEmpire::startAssimilation()
{
    foreach(ICountry* colony, _colonies) {
        colony->makeSimilarTo(_emperialist);
    }
}

IEmpire::IEmpire()
{

}

IEmpire::IEmpire(ICountry *emperialist, QList<ICountry *> colonies) :
    _emperialist(emperialist),
    _colonies(colonies)
{

}

IEmpire::~IEmpire()
{

}

