#ifndef PRICECONTR_H
#define PRICECONTR_H

#include <QDialog>

namespace Ui {
class Pricecontr;
}

class Pricecontr : public QDialog
{
    Q_OBJECT

public:
    explicit Pricecontr(QWidget *parent = nullptr);
    ~Pricecontr();

private slots:


    void on_Zakaz_clicked();

    void on_klog_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Pricecontr *ui;
};

#endif // PRICECONTR_H
