#include <iostream>
#include <iomanip> // pour setw()
using namespace std;

int main() {
    // En-tête des colonnes
    cout << "    |";
    for (int i = 1; i <= 10; ++i) {
        cout << setw(4) << i;
    }
    cout << endl;

    // Ligne de séparation
    cout << "----+";
    for (int i = 1; i <= 10; ++i) {
        cout << "----";
    }
    cout << endl;

    // Affichage du tableau de multiplication
    for (int i = 1; i <= 10; ++i) {
        cout << setw(3) << i << " |";  // numéro de ligne
        for (int j = 1; j <= 10; ++j) {
            cout << setw(4) << i * j;  // produit
        }
        cout << endl;
    }

    return 0;
}
