#ifndef JOB10_3_HPP
#define JOB10_3_HPP

#include "job10_1.hpp"
#include <string>

class Chat : public Animal {
public:
    Chat() : Animal() {}

    void crier() const override {
        cout << "Miaou!" << endl;
    }

    void manger() const override {
        cout << "Le chat mange du poisson." << endl;
    }

    // Surcharge : version avec paramètre
    void manger(const string& aliment) const {
        if (aliment == "des croquettes") {
            cout << "Le chat mange des croquettes." << endl;
        } else {
            cout << "Le chat refuse de manger " << aliment << "." << endl;
        }
    }
};

#endif
