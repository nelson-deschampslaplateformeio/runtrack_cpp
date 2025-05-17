#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Déclaration de la structure Staff
struct Staff {
    string nom;
    string prenom;
};

// Déclaration de la structure Etudiant
struct Etudiant {
    string nom;
    string prenom;
};

int main() {
    // Création et initialisation des membres du staff
    Staff staff1 = {"Cordial", "Alicia"};
    Staff staff2 = {"Malardier", "Pierre"};

    // Affichage des prénoms du staff
    cout << "Prénoms du staff :" << endl;
    cout << "- " << staff1.prenom << endl;
    cout << "- " << staff2.prenom << endl;

    // Saisie des étudiants
    int nbEtudiants;
    cout << "\nCombien d'étudiants voulez-vous ajouter ? ";
    cin >> nbEtudiants;

    vector<Etudiant> etudiants(nbEtudiants);

    for (int i = 0; i < nbEtudiants; ++i) {
        cout << "Etudiant " << i + 1 << " - Nom : ";
        cin >> etudiants[i].nom;
        cout << "Etudiant " << i + 1 << " - Prénom : ";
        cin >> etudiants[i].prenom;
    }

    // Affichage des prénoms des étudiants
    cout << "\nPrénoms des étudiants :" << endl;
    for (const auto& etu : etudiants) {
        cout << "- " << etu.prenom << endl;
    }

    return 0;
}
