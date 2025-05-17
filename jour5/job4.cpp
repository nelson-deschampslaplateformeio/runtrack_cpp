#include "Job4.hpp"

// Constructeurs
Joueur::Joueur() : x(0), y(0), nom("Anonyme") {}

Joueur::Joueur(int x, int y) {
    this->x = x;
    this->y = y;
    this->nom = "Anonyme";
}

Joueur::Joueur(int x, int y, string nom) {
    this->x = x;
    this->y = y;
    this->nom = nom;
}

// Méthodes utilisant "this"
void Joueur::setNom(string nom) {
    this->nom = nom;
}

void Joueur::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void Joueur::reset() {
    this->x = 0;
    this->y = 0;
    this->nom = "Anonyme";
}

void Joueur::display() const {
    cout << "Nom      : " << this->nom << endl;
    cout << "Position : (" << this->x << ", " << this->y << ")" << endl;
}
