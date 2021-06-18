#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int number_1;
int number_2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_number_1_clicked()
{
    QString n1;
    n1 = ui->lineEdit->text();
    number_1 = n1.toInt();
}

