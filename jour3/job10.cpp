#include <iostream>
#include <string>
using namespace std;

int main() {
    string saisie;
    string string2 = "Bonjour";

    cout << "Entrez une chaîne de caractères : ";
    getline(cin, saisie);

    cout << "\nChaînes triées (ordre alphabétique) : " << endl;
    if (saisie <= string2) {
        cout << saisie << endl;
        cout << string2 << endl;
    } else {
        cout << string2 << endl;
        cout << saisie << endl;
    }

    return 0;
}
