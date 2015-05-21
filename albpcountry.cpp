#include "albpcountry.h"

ALBPGraph* ALBPCountry::_graph = nullptr;

ALBPCountry::ALBPCountry() :
    ICountry()
{

}

ALBPCountry::~ALBPCountry()
{

}

ICountry *ALBPCountry::createRandom()
{
    ALBPCountry* albpCountry = new ALBPCountry();
    for(int i = 0; i < graph()->getTaskCount(); ++i) {
        int randomRule = qrand() % _maxRuleValue;
        albpCountry->_rules.append(randomRule);
    }
    return albpCountry;
}

double ALBPCountry::getFitnessValue()
{
    //stub
    double cost = 0;
    foreach(int rule, _rules) {
        cost += rule;
    }
    return cost;
}

void ALBPCountry::makeSimilarTo(ICountry *country)
{
    ALBPCountry* albpCountry = static_cast<ALBPCountry*>(country);
    for(int i = 0; i < _graph->getTaskCount(); ++i) {
        int magic = qrand() % 2;
        if (magic != 0) {
            this->_rules[i] = albpCountry->_rules.at(i);
        }
    }
}

QString ALBPCountry::toString()
{
    QString string("value = {");
    foreach(int rule, _rules) {
        string += QString::number(rule) + " ";
    }
    string += "} \nfitness = {";
    string += QString::number(getFitnessValue());
    string += "}\n";
    return string;
}

