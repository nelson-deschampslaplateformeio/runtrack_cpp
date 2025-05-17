#include <iostream>
using namespace std;

int main() {
    int limite;

    cout << "Entrez la limite supérieure : ";
    cin >> limite;

    if (limite < 0) {
        cout << "Erreur : la limite doit être un entier positif." << endl;
        return 1;
    }

    int a = 0, b = 1;

    cout << "Suite de Fibonacci jusqu'à " << limite << " : " << endl;
    
    if (limite >= 0) cout << a << " ";
    if (limite >= 1) cout << b << " ";

    int suivant = a + b;

    while (suivant <= limite) {
        cout << suivant << " ";
        a = b;
        b = suivant;
        suivant = a + b;
    }

    cout << endl;
    return 0;
}
