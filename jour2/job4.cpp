#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operateur;

    cout << "Entrez le premier nombre : ";
    cin >> num1;

    cout << "Entrez un opérateur (+, -, *, /) : ";
    cin >> operateur;

    cout << "Entrez le deuxième nombre : ";
    cin >> num2;

    switch (operateur) {
        case '+':
            cout << "Résultat : " << (num1 + num2) << endl;
            break;
        case '-':
            cout << "Résultat : " << (num1 - num2) << endl;
            break;
        case '*':
            cout << "Résultat : " << (num1 * num2) << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "Résultat : " << (num1 / num2) << endl;
            else
                cout << "Erreur : division par zéro !" << endl;
            break;
        default:
            cout << "Opérateur invalide !" << endl;
    }

    return 0;
}
