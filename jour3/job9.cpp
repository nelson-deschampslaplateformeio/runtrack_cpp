#include <iostream>
#include <string>
using namespace std;

// Fonction qui vérifie si s1 est inclus dans s2
bool estIncluse(const string& s1, const string& s2) {
    return s2.find(s1) != string::npos;
}

int main() {
    string chaine1, chaine2;

    cout << "Entrez la première chaîne (à chercher) : ";
    getline(cin, chaine1);

    cout << "Entrez la deuxième chaîne (où chercher) : ";
    getline(cin, chaine2);

    if (estIncluse(chaine1, chaine2)) {
        cout << "Résultat : vrai (la première chaîne est incluse)" << endl;
    } else {
        cout << "Résultat : faux (la première chaîne n'est pas incluse)" << endl;
    }

    return 0;
}
