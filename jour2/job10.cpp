#include <iostream>
#include <cmath> // pour sqrt
using namespace std;

int main() {
    double nombre;

    while (true) {
        cout << "donnez un nombre positif : ";
        cin >> nombre;

        if (nombre == 0) {
            break; // arrêt du programme
        }

        if (nombre < 0) {
            cout << "svp positif" << endl;
            continue;
        }

        // Calcul et affichage de la racine carrée
        cout << "sa racine carree est : " << sqrt(nombre) << endl;
    }

    return 0;
}
