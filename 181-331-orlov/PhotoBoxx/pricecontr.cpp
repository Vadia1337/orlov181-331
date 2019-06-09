#include "pricecontr.h"
#include "ui_pricecontr.h"
#include "mainwindow.h"
#include "conzakaz.h"
#include "zakaz.h"
#include <string>
#include <QString>
#include <iostream>
#include <fstream>
#include "change.h"
#include <QFile>

Pricecontr::Pricecontr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pricecontr)
{
    ui->setupUi(this);
    using namespace std;

    ifstream file ("/Users/vador/Documents/PhotoBoxx/buf.txt");
    string line;
    getline(file, line);


    int dlin = line.length();
    int flas = line.find(":");
    line.erase(flas, dlin);

    QString qline = QString::fromStdString(line);

    ui->yourlogin->setText(qline);

}
Pricecontr::~Pricecontr()
{
    delete ui;
}
using namespace std;

void Pricecontr::on_Zakaz_clicked()
{
close();
Zakaz op;
op.setModal(true);
op.exec();
}

void Pricecontr::on_klog_clicked()
{
    close();
    MainWindow *ad = new MainWindow;
        ad->show();

}

void Pricecontr::on_pushButton_clicked()
{

    Change ope;
    ope.setModal(true);
    ope.exec();


}

void Pricecontr::on_pushButton_2_clicked()
{


    Conzakaz ope;
    ope.setModal(true);
    ope.exec();


}
