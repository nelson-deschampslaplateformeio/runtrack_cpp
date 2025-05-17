#ifndef JOB8_2_HPP
#define JOB8_2_HPP

#include "job8_1.hpp"

class Chien : public Animal {
public:
    void crier() const override {
        cout << "Woof!" << endl;
    }

    void manger() const override {
        cout << "Le chien a une alimentation variée." << endl;
    }
};

#endif
