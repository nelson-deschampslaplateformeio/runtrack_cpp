#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 10;

    // Affichage avant échange
    cout << "Avant l'échange :" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    // Déclaration de pointeurs
    int* pA = &a;
    int* pB = &b;

    // Échange via pointeurs
    int temp = *pA;
    *pA = *pB;
    *pB = temp;

    // Affichage après échange
    cout << "Après l'échange :" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
