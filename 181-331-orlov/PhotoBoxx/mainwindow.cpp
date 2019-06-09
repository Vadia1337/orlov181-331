#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "priceadm.h"
#include "pricecontr.h"
#include "price.h"
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}


MainWindow::~MainWindow()
{
    delete ui;
}



using namespace std;


void openpricewind(){ //открываем окно для юзеров

    Price pr;
    pr.setModal(true);
    pr.exec();

}
void openpricewindadm(){ // для админов

    Priceadm pr;
    pr.setModal(true);
    pr.exec();

}
void openpricewindcontr(){ // для контракторов

    Pricecontr pr;
    pr.setModal(true);
    pr.exec();

}



void MainWindow::on_pushButton_clicked()
{


    ifstream file ("/Users/vador/Documents/PhotoBoxx/busers.txt");
string line;


    QString login = ui->lineEdit->text(); //берем логин
    QString Pass = ui->lineEdit_2->text();// пароль

    string _login = login.toStdString ();
    string _Pass = Pass.toStdString ();


    while(getline(file, line)){
        if (line == _login + ":" + _Pass + ":user"){
            QMessageBox::information(this, "Информация", "User, вы успешно вошли!", "Хорошо" );
            ofstream file1 ("/Users/vador/Documents/PhotoBoxx/buf.txt");
            file1.clear(); // чистим файл
            file1 << _login + ":user";
            file1.close(); //закрыли файл
            close();
            openpricewind();
        }

        if (line == _login + ":" + _Pass + ":contractor"){
            QMessageBox::information(this, "Информация", "Сontractor, вы успешно вошли!", "Хорошо" );
            ofstream file2 ("/Users/vador/Documents/PhotoBoxx/buf.txt");
            file2.clear();
            file2 << _login + ":contractor";
            file2.close();
            close();
            openpricewindcontr();
        }

        if (line == _login + ":" + _Pass + ":admin"){
            QMessageBox::information(this, "Информация", "Admin, вы успешно вошли!", "Хорошо" );
            ofstream file3 ("/Users/vador/Documents/PhotoBoxx/buf.txt");
            file3.clear();
            file3 << _login + ":admin";
            file3.close();
            close();
            openpricewindadm();
        }


    else{
        ui->textEdit->setText("Неверный логин или пароль!");
    }


}
}

