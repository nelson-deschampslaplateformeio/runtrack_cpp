#include <iostream>
using namespace std;

int main() {
    // Déclaration des variables
    int a = 10, b = 20, c = 30;

    // Affichage initial
    cout << "Avant modification :" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    // Déclaration des pointeurs
    int* pA = &a;
    int* pB = &b;
    int* pC = &c;

    // Modification des valeurs via pointeurs
    *pA = 100;
    *pB = 200;
    *pC = 300;

    // Affichage après modification
    cout << "Après modification via pointeurs :" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}
