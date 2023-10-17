#include "stopwatch.h"
#include <QDebug>

Stopwatch::Stopwatch(QObject* parent) : QObject(parent)
{
myTime = new QTimer(this);
}
Stopwatch::~Stopwatch(){
    qDebug() << "Stopwatch clear";
}

void Stopwatch::StartTime(){
myTime->start(100);
started = true;
}
void Stopwatch::StopTime(){
myTime->stop();
started = false;
}

void Stopwatch::Clear()
{
    ms = 0;
    s = 0;
    m = 0;
    circle_ms = 0;
    circle_s = 0;
    circle_m = 0;
    circle_num = 0;
    emit sig_SendClearSignal();
}

void Stopwatch::NextCircle()
{
    emit sig_SendCircleSignal();
    circle_num++;
    circle_ms = 0;
    circle_s = 0;
    circle_m = 0;
}


bool Stopwatch::get_start(){
    return started;
}

QString Stopwatch::TimeSlot()
{
    circle_ms++;
    if(circle_ms>=10){
        circle_ms = 0;
        circle_s++;
    }
    if(circle_s >= 60){
        circle_s = 0;
        circle_m++;
    }
    if(m!=0){
        circle_time = QString::number(circle_m) + " : " + QString::number(circle_s) + "." + QString::number(circle_ms);
    }else{
        circle_time = QString::number(circle_s) + "." + QString::number(circle_ms);
    }
ms++;
if(ms>=10){
    ms = 0;
    s++;
}
if(s >= 60){
    s = 0;
    m++;
}
return QString::number(m) + " : " + QString::number(s) + " . " + QString::number(ms);
}
