#include <iostream>
using namespace std;

int main() {
    float note;

    cout << "Entrez une note entre 0 et 20 : ";
    cin >> note;

    if (note < 0 || note > 20) {
        cout << "Erreur : la note doit être comprise entre 0 et 20." << endl;
    } else {
        if (note > 10) {
            cout << "Validé" << endl;
        } else {
            cout << "Non validé" << endl;
        }
    }

    return 0;
}
