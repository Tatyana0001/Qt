#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_start_stop_toggled(bool checked);
    void TimerSlot();
    void StartStopTimerSlot();
    void RcvClearSig();
    void RcvClearSignal();
    void RcvCircleSignal();
    void RcvCircleSig();

private:
    Ui::MainWindow *ui;
    Stopwatch *stopwatch;
};
#endif // MAINWINDOW_H
