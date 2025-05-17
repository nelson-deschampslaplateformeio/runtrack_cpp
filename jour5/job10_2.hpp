#ifndef JOB10_2_HPP
#define JOB10_2_HPP

#include "job10_1.hpp"

class Chien : public Animal {
public:
    Chien() : Animal() {}

    void crier() const override {
        cout << "Woof!" << endl;
    }

    void manger() const override {
        cout << "Le chien a une alimentation variée." << endl;
    }
};

#endif
