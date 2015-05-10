#include <iostream>

#include "albpicalgorithm.h"

int main()
{
    std::cout << "Start" << std::endl;

    IICAlgorithm* alogorithm = new ALBPICAlgorithm(1000);
    alogorithm->run();
    ALBPCountry* best = (ALBPCountry*) alogorithm->getBest();
    std::cout << best->toString().toStdString();

    return 0;
}
