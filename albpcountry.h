#ifndef ALBPCOUNTRY_H
#define ALBPCOUNTRY_H

#include <QVector>
#include <functional>
#include <QString>

#include "icountry.h"

class ALBPCountry : ICountry
{
private:

public:
    ALBPCountry();
    ~ALBPCountry();

    static ICountry* createRandom();
    virtual double getFitnessValue();
    virtual void makeSimilarTo(ICountry *country);

    QString toString();


};

#endif // ALBPCOUNTRY_H
