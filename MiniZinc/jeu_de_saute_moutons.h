#ifndef JEU_DE_SAUTE_MOUTONS_H
#define JEU_DE_SAUTE_MOUTONS_H

#include <QDialog>

namespace Ui {
class jeu_de_saute_moutons;
}

class jeu_de_saute_moutons : public QDialog
{
    Q_OBJECT

public:
    explicit jeu_de_saute_moutons(QWidget *parent = 0);
    ~jeu_de_saute_moutons();

private:
    Ui::jeu_de_saute_moutons *ui;
};

#endif // JEU_DE_SAUTE_MOUTONS_H
