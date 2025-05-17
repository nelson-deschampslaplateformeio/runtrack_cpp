#include <iostream>
using namespace std;

int main() {
    int n;
    double somme = 0.0;

    cout << "Entrez un entier positif n : ";
    cin >> n;

    if (n <= 0) {
        cout << "Erreur : n doit être un entier positif." << endl;
        return 1;
    }

    for (int i = 1; i <= n; ++i) {
        somme += 1.0 / i;
    }

    cout << "La somme des " << n << " premiers termes de la série harmonique est : " << somme << endl;

    return 0;
}
