#include <iostream>
#include "job1.hpp"
using namespace std;

int main() {
    Joueur joueur;

    joueur.initialiser(5, 5);
    joueur.afficherPosition();

    joueur.deplacerHaut();
    joueur.deplacerGauche();
    joueur.afficherPosition();

    joueur.deplacerBas();
    joueur.deplacerDroite();
    joueur.deplacerDroite();
    joueur.afficherPosition();

    return 0;
}
