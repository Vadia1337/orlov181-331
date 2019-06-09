#include "priceadm.h"
#include "ui_priceadm.h"
#include "mainwindow.h"
#include "vsezakazi.h"
#include "zakaz.h"
#include <string>
#include <QString>
#include <iostream>
#include <fstream>
#include "change.h"
#include <QFile>

Priceadm::Priceadm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Priceadm)
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

Priceadm::~Priceadm()
{
    delete ui;
}
void Priceadm::on_Zakaz_clicked()
{
close();
Zakaz op;
op.setModal(true);
op.exec();
}

void Priceadm::on_klog_clicked()
{
    close();
    MainWindow *ad = new MainWindow;
        ad->show();

}

void Priceadm::on_pushButton_clicked()
{

    Change ope;
    ope.setModal(true);
    ope.exec();


}
void Priceadm::on_pushButton_2_clicked()
{
    close();
    vsezakazi open;
    open.setModal(true);
    open.exec();
}
