#include "traversee_de_la_riviere.h"
#include "ui_traversee_de_la_riviere.h"
#include <vector>
#include <QLabel>

using namespace std;

// #include "globals.mzn"
int num_animaux = 3;
int max_trav = 10; // nb max de traversées
int max_num_trav = 2; // nb maximum d'animaux par traversée (min=1)
int A = 1; // rive A
int B = 2; // rive B

// où sont les buffles
std::vector<std::vector<int> > buffles(max_trav, std::vector<int>(num_animaux));

// où sont les lions
std::vector<std::vector<int> > lions(max_trav, std::vector<int>(num_animaux));

// où est le radeau
std::vector<int> radeau(max_trav);

// nb min de traversées
std::vector<int> total_trav(max_trav);

// les animaux transférés (sur le radeau)
std::vector<int> transfereB(max_trav);
std::vector<int> transfereL(max_trav);

// Widgets de la fenêtre

traversee_de_la_riviere::traversee_de_la_riviere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::traversee_de_la_riviere)
{
    ui->setupUi(this);

    this->init();
}

void traversee_de_la_riviere::init() {
}

traversee_de_la_riviere::~traversee_de_la_riviere()
{
    delete ui;
}
