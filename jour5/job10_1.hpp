#ifndef JOB10_1_HPP
#define JOB10_1_HPP

#include <iostream>
using namespace std;

class Animal {
protected:
    static int totalAnimaux;

public:
    Animal() { totalAnimaux++; }
    virtual ~Animal() {}

    virtual void crier() const = 0;
    virtual void manger() const = 0;

    static int getTotalAnimaux();
};

#endif
