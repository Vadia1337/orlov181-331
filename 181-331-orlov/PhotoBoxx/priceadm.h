#ifndef PRICEADM_H
#define PRICEADM_H

#include <QDialog>

namespace Ui {
class Priceadm;
}

class Priceadm : public QDialog
{
    Q_OBJECT

public:
    explicit Priceadm(QWidget *parent = nullptr);
    ~Priceadm();

private slots:


    void on_Zakaz_clicked();

    void on_klog_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Priceadm *ui;
};

#endif // PRICEADM_H
