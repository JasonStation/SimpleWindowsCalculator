#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *resultButton = MainWindow::findChild<QPushButton *>("pushButton");
    connect(resultButton, SIGNAL(pressed()), this, SLOT(Solve()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Solve(){
    QString firstNum = ui->lineEdit->text();
    QString secondNum = ui->lineEdit_2->text();
    QString comboBox = ui->comboBox->currentText();
    double result = 0;
    if(QString::compare(comboBox, "+") == 0) result = firstNum.toDouble() + secondNum.toDouble();
    else if(QString::compare(comboBox, "-") == 0) result = firstNum.toDouble() - secondNum.toDouble();
    else if(QString::compare(comboBox, "/") == 0) result = firstNum.toDouble() / secondNum.toDouble();
    else result = firstNum.toDouble() * secondNum.toDouble();

    ui->result->setText(QString::number(result));
}

