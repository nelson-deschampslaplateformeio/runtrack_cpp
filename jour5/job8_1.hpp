#ifndef JOB8_1_HPP
#define JOB8_1_HPP

#include <iostream>
using namespace std;

// Classe abstraite
class Animal {
public:
    virtual void crier() const = 0;   // Méthode pure
    virtual void manger() const = 0;  // Méthode pure
    virtual ~Animal() {}              // Destructeur virtuel
};

#endif
