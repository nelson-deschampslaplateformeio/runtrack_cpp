#ifndef JOB7_HPP
#define JOB7_HPP

#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string nom;
    int numero;

public:
    // Constructeur standard
    Contact(string nom, int numero) : nom(nom), numero(numero) {}

    // Constructeur de copie
    Contact(const Contact& autre) {
        this->nom = autre.nom;
        this->numero = autre.numero;
    }

    // Méthode pour modifier le numéro
    void setNumero(int nouveauNumero) {
        this->numero = nouveauNumero;
    }

    // Méthode pour afficher les infos
    void afficher() const {
        cout << "Nom : " << nom << ", Numéro : " << numero << endl;
    }
};

#endif
