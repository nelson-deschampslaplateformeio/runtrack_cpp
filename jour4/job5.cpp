#include <iostream>
using namespace std;

// Déclaration de la structure
struct Point {
    int x;
    int y;
};

int main() {
    // Création d'une instance de Point
    Point p;

    // Pointeur vers la structure
    Point* ptr = &p;

    // Modification des membres via le pointeur
    ptr->x = 10;
    ptr->y = 20;

    // Affichage des valeurs modifiées
    cout << "Coordonnées du point : (" << ptr->x << ", " << ptr->y << ")" << endl;

    return 0;
}
