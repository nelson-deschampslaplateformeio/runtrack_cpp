#include "job11.hpp"

int main() {
    Operation a(10);
    Operation b(5);

    Operation somme = a + b;
    Operation difference = a - b;
    Operation produit = a * b;
    Operation quotient = a / b;

    cout << "--- Opérations ---" << endl;
    somme.afficher();       // 15
    difference.afficher();  // 5
    produit.afficher();     // 50
    quotient.afficher();    // 2

    return 0;
}
