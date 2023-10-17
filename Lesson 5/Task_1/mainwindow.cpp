#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stopwatch = new Stopwatch(this);
    ui->pb_start_stop->setText("Старт");
    ui->pb_start_stop->setCheckable(true);
    ui->pb_circle->setEnabled(false);
    connect(ui->pb_start_stop, &QPushButton::clicked, this, &MainWindow::StartStopTimerSlot);
    connect(ui->pb_clear, &QPushButton::clicked, this, &MainWindow::RcvClearSignal);
    connect(ui->pb_circle, &QPushButton::clicked, this, &MainWindow::RcvCircleSignal);

    connect(this->stopwatch->myTime, &QTimer::timeout, this, &MainWindow::TimerSlot);
    connect(stopwatch, &Stopwatch::sig_SendClearSignal, this, &MainWindow::RcvClearSig);
    connect(stopwatch, &Stopwatch::sig_SendCircleSignal, this, &MainWindow::RcvCircleSig);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_start_stop_toggled(bool checked)
{
    if(checked){
        ui->pb_start_stop->setText("Стоп");
        ui->pb_circle->setEnabled(true);
    }else{
        ui->pb_start_stop->setText("Старт");
        ui->pb_circle->setEnabled(false);
    }
}
void MainWindow::TimerSlot(){
    ui->lb_time->setText(stopwatch->TimeSlot());
}

void MainWindow::StartStopTimerSlot()
{
    if(!stopwatch->get_start()){
        stopwatch->StartTime();
    }else{
        stopwatch->StopTime();
    }
}

void MainWindow::RcvClearSig()
{
    ui->lb_time->setText("0 : 0 . 0");
}

void MainWindow::RcvClearSignal()
{
    stopwatch->Clear();
}

void MainWindow::RcvCircleSignal()
{
    stopwatch->NextCircle();
}

void MainWindow::RcvCircleSig()
{
    ui->te_time->setText("Круг " + QString::number(stopwatch->circle_num) + ", время: " + stopwatch->circle_time + " сек.");
}

