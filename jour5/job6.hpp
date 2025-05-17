#ifndef JOB6_HPP
#define JOB6_HPP

#include <iostream>
#include <string>
using namespace std;

class Personne {
private:
    string nom;
    int pointsDeVie;
    float defense;

public:
    // Constructeur avec liste d'initialisation
    Personne(string nom, int pdv, float def)
        : nom(nom), pointsDeVie(pdv), defense(def) {}

    // Méthodes d'affichage
    void afficherInfos() const {
        cout << "Nom          : " << nom << endl;
        cout << "Points de vie: " << pointsDeVie << endl;
        cout << "Défense      : " << defense << endl;
    }

    // Méthodes de modification
    void setNom(string nouveauNom) {
        this->nom = nouveauNom;
    }

    void setPointsDeVie(int pdv) {
        this->pointsDeVie = pdv;
    }

    void setDefense(float def) {
        this->defense = def;
    }

    // Exemple de logique de jeu : infliger des dégâts
    void subirDegats(int degats) {
        int degatsEffectifs = static_cast<int>(degats * (1.0f - defense));
        pointsDeVie -= degatsEffectifs;
        if (pointsDeVie < 0) pointsDeVie = 0;
    }
};

#endif
