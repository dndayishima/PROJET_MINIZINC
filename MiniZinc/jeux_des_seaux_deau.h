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
    void transfert(std::string src, std::string dest);

private:
    Ui::jeux_des_seaux_deau *ui;

private slots:
    void on_solvability_clicked();
    void on_pushButton_clicked();
    void on_seau_A_clicked();
    void on_seau_B_clicked();
    void on_seau_C_clicked();
};

// déclaration de fonctions
void init_nb_transferts(std::string string);

#endif // JEUX_DES_SEAUX_DEAU_H
