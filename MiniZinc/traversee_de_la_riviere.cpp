#include "traversee_de_la_riviere.h"
#include "ui_traversee_de_la_riviere.h"

traversee_de_la_riviere::traversee_de_la_riviere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::traversee_de_la_riviere)
{
    ui->setupUi(this);
}

traversee_de_la_riviere::~traversee_de_la_riviere()
{
    delete ui;
}
