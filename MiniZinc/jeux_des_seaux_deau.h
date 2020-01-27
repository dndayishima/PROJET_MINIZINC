#ifndef JEUX_DES_SEAUX_DEAU_H
#define JEUX_DES_SEAUX_DEAU_H

#include <QDialog>
#include <QLabel>
#include <string>

namespace Ui {
class jeux_des_seaux_deau;
}

class jeux_des_seaux_deau : public QDialog
{
    Q_OBJECT

public:
    explicit jeux_des_seaux_deau(QWidget *parent = 0);
    ~jeux_des_seaux_deau();
    void init();
    void start_game();
    void end_transfert();
    void end_game();

private:
    Ui::jeux_des_seaux_deau *ui;

private slots:
    void on_solvability_clicked();
    void on_pushButton_clicked();
    void on_seau_A_clicked();
    void on_seau_B_clicked();
    void on_seau_C_clicked();
    void on_unselect_clicked();
};

// déclaration de fonctions

// lecture dans le résultat reçu après l'exécution de
// MiniZinc
// on récupère le nombre de tranferts maximal à effectuer
void init_nb_transferts(std::string string);

// Pour pouvoir effectuer un transfert, on a besoin de savoir :
// - capacité src
// - capacité courante de la dest
// - capacité maximale de la dest
bool transfert(int &capacite_src, int &capacite_dest, int &capacite_max_dest);

#endif // JEUX_DES_SEAUX_DEAU_H
