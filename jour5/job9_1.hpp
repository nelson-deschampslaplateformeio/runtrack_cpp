#ifndef JOB9_1_HPP
#define JOB9_1_HPP

#include <iostream>
using namespace std;

class Animal {
protected:
    static int totalAnimaux;  // membre statique partagé

public:
    Animal() { totalAnimaux++; }     // constructeur de base
    virtual ~Animal() {}             // destructeur virtuel

    virtual void crier() const = 0;
    virtual void manger() const = 0;

    static int getTotalAnimaux();    // méthode pour accéder au total
};

#endif
