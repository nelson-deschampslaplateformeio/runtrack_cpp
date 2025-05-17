#include <iostream>

int main() {
    int nombre, inverse = 0;

    std::cout << "Entrez un nombre entier : ";
    std::cin >> nombre;

    while (nombre != 0) {
        int chiffre = nombre % 10;           // Prend le dernier chiffre
        inverse = inverse * 10 + chiffre;    // Ajoute le chiffre à l’inverse
        nombre = nombre / 10;                // Supprime le dernier chiffre
    }

    std::cout << "Nombre inversé : " << inverse << std::endl;

    return 0;
}
