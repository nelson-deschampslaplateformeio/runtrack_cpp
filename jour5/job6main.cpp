#include "job6.hpp"

int main() {
    // Création de différents types de personnages
    Personne guerrier("Guerrier", 150, 0.2f);
    Personne mage("Mage", 80, 0.1f);
    Personne voleur("Voleur", 100, 0.15f);

    cout << "=== Informations initiales ===" << endl;
    guerrier.afficherInfos();
    cout << endl;
    mage.afficherInfos();
    cout << endl;
    voleur.afficherInfos();

    cout << "\n=== Le mage subit 50 dégâts ===" << endl;
    mage.subirDegats(50);
    mage.afficherInfos();

    cout << "\n=== Le guerrier améliore sa défense ===" << endl;
    guerrier.setDefense(0.3f);
    guerrier.afficherInfos();

    return 0;
}
