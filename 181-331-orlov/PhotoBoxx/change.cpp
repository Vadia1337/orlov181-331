#include "change.h"
#include "ui_change.h"
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


Change::Change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Change)
{
    ui->setupUi(this);
}

Change::~Change()
{
    delete ui;
}
using namespace std;

void Change::on_pushButton_clicked()
{

     QString nlogin = ui->newlog->text();
     string s_nlogin = nlogin.toStdString ();

     ifstream file11 ("/Users/vador/Documents/PhotoBoxx/buf.txt");
     string activelog;
     getline(file11, activelog);


     int dlin = activelog.length();
    int first = activelog.find_first_of(":");
    activelog.erase(first, dlin - first);





    ifstream file ("/Users/vador/Documents/PhotoBoxx/busers.txt");
    string line;
    // getline(file, line);
    file >> line;
   int num1 = activelog.length();
    int num = line.find(activelog);
    line.erase(num, num1);
    line.insert(num,s_nlogin);
    file.close();

    ofstream file1 ("/Users/vador/Documents/PhotoBoxx/busers.txt");




    file1 << line;

    QMessageBox::information(this, "Информация", "Логин успешно изменён!", "Ок" );

    close();

}


void Change::on_pushButton_2_clicked()
{



    QString spass = ui->strpass->text();
    QString npass = ui->newpass->text();
    QString npass1 = ui->newpass1->text();

    string s_spass = spass.toStdString ();
    string s_npass = npass.toStdString ();
    string s_npass1 = npass1.toStdString ();

    ifstream file2 ("/Users/vador/Documents/PhotoBoxx/busers.txt");
    string line1;
    while(getline(file2, line1)){

    if (s_npass != s_npass1){
    QMessageBox::warning(this, "Информация", "Пароли не совпадают!", "Ок" );
    }else
    {

        int num1 = s_spass.length();
         int num = line1.find(s_spass);
         line1.erase(num, num1);
         line1.insert(num ,s_npass);


         ofstream file2 ("/Users/vador/Documents/PhotoBoxx/busers.txt");

         file2 << line1;

         QMessageBox::information(this, "Информация", "Пароль измененён!", "Ок" );

         close();
}
}



}
