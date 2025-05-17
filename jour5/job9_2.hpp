#ifndef JOB9_2_HPP
#define job9_2_HPP

#include "job9_1.hpp"

class Chien : public Animal {
public:
    Chien() : Animal() {}  // appel du constructeur de Animal pour incrémenter
    void crier() const override {
        cout << "Woof!" << endl;
    }

    void manger() const override {
        cout << "Le chien a une alimentation variée." << endl;
    }
};

#endif
