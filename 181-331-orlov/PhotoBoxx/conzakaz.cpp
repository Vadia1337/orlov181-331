#include "conzakaz.h"
#include "ui_conzakaz.h"
#include <QFile>
#include <QString>
#include <iostream>
#include <fstream>
#include <string>

Conzakaz::Conzakaz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Conzakaz)
{
    ui->setupUi(this);

    using namespace std;

    ifstream file ("/Users/vador/Documents/PhotoBoxx/zakazi.txt");  //вытаскиваем базу заказов
    string line;
    getline(file, line);




    QString qline = QString::fromStdString(line);

    ui->textBrowser->setText(qline);
}

Conzakaz::~Conzakaz()
{
    delete ui;
}
