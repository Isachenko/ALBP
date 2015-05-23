#include <iostream>

#include "albpicalgorithm.h"
#include "albpgraph.h"

int main()
{
    std::cout << "Start" << std::endl;

    ALBPGraph* graph = new ALBPGraph();
    graph->readFromFile("problem.txt");
    IICAlgorithm* alogorithm = new ALBPICAlgorithm(1000, graph);
    alogorithm->run();
    ALBPCountry* best = (ALBPCountry*) alogorithm->getBest();
    std::cout << best->toString().toStdString();

    return 0;
}
