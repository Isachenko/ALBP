#include <iostream>

#include "albpicalgorithm.h"

int main()
{
    std::cout << "Start" << std::endl;

    IICAlgorithm* alogorithm = new ALBPICAlgorithm();
    alogorithm->run();


    return 0;
}
