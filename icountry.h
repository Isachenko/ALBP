#ifndef ICOUNTRY_H
#define ICOUNTRY_H

#include <QString>

class ICountry
{
public:
    ICountry();
    ~ICountry();

    virtual double getFitnessValue() = 0;
    virtual void makeSimilarTo(ICountry *country) = 0;
};

#endif // ICOUNTRY_H
