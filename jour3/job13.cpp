#include <iostream>
using namespace std;

int main() {
    // Deux tableaux déjà triés
    int tab1[] = {1, 3, 5, 7};
    int tab2[] = {2, 4, 6, 8, 10};
    
    int n1 = sizeof(tab1) / sizeof(tab1[0]);
    int n2 = sizeof(tab2) / sizeof(tab2[0]);

    int tab3[n1 + n2]; // tableau fusionné
    int i = 0, j = 0, k = 0;

    // Fusion en maintenant l’ordre croissant
    while (i < n1 && j < n2) {
        if (tab1[i] < tab2[j]) {
            tab3[k++] = tab1[i++];
        } else {
            tab3[k++] = tab2[j++];
        }
    }

    // Copie du reste
    while (i < n1) {
        tab3[k++] = tab1[i++];
    }

    while (j < n2) {
        tab3[k++] = tab2[j++];
    }

    // Affichage du tableau fusionné
    cout << "Tableau fusionné (ordre croissant) : ";
    for (int m = 0; m < n1 + n2; ++m) {
        cout << tab3[m] << " ";
    }
    cout << endl;

    return 0;
}
