#ifndef JOB8_3_HPP
#define JOB8_3_HPP

#include "job8_1.hpp"

class Chat : public Animal {
public:
    void crier() const override {
        cout << "Miaou!" << endl;
    }

    void manger() const override {
        cout << "Le chat mange du poisson." << endl;
    }
};

#endif
