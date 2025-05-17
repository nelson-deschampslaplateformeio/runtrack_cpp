#include "Job1.hpp"

// Constructeur
Joueur::Joueur() : x(0), y(0) {}

// Initialisation
void Joueur::initialiser(int posX, int posY) {
    x = posX;
    y = posY;
}

// Affichage de la position
void Joueur::afficherPosition() const {
    cout << "Position du joueur : (" << x << ", " << y << ")" << endl;
}

// Déplacements
void Joueur::deplacerHaut() {
    y--;
}

void Joueur::deplacerBas() {
    y++;
}

void Joueur::deplacerGauche() {
    x--;
}

void Joueur::deplacerDroite() {
    x++;
}
