#ifndef JOB11_HPP
#define JOB11_HPP

#include <iostream>
using namespace std;

class Operation {
private:
    double valeur;

public:
    Operation(double val = 0) : valeur(val) {}

    // Accesseur
    double getValeur() const {
        return valeur;
    }

    // Surcharge opérateur +
    Operation operator+(const Operation& autre) const {
        return Operation(this->valeur + autre.valeur);
    }

    // Surcharge opérateur -
    Operation operator-(const Operation& autre) const {
        return Operation(this->valeur - autre.valeur);
    }

    // Surcharge opérateur *
    Operation operator*(const Operation& autre) const {
        return Operation(this->valeur * autre.valeur);
    }

    // Surcharge opérateur /
    Operation operator/(const Operation& autre) const {
        if (autre.valeur == 0) {
            cerr << "Erreur : division par zéro !" << endl;
            return Operation(0);
        }
        return Operation(this->valeur / autre.valeur);
    }

    // Affichage
    void afficher() const {
        cout << "Résultat : " << valeur << endl;
    }
};

#endif
