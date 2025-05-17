#ifndef JOB3_HPP
#define JOB3_HPP

#include <iostream>
#include <string>
using namespace std;

class Joueur {
private:
    int x;
    int y;
    string nom;

public:
    // Constructeur par défaut
    Joueur();

    // Constructeur avec position
    Joueur(int posX, int posY);

    // Constructeur avec position + nom
    Joueur(int posX, int posY, string nomJoueur);

    void afficherPosition() const;
    void afficherNom() const;

    void deplacerHaut();
    void deplacerBas();
    void deplacerGauche();
    void deplacerDroite();
};

#endif
