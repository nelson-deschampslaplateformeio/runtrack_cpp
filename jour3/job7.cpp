#include <iostream>
using namespace std;

int main() {
    const int TAILLE = 10;
    int T[TAILLE];

    // Saisie des entiers
    cout << "Saisissez 10 entiers :" << endl;
    for (int i = 0; i < TAILLE; ++i) {
        cout << "T[" << i << "] = ";
        cin >> T[i];
    }

    // Recherche de l'indice du plus grand élément
    int maxIndice = 0;
    for (int i = 1; i < TAILLE; ++i) {
        if (T[i] > T[maxIndice]) {
            maxIndice = i;
        }
    }

    // Affichage de l'indice du plus grand élément
    cout << "L'indice du plus grand élément est : " << maxIndice << endl;
    cout << "Valeur maximale : " << T[maxIndice] << endl;

    return 0;
}
