#include "minizinc.h"
#include "ui_minizinc.h"
#include "jeux_des_seaux_deau.h"
#include "traversee_de_la_riviere.h"
#include "jeu_de_saute_moutons.h"

MiniZinc::MiniZinc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MiniZinc)
{
    ui->setupUi(this);
}

MiniZinc::~MiniZinc()
{
    delete ui;
}

// Slot pour ouvrir la fenêtre du jeu des seaux d'eau
void MiniZinc::on_pushButton_2_clicked()
{
    // hide();
    //this->setEnabled(false);
    jeux_des_seaux_deau jeux_des_seaux_deau;
    jeux_des_seaux_deau.setModal(true);
    jeux_des_seaux_deau.exec();
}

// Slot pour ouvrir la fenêtre du jeu de la traversée de la rivière
void MiniZinc::on_pushButton_clicked()
{
    // hide();
    traversee_de_la_riviere traversee_de_la_riviere;
    traversee_de_la_riviere.setModal(true);
    traversee_de_la_riviere.exec();
}

// Slot pour ouvrir le jeu du saute moutons
void MiniZinc::on_pushButton_3_clicked()
{
    // hide();
    jeu_de_saute_moutons jeu_de_saute_moutons;
    jeu_de_saute_moutons.setModal(true);
    jeu_de_saute_moutons.exec();
}
