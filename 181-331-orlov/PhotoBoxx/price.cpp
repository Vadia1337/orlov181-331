#include "price.h"
#include "ui_price.h"
#include "mainwindow.h"
#include "zakaz.h"
#include <string>
#include <QString>
#include <iostream>
#include <fstream>
#include "change.h"
#include <QFile>

Price::Price(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Price)
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
using namespace std;



Price::~Price()
{
    delete ui;
}

void Price::on_Zakaz_clicked()
{
close();
Zakaz op;
op.setModal(true);
op.exec();
}

void Price::on_klog_clicked()
{
    close();
    MainWindow *ad = new MainWindow;
        ad->show();

}

void Price::on_pushButton_clicked()
{

    Change ope;
    ope.setModal(true);
    ope.exec();


}
