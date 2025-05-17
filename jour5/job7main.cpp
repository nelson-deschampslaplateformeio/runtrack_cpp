#include "job7.hpp"

int main() {
    // Création d'objets Contact
    Contact c1("Alice", 12345);
    Contact c2("Bob", 67890);
    Contact c3("Charlie", 24680);

    // Copie des objets
    Contact copie1 = c1;
    Contact copie2 = c2;
    Contact copie3 = c3;

    // Modification des copies
    copie1.setNumero(11111);
    copie2.setNumero(22222);
    copie3.setNumero(33333);

    // Affichage des objets originaux
    cout << "=== Contacts originaux ===" << endl;
    c1.afficher();
    c2.afficher();
    c3.afficher();

    // Affichage des copies
    cout << "\n=== Copies modifiées ===" << endl;
    copie1.afficher();
    copie2.afficher();
    copie3.afficher();

    return 0;
}
