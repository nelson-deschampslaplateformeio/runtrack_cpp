#include <iostream>
#include <string>
using namespace std;

int main() {
    int entier = 17;
    float flottant = 3.14f;
    double reel = 123.345;
    string caractere = "La Plateforme";

    cout << "Valeur de entier : " << entier << ", Adresse : " << &entier << endl;
    cout << "Valeur de flottant : " << flottant << ", Adresse : " << &flottant << endl;
    cout << "Valeur de reel : " << reel << ", Adresse : " << &reel << endl;
    cout << "Valeur de caractere : " << caractere << ", Adresse : " << &caractere << endl;

    return 0;
}
