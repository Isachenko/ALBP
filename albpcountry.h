#ifndef ALBPCOUNTRY_H
#define ALBPCOUNTRY_H

#include <QVector>
#include <functional>

#include "icountry.h"

class ALBPCountry : ICountry
{
private:
    QVector<int> _;


    std::function<void (CodesTreeNode*)> bypass

public:
    ALBPCountry();
    ~ALBPCountry();

    virtual double getFitnessValue();
    virtual void makeSimilarTo(ICountry *country);


};

#endif // ALBPCOUNTRY_H
