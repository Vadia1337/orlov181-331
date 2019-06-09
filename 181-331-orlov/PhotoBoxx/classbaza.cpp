#include "classbaza.h"
#include <QFile>
#include <QString>
#include <iostream>
#include <fstream>
#include <string>
#include <QMessageBox>


ClassBaza::ClassBaza()
{


    using namespace std;

    ifstream file ("/Users/vador/Documents/PhotoBoxx/busers.txt");
    string line;
    getline(file, line);
    cout << "У тебя получилось!!!"  << endl;




}
