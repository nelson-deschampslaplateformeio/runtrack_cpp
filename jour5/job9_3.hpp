#ifndef JOB9_3_HPP
#define JOB9_3_HPP

#include "Job9_1.hpp"

class Chat : public Animal {
public:
    Chat() : Animal() {}  // appel du constructeur de Animal
    void crier() const override {
        cout << "Miaou!" << endl;
    }

    void manger() const override {
        cout << "Le chat mange du poisson." << endl;
    }
};

#endif
