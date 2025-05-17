#ifndef JOB2_HPP
#define JOB2_HPP

#include <iostream>
using namespace std;

class Joueur {
private:
    int x;
    int y;

public:
    Joueur();                      // Constructeur par défaut
    Joueur(int posX, int posY);    // ✅ Constructeur avec paramètres

    void initialiser(int posX, int posY);
    void afficherPosition() const;

    void deplacerHaut();
    void deplacerBas();
    void deplacerGauche();
    void deplacerDroite();
};

#endif
