#ifndef VSEZAKAZI_H
#define VSEZAKAZI_H

#include <QDialog>

namespace Ui {
class vsezakazi;
}

class vsezakazi : public QDialog
{
    Q_OBJECT

public:
    explicit vsezakazi(QWidget *parent = nullptr);
    ~vsezakazi();

private slots:
    void on_pushButton_clicked();

private:
    Ui::vsezakazi *ui;
};

#endif // VSEZAKAZI_H
