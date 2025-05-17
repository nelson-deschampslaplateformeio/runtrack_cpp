#include <iostream>
using namespace std;

int main() {
    int tab[5] = {1, 2, 3, 4, 5};

    cout << "Contenu du tableau : ";
    for (int& valeur : tab) {  // boucle avec référence
        cout << valeur << " ";
    }

    cout << endl;
    return 0;
}
