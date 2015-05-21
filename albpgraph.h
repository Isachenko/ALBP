#ifndef ALBPGRAPH_H
#define ALBPGRAPH_H

#include <QList>
#include <QMap>
#include <QVector>

#include "albptask.h"

class ALBPGraph
{
private:
    QVector<ALBPTask*> _tasks;
    QMap<ALBPTask*, QList<ALBPTask*> > _taskPredcessors;
    QMap<ALBPTask*, QList<ALBPTask*> > _taskSuccessors;

public:
    ALBPGraph();
    ~ALBPGraph();

    int getTaskCount();


};

#endif // ALBPGRAPH_H
