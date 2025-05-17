#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int nombre, original, reste, somme = 0;
    int n = 0;

    cout << "Entrez un entier : ";
    cin >> nombre;

    original = nombre;

    // Compter le nombre de chiffres
    int temp = nombre;
    while (temp != 0) {
        temp /= 10;
        n++;
    }

    // Calculer la somme des puissances des chiffres
    temp = nombre;
    while (temp != 0) {
        reste = temp % 10;
        somme += pow(reste, n);
        temp /= 10;
    }

    // Vérification
    if (somme == original) {
        cout << original << " est un nombre narcissique." << endl;
    } else {
        cout << original << " n'est pas un nombre narcissique." << endl;
    }

    return 0;
}
