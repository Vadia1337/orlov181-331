#ifndef CONZAKAZ_H
#define CONZAKAZ_H

#include <QDialog>

namespace Ui {
class Conzakaz;
}

class Conzakaz : public QDialog
{
    Q_OBJECT

public:
    explicit Conzakaz(QWidget *parent = nullptr);
    ~Conzakaz();

private:
    Ui::Conzakaz *ui;
};

#endif // CONZAKAZ_H
