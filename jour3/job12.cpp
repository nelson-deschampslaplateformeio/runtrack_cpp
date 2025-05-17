#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int MAX_TENTATIVES = 7;
    int nombreMystere, tentative, essai = 0;
    
    // Initialisation du générateur aléatoire
    srand(static_cast<unsigned int>(time(0)));
    nombreMystere = rand() % 101; // entre 0 et 100 inclus

    cout << "=== Jeu du Nombre Mystère ===" << endl;
    cout << "Devinez le nombre entre 0 et 100 !" << endl;
    cout << "Vous avez " << MAX_TENTATIVES << " tentatives." << endl;

    // Boucle de jeu
    while (essai < MAX_TENTATIVES) {
        cout << "\nEssai " << (essai + 1) << " : ";
        cin >> tentative;

        if (tentative == nombreMystere) {
            cout << "Bravo ! Vous avez trouvé le nombre mystère : " << nombreMystere << endl;
            return 0; // Fin du jeu
        } else if (tentative < nombreMystere) {
            cout << "Trop petit !" << endl;
        } else {
            cout << "Trop grand !" << endl;
        }

        essai++;
    }

    // Si le joueur n'a pas trouvé
    cout << "\nDommage ! Vous avez épuisé vos tentatives." << endl;
    cout << "Le nombre mystère était : " << nombreMystere << endl;

    return 0;
}
