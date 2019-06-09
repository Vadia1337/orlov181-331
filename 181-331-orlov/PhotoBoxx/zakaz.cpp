#include "zakaz.h"
#include "ui_zakaz.h"
#include "price.h"
#include "priceadm.h"
#include "pricecontr.h"
#include <iostream>
#include <fstream>
#include <QString>
#include <string>
#include <QMessageBox>
#include <locale>
#include<ctype.h>

Zakaz::Zakaz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Zakaz)
{
    ui->setupUi(this);

    using namespace std;
    ifstream baza ("/Users/vador/Documents/PhotoBoxx/contractors.txt");//вытаскиваем контрактеров
    string sbaza;
    getline(baza, sbaza);


    QString qbaza = QString::fromStdString(sbaza);

    ui->textBrowser_ispolnitel->setText(qbaza);




}

Zakaz::~Zakaz()
{
    delete ui;
}
 using namespace std;
void Zakaz::on_pushButton_clicked()
{



    ifstream bufer ("/Users/vador/Documents/PhotoBoxx/buf.txt");
    string sbufer;
    getline(bufer, sbufer);

  int buad = sbufer.find(":admin");
  int bucont = sbufer.find(":contractor");

        if (buad != 0){

            close();
            Priceadm pr1;
            pr1.setModal(true);
            pr1.exec();


        }else if (bucont != 0) {


            close();
            Pricecontr pr2;
            pr2.setModal(true);
            pr2.exec();

        }else {


            close();
            Price pr2;
            pr2.setModal(true);
            pr2.exec();


        }


}

void Zakaz::on_pushButton_3_clicked()
{
int mone = 0;
string res;
   QString photob = ui->comboBox->currentText();
   QString _photob = ui->lineEdit->text();
   QString photost = ui->comboBox_2->currentText();
   QString _photost = ui->lineEdit_2->text();
   QString photosh = ui->comboBox_3->currentText();
   QString _photosh = ui->lineEdit_3->text();
   QString photopr = ui->comboBox_4->currentText();
   QString _photopr = ui->lineEdit_4->text();

    string s_photob = photob.toStdString ();//
    string s__photob = _photob.toStdString ();
    string s_photost = photost.toStdString ();//
    string s__photost = _photost.toStdString ();
    string s_photosh = photosh.toStdString ();//
    string s__photosh = _photosh.toStdString ();
    string s_photopr = photopr.toStdString ();//
    string s__photopr = _photopr.toStdString ();







 res = s_photob + ":№" + s__photob + ":" + s_photost + ":№" + s__photost + ":" + s_photosh + ":№" + s__photosh + ":" + s_photopr + ":№" + s__photopr;




//сумма позиций
 int f = s_photob.find('-');
 s_photob.erase(0,f+1);
 string ress = s_photob;
 mone = (mone + atoi(ress.c_str()))*atoi(s__photob.c_str());

 int f1 = s_photost.find('-');
  s_photost.erase(0,f1+1);
  string ress1 = s_photost;
  mone = (mone + atoi(ress1.c_str()))*atoi(s__photost.c_str());

  int f2 = s_photosh.find('-');
   s_photosh.erase(0,f2+1);
   string ress2 = s_photosh;
   mone = (mone + atoi(ress2.c_str()))*atoi(s__photosh.c_str());

   int f3 = s_photopr.find('-');
    s_photopr.erase(0,f3+1);
    string ress3 = s_photopr;
    mone = (mone + atoi(ress3.c_str()))*atoi(s__photopr.c_str());

    QString qsmone = QString::number(mone);

    ui->textBrowser_2->setText(qsmone);//цена



 for(int i = 0; i < res.length(); i++) {
     if(res[i] == ' ') {
             res.erase(i,1);
             i--;
 }     
}
QString qres = QString::fromStdString(res);
ui->textBrowser->setText(qres);//заказ


}

void Zakaz::on_pushButton_4_clicked()
{

    ui->textBrowser->clear();

}

void Zakaz::on_pushButton_2_clicked()
{
   QString text =  ui->textBrowser->toPlainText();
   string stext = text.toStdString();


   ifstream file ("/Users/vador/Documents/PhotoBoxx/buf.txt");  //вытаскиваем логин
   string line;
   getline(file, line);

  QString sum = ui->textBrowser_2->toPlainText();
   string ssum = sum.toStdString();


QString con = ui->lineEdit_5->text();//вытащили имя контрактора
string ccon = con.toStdString();


   string zakaz = stext + " " + "Заказчик:" + " " + line + ";" + " " + "Сумма заказа:"+ssum + " " + "Исполнитель::" + ccon ;

   ofstream file1 ("/Users/vador/Documents/PhotoBoxx/zakazi.txt", ios_base::app);







   file1 << zakaz;
   file1.close();



QMessageBox::information(this, "Информация", "Ваш заказ отправлен!", "Хорошо" );


}

