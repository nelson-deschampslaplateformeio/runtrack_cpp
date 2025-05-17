#include <iostream>
#include <cstring> // pour strlen
using namespace std;

int main() {
    char saisie[100]; // buffer pour l'entrée utilisateur
    char tab[100];    // tableau pour stocker les lettres

    cout << "Entrez une chaîne de caractères : ";
    cin.getline(saisie, 100); // lecture avec espaces

    // Copier les lettres dans tab, caractère par caractère
    int i = 0;
    while (saisie[i] != '\0') {
        tab[i] = saisie[i];
        i++;
    }

    // Ajout du caractère de fin de chaîne
    tab[i] = '\0';

    // Affichage lettre par lettre
    cout << "Contenu du tableau tab : ";
    for (int j = 0; tab[j] != '\0'; j++) {
        cout << tab[j];
    }

    cout << endl;
    return 0;
}
