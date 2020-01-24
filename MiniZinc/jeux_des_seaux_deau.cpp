#include "jeux_des_seaux_deau.h"
#include "ui_jeux_des_seaux_deau.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <QString>
#include <QStringList>
#include <QLabel>
#include <QPushButton>
#include <stdlib.h>
#include <stdio.h>

//#include <QDir>
//#include <unistd.h>

using namespace std;

// Quelques variables stockées

int nb_transferts = 0; // nb de transferts que l'utilisateur de doit pas dépasser
int steps_done = 0; // nb de tours joués
//bool solvality_check_clicked = false; // on vérifie qu'on a pas encore appuyé sur le bouton "Tester la solvabilité"

// ces données sont en brut mais pourraient être
// bien lues depuis un fichier .dzn
int max_capacity_sa = 8;
int max_capacity_sb = 5;
int max_capacity_sc = 3;
int capacity_sa = 8;
int capacity_sb = 0;
int capacity_sc = 0;

// capacité voulues
int fin_capacity_sa = 4;
int fin_capacity_sb = 4;
int fin_capacity_sc = 0;

// statut - en cours de transfert ou pas
bool transfering = false;
string transfert_src = "";

// Les messages à afficher
QString before_msg = "Appuyer d'abord sur \"TESTER LA SOLVABILITE\" !";
string info_max_nb_transferts = "Nombre de transferts maximum : ";

// Widgets de la fenêtre
QLabel *message, *steps, *seau_A_contents, *seau_B_contents, *seau_C_contents;
QLabel *max_seau_A, *max_seau_B, *max_seau_C;
QPushButton *seau_A, *seau_B, *seau_C;

jeux_des_seaux_deau::jeux_des_seaux_deau(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::jeux_des_seaux_deau)
{
    ui->setupUi(this);

    // on fait l'initialisation ensuite
    this->init();
}

void jeux_des_seaux_deau::init() {
    message = ui->message;
    message->setText(before_msg);

    seau_A = ui->seau_A;
    seau_A->setEnabled(false);

    seau_B = ui->seau_B;
    seau_B->setEnabled(false);

    seau_C = ui->seau_C;
    seau_C->setEnabled(false);

    // masquer les labels qui sont utilisés en cours de jeu
    steps = ui->steps;
    steps->hide();
    seau_A_contents = ui->seau_A_contents;
    seau_A_contents->hide();
    seau_B_contents = ui->seau_B_contents;
    seau_B_contents->hide();
    seau_C_contents = ui->seau_C_contents;
    seau_C_contents->hide();

    // affichage des capacités maximales
    max_seau_A = ui->max_seau_A;
    ostringstream os_max_A;
    os_max_A << "Max " << max_capacity_sa << " L";
    max_seau_A->setText(QString::fromStdString(os_max_A.str()));

    max_seau_B = ui->max_seau_B;
    ostringstream os_max_B;
    os_max_B << "Max " << max_capacity_sb << " L";
    max_seau_B->setText(QString::fromStdString(os_max_B.str()));

    max_seau_C = ui->max_seau_C;
    ostringstream os_max_C;
    os_max_C << "Max " << max_capacity_sc << " L";
    max_seau_C->setText(QString::fromStdString(os_max_C.str()));
}

jeux_des_seaux_deau::~jeux_des_seaux_deau()
{
    delete ui;
}

// vérification de la solvabilité d'un modèle
void jeux_des_seaux_deau::on_solvability_clicked()
{
    FILE *in;
    char buff[512];

    // Création d'un PIPE pour que nous puissions
    // lire le résultat de l'exécution d'un
    // programme

    //QDir directory(":/game1");

    //string data = ":/game1/game_1_mzn/1.dzn";
    string data = "~/.minizinc-games/1.dzn";
    //string data = directory.absoluteFilePath("game_1_mzn/1.dzn").toStdString();
    //string model = ":/game1/game_1_mzn/1.mzn";
    string model = "~/.minizinc-games/1.mzn";
    //string model = directory.absoluteFilePath("game_1_mzn/1.mzn").toStdString();

    string cmd = "minizinc --solver Gecode " + model + " " + data;
    //cout << cmd << endl;

    in = popen(cmd.c_str(), "r");
    if (!in) {
        exit(1); // s'il n'y a rien, nous sortons du programme
    }

    // Vector de String dans lequel nous allons stocker
    // ligne par ligne le résultat de notre exécution de
    // la commande minizinc
    std::vector<std::string> result;

    // lecture de la sortie de l'exécution
    // ligne par ligne
    while (fgets(buff, sizeof(buff), in) != NULL ) {
        result.push_back(buff);
        //cout << buff << endl;
    }

    // affichage du résultat pour le débogage
    for (unsigned int i = 0; i < result.size(); ++i) {
        cout << result[i];
    }
    cout << endl;
    // fermeture du PIPE
    pclose(in);

    // extraction du nombre de transferts que l'utilisateur ne doit pas
    // dépasser
    init_nb_transferts(result[0]);

    // on vérifie si le nb_transferts != 0
    // si c'est le cas, le joueur peut commencer à jouer
    if (nb_transferts != 0) {
        this->start_game();
    } else {
        // dire que ce n'est pas satisfiable
    }
}

void jeux_des_seaux_deau::on_pushButton_clicked()
{
    close();
}

void jeux_des_seaux_deau::start_game() {
    seau_A->setEnabled(true);
    seau_B->setEnabled(true);
    seau_C->setEnabled(true);

    // construction du nouveau message
    ostringstream os;
    os << info_max_nb_transferts << nb_transferts;
    message->setText(QString::fromStdString(os.str()));

    // afficher les différents labels du jeu
    ostringstream os_steps;
    os_steps << steps_done;
    steps->setText(QString::fromStdString(os_steps.str()));
    steps->show();

    ostringstream os_sa;
    os_sa << capacity_sa << " L";
    seau_A_contents->setText(QString::fromStdString(os_sa.str()));
    seau_A_contents->show();

    ostringstream os_sb;
    os_sb << capacity_sb << " L";
    seau_B_contents->setText(QString::fromStdString(os_sb.str()));
    seau_B_contents->show();

    ostringstream os_sc;
    os_sc << capacity_sc << " L";
    seau_C_contents->setText(QString::fromStdString(os_sc.str()));
    seau_C_contents->show();
}


void init_nb_transferts(string string) {
    QString qs = QString::fromStdString(string);
    QStringList qsl = qs.split("=");
    QString neededStr = qsl.value(qsl.length() - 1);

    nb_transferts = atoi(neededStr.toStdString().c_str()); // 0 dans le cas où ce n'est pas un chiffre
}



void jeux_des_seaux_deau::on_seau_A_clicked()
{
    if (!transfering) {
        seau_A->setEnabled(false);
        transfering = true;
        transfert_src = "A";
    }
}

void jeux_des_seaux_deau::on_seau_B_clicked()
{
    if (!transfering) {
        seau_B->setEnabled(false);
        transfering = true;
        transfert_src = "B";
    } else {
        //transfert(transfert_src, "B");
    }
}

void jeux_des_seaux_deau::on_seau_C_clicked()
{

}

/*void jeux_des_seaux_deau::transfert(string src, string dest){
    int *src_content;
    int *dest_content;
    int *dest_capacity;

    if (src == "A") {
        src_content = capacity_sa;
        //src_content += 1;
    }
    if (src == "B") {
        src_content = &capacity_sb;
    }
    if (src == "C") {
        src_content = &capacity_sc;
    }

    cout << "src content " << src_content << endl;
    //cout << "dest content " << dest << endl;
}*/
