#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Entrez un entier positif : ";
    cin >> n;

    if (n < 1) {
        cout << "Erreur : veuillez entrer un entier supérieur ou égal à 1." << endl;
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " : ";

        if (i % 3 == 0 && i % 5 == 0) {
            cout << "Multiple de 3 et 5";
        } else if (i % 3 == 0) {
            cout << "Multiple de 3";
        } else if (i % 5 == 0) {
            cout << "Multiple de 5";
        } else {
            cout << "Aucun";
        }

        cout << endl;
    }

    return 0;
}
