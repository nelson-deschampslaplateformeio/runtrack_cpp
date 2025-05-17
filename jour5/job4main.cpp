#include "Job4.hpp"

int main() {
    Joueur joueur1;
    joueur1.display();

    cout << "\nModification du joueur...\n";
    joueur1.setNom("Eva");
    joueur1.setPosition(5, 7);
    joueur1.display();

    cout << "\nReset du joueur...\n";
    joueur1.reset();
    joueur1.display();

    return 0;
}
