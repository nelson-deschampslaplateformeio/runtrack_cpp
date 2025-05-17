#include <iostream>
using namespace std;

int main() {
    int taille;

    // Demander la taille du tableau
    cout << "Entrez la taille du tableau : ";
    cin >> taille;

    // Vérification
    if (taille <= 0) {
        cout << "La taille doit être un entier positif." << endl;
        return 1;
    }

    // Création du tableau dynamique
    int* tableau = new int[taille];

    // Remplissage du tableau
    for (int i = 0; i < taille; ++i) {
        cout << "Entrez la valeur de l'élément " << i << " : ";
        cin >> tableau[i];
    }

    // Affichage du tableau
    cout << "Contenu du tableau : ";
    for (int i = 0; i < taille; ++i) {
        cout << tableau[i] << " ";
    }
    cout << endl;

    // Libération de la mémoire
    delete[] tableau;

    return 0;
}
