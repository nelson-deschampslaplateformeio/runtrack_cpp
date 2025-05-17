#ifndef JOB1_HPP
#define JOB1_HPP

#include <iostream>
using namespace std;

class Joueur {
private:
    int x;
    int y;

public:
    // Constructeur
    Joueur();

    // Méthode pour initialiser la position
    void initialiser(int posX, int posY);

    // Méthode pour afficher la position
    void afficherPosition() const;

    // Méthodes pour déplacer le joueur
    void deplacerHaut();
    void deplacerBas();
    void deplacerGauche();
    void deplacerDroite();
};

#endif
