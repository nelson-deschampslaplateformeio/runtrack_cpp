#include "job2.hpp"

// Constructeur par défaut
Joueur::Joueur() : x(0), y(0) {}

// Constructeur avec paramètres
Joueur::Joueur(int posX, int posY) {
    x = posX;
    y = posY;
}

void Joueur::initialiser(int posX, int posY) {
    x = posX;
    y = posY;
}

void Joueur::afficherPosition() const {
    cout << "Position : (" << x << ", " << y << ")" << endl;
}

void Joueur::deplacerHaut()    { y--; }
void Joueur::deplacerBas()     { y++; }
void Joueur::deplacerGauche()  { x--; }
void Joueur::deplacerDroite()  { x++; }
