#include <iostream>
using namespace std;

int main() {
    int tab[] = {12, 45, 3, 89, 21, 56};
    int taille = sizeof(tab) / sizeof(tab[0]);

    // Supposons que le premier élément est le maximum
    int max = tab[0];

    // Parcourir le tableau
    for (int i = 1; i < taille; ++i) {
        if (tab[i] > max) {
            max = tab[i];
        }
    }

    cout << "La valeur maximale du tableau est : " << max << endl;

    return 0;
}
