#include "Job3.hpp"

// Constructeur par défaut
Joueur::Joueur() : x(0), y(0), nom("Anonyme") {}

// Constructeur avec position
Joueur::Joueur(int posX, int posY) : x(posX), y(posY), nom("Anonyme") {}

// Constructeur avec position et nom
Joueur::Joueur(int posX, int posY, string nomJoueur) : x(posX), y(posY), nom(nomJoueur) {}

void Joueur::afficherPosition() const {
    cout << "Position : (" << x << ", " << y << ")" << endl;
}

void Joueur::afficherNom() const {
    cout << "Nom du joueur : " << nom << endl;
}

void Joueur::deplacerHaut()    { y--; }
void Joueur::deplacerBas()     { y++; }
void Joueur::deplacerGauche()  { x--; }
void Joueur::deplacerDroite()  { x++; }
