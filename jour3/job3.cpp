#include <iostream>
#include <string>
using namespace std;

int main() {
    string chaine1, chaine2;

    cout << "Entrez la première chaîne : ";
    getline(cin, chaine1);

    cout << "Entrez la deuxième chaîne : ";
    getline(cin, chaine2);

    if (chaine1 == chaine2) {
        cout << "Résultat : 0 (les chaînes sont égales)" << endl;
        return 0;
    } else {
        cout << "Résultat : 1 (les chaînes sont différentes)" << endl;
        return 1;
    }
}
