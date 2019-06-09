#include "vsezakazi.h"
#include "ui_vsezakazi.h"
#include "priceadm.h"
#include "pricecontr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QString>
#include <string>


vsezakazi::vsezakazi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vsezakazi)
{
    ui->setupUi(this);
    using namespace std;

    ifstream file ("/Users/vador/Documents/PhotoBoxx/zakazi.txt");
    string line;
    getline(file, line);


    QString qline = QString::fromStdString(line);

    ui->textBrowser->setText(qline);




}












vsezakazi::~vsezakazi(){

delete ui;

}



void vsezakazi::on_pushButton_clicked()
{
    std::ifstream bufer ("/Users/vador/Documents/PhotoBoxx/buf.txt");
    std::string sbufer;
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

        }
}
