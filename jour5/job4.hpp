#ifndef JOB4_HPP
#define JOB4_HPP

#include <iostream>
#include <string>
using namespace std;

class Joueur {
private:
    int x;
    int y;
    string nom;

public:
    // Constructeurs
    Joueur();
    Joueur(int x, int y);
    Joueur(int x, int y, string nom);

    // Méthodes utilisant this
    void setNom(string nom);
    void setPosition(int x, int y);
    void reset();
    void display() const;
};

#endif
