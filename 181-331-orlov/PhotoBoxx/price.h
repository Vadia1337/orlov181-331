#ifndef PRICE_H
#define PRICE_H

#include <QDialog>

namespace Ui {
class Price;
}

class Price : public QDialog
{
    Q_OBJECT

public:
    explicit Price(QWidget *parent = nullptr);
    ~Price();

private slots:


    void on_Zakaz_clicked();

    void on_klog_clicked();

    void on_pushButton_clicked();

private:
    Ui::Price *ui;

};



#endif // PRICE_H
