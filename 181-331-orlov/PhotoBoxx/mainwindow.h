#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QFile>
#include <QString>
#include <iostream>
#include <fstream>
#include <string>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:



    class wbaza {

    private:





    public:

        void openbaza(){


               using namespace std;

        ifstream file ("/Users/vador/Documents/PhotoBoxx/busers.txt");
        string line;

        getline(file, line);

        }



    };



    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};



#endif // MAINWINDOW_H
