#include <iostream>
#include <string>
using namespace std;

// Structure pour regrouper différents types
struct Donnees {
    int entier;
    string texte1;
    float reel;
    string texte2;
};

int main() {
    Donnees data = {2019, "La Plateforme", 3.14f, "Étudiants"};

    // Affichage des valeurs et adresses
    cout << "entier : " << data.entier << " | Adresse : " << &data.entier << endl;
    cout << "texte1 : " << data.texte1 << " | Adresse : " << &data.texte1 << endl;
    cout << "reel   : " << data.reel   << " | Adresse : " << &data.reel << endl;
    cout << "texte2 : " << data.texte2 << " | Adresse : " << &data.texte2 << endl;

    return 0;
}
