#include "job9_1.hpp"
#include "job9_2.hpp"
#include "job9_3.hpp"

int main() {
    Chien chien1, chien2;
    Chat chat1, chat2, chat3;

    cout << "\n=== Test des animaux ===" << endl;
    chien1.crier(); chien1.manger();
    chat1.crier(); chat1.manger();

    cout << "\nNombre total d'animaux créés : "
         << Animal::getTotalAnimaux() << endl;

    return 0;
}
