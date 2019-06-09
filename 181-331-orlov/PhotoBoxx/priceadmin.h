#ifndef PRICEADMIN_H
#define PRICEADMIN_H


#include <QDialog>

namespace Ui {
class priceadmin;
}

class priceadmin : public QDialog
{
    Q_OBJECT

public:
    explicit priceadmin(QWidget *parent = nullptr);
    ~priceadmin();

private slots:


    void on_Zakaz_clicked();

    void on_klog_clicked();

    void on_pushButton_clicked();

private:
    Ui::priceadmin *ui;

};

#endif // PRICEADMIN_H
