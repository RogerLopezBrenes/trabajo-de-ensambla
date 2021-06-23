#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int number_1 = 0;   //para poder convertir el Qstring a entero y poder manipularlo
int number_2 = 0;   //aqui igual
QString n1;         //para poder poner el numero en los label y text
QString n2;         //aqui lo mismo xd

MainWindow::MainWindow(QWidget *parent)     //constructor
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()                   //destructor
{
    delete ui;
}

//para lineEdit1
void MainWindow::on_number_0_clicked()
{
    QString n = "0";
    ui->lineEdit->setText(n);
    number_1 = (number_1*10) + n.toInt();
    n1 = QString::number(number_1);
    ui->lineEdit->setText(n1);
}

void MainWindow::on_number_1_clicked()
{
    //if(){} creo que se necesita un if para saber si escribe en el lineEdit1 o lineEdit2
    QString n = "1";
    ui->lineEdit->setText(n1);
    number_1 = (number_1*10) + n.toInt();
    n1 = QString::number(number_1);
    ui->lineEdit->setText(n1);
}

void MainWindow::on_number_2_clicked()
{
    QString n = "2";
    ui->lineEdit->setText(n1);
    number_1 = (number_1*10) + n.toInt();
    n1 = QString::number(number_1);
    ui->lineEdit->setText(n1);
}


void MainWindow::on_number_3_clicked()
{
    QString n = "3";
    ui->lineEdit->setText(n1);
    number_1 = (number_1*10) + n.toInt();
    n1 = QString::number(number_1);
    ui->lineEdit->setText(n1);
}


void MainWindow::on_number_4_clicked()
{
    QString n = "4";
    ui->lineEdit->setText(n1);
    number_1 = (number_1*10) + n.toInt();
    n1 = QString::number(number_1);
    ui->lineEdit->setText(n1);
}


void MainWindow::on_number_5_clicked()
{
    QString n = "5";
    ui->lineEdit->setText(n1);
    number_1 = (number_1*10) + n.toInt();
    n1 = QString::number(number_1);
    ui->lineEdit->setText(n1);
}

void MainWindow::on_number_6_clicked()
{
    QString n = "6";
    ui->lineEdit->setText(n1);
    number_1 = (number_1*10) + n.toInt();
    n1 = QString::number(number_1);
    ui->lineEdit->setText(n1);
}

void MainWindow::on_number_7_clicked()
{
    QString n = "7";
    ui->lineEdit->setText(n1);
    number_1 = (number_1*10) + n.toInt();
    n1 = QString::number(number_1);
    ui->lineEdit->setText(n1);
}

void MainWindow::on_number_8_clicked()
{
    QString n = "8";
    ui->lineEdit->setText(n1);
    number_1 = (number_1*10) + n.toInt();
    n1 = QString::number(number_1);
    ui->lineEdit->setText(n1);
}

void MainWindow::on_number_9_clicked()
{
    QString n = "9";
    ui->lineEdit->setText(n1);
    number_1 = (number_1*10) + n.toInt();
    n1 = QString::number(number_1);
    ui->lineEdit->setText(n1);
}


//solo convierte el numero a binario
void MainWindow::on_button_equal_clicked()
{
    int binary = n1.toInt();
    QString r = "";
    while (binary != 0){
        if(binary%2 == 0){
            r = "0"+r;
        } else {
            r = "1"+r;
        }
        binary /= 2;
    }
    ui->lineEdit_2->setText(r);
}


void MainWindow::on_button_Clear_clicked()
{
    n1 = "";
    number_1 = 0;
    ui->lineEdit_2->setText("");
    ui->lineEdit->setText("");
}

