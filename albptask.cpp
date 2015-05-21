#include "albptask.h"


bool ALBPTask::isComplite() const
{
    return _isComplite;
}

void ALBPTask::setIsComplite(bool isComplite)
{
    _isComplite = isComplite;
}
ALBPTask::ALBPTask(double time) :
    _time(time)
{

}

ALBPTask::~ALBPTask()
{

}


