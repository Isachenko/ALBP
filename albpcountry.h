#ifndef ALBPCOUNTRY_H
#define ALBPCOUNTRY_H

#include <QVector>
#include <functional>
#include <QString>

#include "icountry.h"
#include "albpgraph.h"

class ALBPCountry : public ICountry
{
private:
    static ALBPGraph* _graph;
    static const int _maxRuleValue = 10;

    QVector<int> _rules;


public:
    ALBPCountry();
    ~ALBPCountry();

    static ICountry* createRandom();
    virtual double getFitnessValue();
    virtual void makeSimilarTo(ICountry *country);
    QString toString();

    static ALBPGraph *graph() { return _graph; }
    static void setGraph(ALBPGraph *graph) { _graph = graph; }
};

#endif // ALBPCOUNTRY_H
