#include "job10_2.hpp"
#include "job10_3.hpp"

int main() {
    Chien chien1;
    Chat chat1;

    cout << "--- Chien ---" << endl;
    chien1.crier();
    chien1.manger();

    cout << "\n--- Chat ---" << endl;
    chat1.crier();
    chat1.manger();  // Appel sans paramètre (héritée d'Animal)
    chat1.manger("des croquettes"); // Appel avec paramètre
    chat1.manger("du chocolat");    // Autre cas

    cout << "\nTotal d'animaux créés : " << Animal::getTotalAnimaux() << endl;

    return 0;
}
