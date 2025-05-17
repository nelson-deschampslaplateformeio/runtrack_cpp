#include <iostream>
using namespace std;

int main() {
    const int TAILLE = 10;
    int T[TAILLE];
    int compteur = 0;

    // Saisie des 10 entiers
    cout << "Saisissez 10 entiers :" << endl;
    for (int i = 0; i < TAILLE; ++i) {
        cout << "T[" << i << "] = ";
        cin >> T[i];

        // Comptage si >= 5
        if (T[i] >= 5) {
            compteur++;
        }
    }

    // Affichage du résultat
    cout << "Nombre d'entiers >= 5 : " << compteur << endl;

    return 0;
}
