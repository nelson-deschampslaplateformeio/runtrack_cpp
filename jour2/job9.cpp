#include <iostream>
using namespace std;

int main() {
    int a, b, x;

    // Saisie des bornes a et b avec vérification que a < b
    cout << "Entrez la valeur de a (borne inférieure) : ";
    cin >> a;

    cout << "Entrez la valeur de b (borne supérieure) : ";
    cin >> b;

    if (a >= b) {
        cout << "Erreur : a doit être inférieur à b." << endl;
        return 1;
    }

    // Saisie de l'entier à tester
    cout << "Entrez un entier : ";
    cin >> x;

    // Vérification de l'appartenance à l'intervalle
    if (x >= a && x <= b) {
        cout << "GAGNE" << endl;
    } else {
        cout << "PERDU" << endl;
    }

    return 0;
}
