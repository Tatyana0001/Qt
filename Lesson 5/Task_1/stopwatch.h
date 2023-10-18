#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QString>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject* parent = nullptr);
    QTimer *myTime = nullptr;
    int circle_num = 1;
    QString circle_time;
    bool started = false;
    bool get_start();
    ~Stopwatch();
    void StartTime();
    void StopTime();
    void Clear();
    void NextCircle();
private:
    int ms = 0;
    int s = 0;
    int m = 0;
    int circle_ms = 0;
    int circle_s = 0;
    int circle_m = 0;

signals:
    void sig_SendClearSignal();
    void sig_SendCircleSignal();
public slots:
    QString TimeSlot();
};


#endif // STOPWATCH_H
