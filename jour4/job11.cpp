#include <iostream>
#include <string>
using namespace std;

int main() {
    // Tableau statique des fruits
    string fruit[5] = {"Pomme", "Banane", "Fraise", "Mangue", "Ananas"};

    // Affichage du tableau fruit
    cout << "Liste de fruits disponibles : ";
    for (int i = 0; i < 5; ++i) {
        cout << fruit[i];
        if (i < 4) cout << ", ";
    }
    cout << endl;

    // Demande du nombre de fruits préférés
    int tailleFavoris;
    cout << "Combien de fruits préférez-vous ? ";
    cin >> tailleFavoris;

    if (tailleFavoris <= 0) {
        cout << "Le nombre doit être supérieur à 0." << endl;
        return 1;
    }

    // Allocation dynamique du tableau favoris
    string* favoris = new string[tailleFavoris];

    // Saisie des fruits favoris
    cout << "Entrez vos fruits préférés :" << endl;
    for (int i = 0; i < tailleFavoris; ++i) {
        cout << "Fruit " << (i + 1) << " : ";
        cin >> favoris[i];
    }

    // Affichage des favoris
    cout << "Vos fruits favoris sont : ";
    for (int i = 0; i < tailleFavoris; ++i) {
        cout << favoris[i];
        if (i < tailleFavoris - 1) cout << ", ";
    }
    cout << endl;

    // Libération de la mémoire
    delete[] favoris;

    return 0;
}
