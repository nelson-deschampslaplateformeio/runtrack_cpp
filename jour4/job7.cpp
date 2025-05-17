#include <iostream>
using namespace std;

int main() {
    // Initialisation d’un tableau statique
    int tab[5] = {10, 20, 30, 40, 50};

    cout << "Contenu et adresses des éléments du tableau :" << endl;

    for (int i = 0; i < 5; ++i) {
        cout << "tab[" << i << "] = " << tab[i]
             << " | Adresse : " << &tab[i] << endl;
    }

    return 0;
}
