#ifndef ALBPTASK_H
#define ALBPTASK_H


class ALBPTask
{
    double _time;
    bool _isComplite;

public:
    ALBPTask(double time);
    ~ALBPTask();
    bool isComplite() const;
    void setIsComplite(bool isComplite);
};

#endif // ALBPTASK_H
