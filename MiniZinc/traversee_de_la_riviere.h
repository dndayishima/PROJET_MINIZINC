#ifndef TRAVERSEE_DE_LA_RIVIERE_H
#define TRAVERSEE_DE_LA_RIVIERE_H

#include <QDialog>

namespace Ui {
class traversee_de_la_riviere;
}

class traversee_de_la_riviere : public QDialog
{
    Q_OBJECT

public:
    explicit traversee_de_la_riviere(QWidget *parent = 0);
    ~traversee_de_la_riviere();

private:
    Ui::traversee_de_la_riviere *ui;
};

#endif // TRAVERSEE_DE_LA_RIVIERE_H
