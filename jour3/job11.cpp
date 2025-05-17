#include <iostream>
using namespace std;

int main() {
    const int taille = 10;
    int tableau[taille];
    int sommePairs = 0;

    // Saisie du tableau
    cout << "Entrez " << taille << " entiers :" << endl;
    for (int i = 0; i < taille; ++i) {
        cout << "Élément " << i << " : ";
        cin >> tableau[i];
    }

    // Calcul de la somme des éléments pairs
    for (int i = 0; i < taille; ++i) {
        if (tableau[i] % 2 == 0) {
            sommePairs += tableau[i];
        }
    }

    // Affichage du résultat
    cout << "La somme des éléments pairs est : " << sommePairs << endl;

    return 0;
}
