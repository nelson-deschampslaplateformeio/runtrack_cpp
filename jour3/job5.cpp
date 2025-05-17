#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool formatHeureValide(const string& heure) {
    // Vérifier que la longueur est exactement 5 caractères
    if (heure.length() != 5)
        return false;

    // Vérifier le format : chiffres, 'h', chiffres
    return isdigit(heure[0]) && isdigit(heure[1]) &&
           heure[2] == 'h' &&
           isdigit(heure[3]) && isdigit(heure[4]);
}

int main() {
    string saisie;

    cout << "Entrez une heure au format XXhXX : ";
    cin >> saisie;

    if (formatHeureValide(saisie)) {
        cout << "Format valide." << endl;
    } else {
        cout << "Format invalide. Exemple attendu : 14h30" << endl;
    }

    return 0;
}
