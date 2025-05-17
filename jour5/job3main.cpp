#include "Job3.hpp"

int main() {
    // Joueur 1 avec constructeur par défaut
    Joueur joueur1;
    joueur1.afficherNom();
    joueur1.afficherPosition();

    // Joueur 2 avec constructeur x, y
    Joueur joueur2(3, 4);
    joueur2.afficherNom();
    joueur2.afficherPosition();

    // Joueur 3 avec constructeur x, y, nom
    Joueur joueur3(7, 2, "Alex");
    joueur3.afficherNom();
    joueur3.afficherPosition();

    return 0;
}
