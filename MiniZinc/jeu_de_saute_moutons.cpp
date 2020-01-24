#include "jeu_de_saute_moutons.h"
#include "ui_jeu_de_saute_moutons.h"

jeu_de_saute_moutons::jeu_de_saute_moutons(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::jeu_de_saute_moutons)
{
    ui->setupUi(this);
}

jeu_de_saute_moutons::~jeu_de_saute_moutons()
{
    delete ui;
}
