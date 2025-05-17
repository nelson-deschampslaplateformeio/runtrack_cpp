#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure pour stocker une destination et son temps de vol
struct Vol {
    string destination;
    float temps;
};

int main() {
    vector<Vol*> vols;
    int nombreVols;

    cout << "Combien de destinations voulez-vous saisir ? ";
    cin >> nombreVols;
    cin.ignore(); // pour vider le buffer

    // Saisie des données utilisateur
    for (int i = 0; i < nombreVols; ++i) {
        Vol* v = new Vol;
        cout << "\nDestination #" << (i + 1) << " : ";
        getline(cin, v->destination);

        cout << "Temps de vol (en heures) : ";
        cin >> v->temps;
        cin.ignore(); // vider le buffer pour getline suivant

        vols.push_back(v);
    }

    // Affichage des données
    cout << "\n--- Liste des destinations ---" << endl;
    for (size_t i = 0; i < vols.size(); ++i) {
        cout << "Destination " << (i + 1) << " : " << vols[i]->destination
             << ", Temps de vol : " << vols[i]->temps << " heures" << endl;
    }

    // Modification des données
    cout << "\nSouhaitez-vous modifier les données ? (o/n) : ";
    char reponse;
    cin >> reponse;
    cin.ignore();

    if (reponse == 'o' || reponse == 'O') {
        for (size_t i = 0; i < vols.size(); ++i) {
            cout << "\nModification pour la destination #" << (i + 1) << " : ";
            cout << "\nAncienne destination : " << vols[i]->destination << ", ancien temps : " << vols[i]->temps << " h" << endl;
            cout << "Nouvelle destination : ";
            getline(cin, vols[i]->destination);
            cout << "Nouveau temps de vol : ";
            cin >> vols[i]->temps;
            cin.ignore();
        }
    }

    // Affichage final
    cout << "\n--- Données finales ---" << endl;
    for (size_t i = 0; i < vols.size(); ++i) {
        cout << "Destination " << (i + 1) << " : " << vols[i]->destination
             << ", Temps de vol : " << vols[i]->temps << " heures" << endl;
    }

    // Libération mémoire
    for (Vol* v : vols) {
        delete v;
    }

    return 0;
}
