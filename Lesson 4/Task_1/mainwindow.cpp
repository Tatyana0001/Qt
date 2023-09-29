#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rb_one->setText("Кнопка 1");
    ui->rb_two->setText("Кнопка 2");
    ui->rb_one->setChecked(true);
    for(int i = 0; i<10; i++){
        ui->comboBox->addItem("Элемент " + QString::number(i));
    }
    ui->pb_add->setText("Добавить");
    ui->pb_add->setCheckable(true);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_add_toggled(bool checked)
{
    //if(checked){ //Закоментировала эту строку, так как в задании написано, что ProgressBar должен увеличиваться при каждом нажатии.
    if(ui->progressBar->value()<100){
        ui->progressBar->setValue(ui->progressBar->value()+10);
    }else{ ui->progressBar->setValue(0);}
    //}
}

