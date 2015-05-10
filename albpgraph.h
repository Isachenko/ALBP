#ifndef ALBPGRAPH_H
#define ALBPGRAPH_H

#include <QList>
#include <QMap>

#include "albptask.h"

class ALBPGraph
{
private:
    QList<ALBPTask*> _tasks;
    QMap<ALBPTask*, QList<ALBPTask*> > _taskPredcessors;
    QMap<ALBPTask*, QList<ALBPTask*> > _taskSuccessors;

public:
    ALBPGraph();
    ~ALBPGraph();
};

#endif // ALBPGRAPH_H
