#ifndef JOB5_HPP
#define JOB5_HPP

#include <string>
#include <iostream>
using namespace std;

class Etudiant {
private:
    string nom;
    string prenom;
    int age;
    int matricule;

public:
    // Constructeur avec liste d'initialisation
    Etudiant(string nom, string prenom, int age, int matricule)
        : nom(nom), prenom(prenom), age(age), matricule(matricule) {}

    // Méthode pour afficher les informations de l'étudiant
    void afficherInfos() const {
        cout << "Nom       : " << nom << endl;
        cout << "Prénom    : " << prenom << endl;
        cout << "Âge       : " << age << " ans" << endl;
        cout << "Matricule : " << matricule << endl;
    }
};

#endif
