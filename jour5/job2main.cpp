#include "job2.hpp"

int main() {
    // Utilisation du constructeur avec position personnalisée
    Joueur joueur(4, 2);

    joueur.afficherPosition();

    // Simuler quelques déplacements
    joueur.deplacerDroite();
    joueur.deplacerBas();
    joueur.deplacerGauche();

    joueur.afficherPosition();

    return 0;
}
