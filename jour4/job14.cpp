#include <iostream>
using namespace std;

int main() {
    int x = 12;

    // Création d'une référence à x
    int& ref = x;

    // Modification de x via la référence
    ref = 25;

    // Affichage de la nouvelle valeur de x
    cout << "La valeur de x est : " << x << endl;

    return 0;
}
