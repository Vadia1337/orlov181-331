#ifndef ZAKAZ_H
#define ZAKAZ_H

#include <QDialog>

namespace Ui {
class Zakaz;
}

class Zakaz : public QDialog
{
    Q_OBJECT

public:
    explicit Zakaz(QWidget *parent = nullptr);
    ~Zakaz();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::Zakaz *ui;
};

#endif // ZAKAZ_H
