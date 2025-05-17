#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Etudiant {
    string nom;
    string prenom;
    float note;
};

// Fonction pour afficher le menu
void afficherMenu() {
    cout << "\nMenu :" << endl;
    cout << "1. Ajouter une note" << endl;
    cout << "2. Afficher la liste de notes" << endl;
    cout << "3. Supprimer une note d'un étudiant" << endl;
    cout << "4. Afficher la moyenne des notes" << endl;
    cout << "5. Quitter" << endl;
    cout << "Choix : ";
}

int main() {
    vector<Etudiant> liste;
    int choix;

    do {
        afficherMenu();
        cin >> choix;

        switch (choix) {
            case 1: {
                Etudiant e;
                cout << "Nom : ";
                cin >> e.nom;
                cout << "Prénom : ";
                cin >> e.prenom;
                cout << "Note : ";
                cin >> e.note;
                liste.push_back(e);
                break;
            }

            case 2: {
                if (liste.empty()) {
                    cout << "Aucune note enregistrée." << endl;
                } else {
                    cout << "\nListe des notes :" << endl;
                    for (const auto& e : liste) {
                        cout << e.nom << " " << e.prenom << " : " << fixed << setprecision(2) << e.note << endl;
                    }
                }
                break;
            }

            case 3: {
                string nom, prenom;
                cout << "Nom de l'étudiant à supprimer : ";
                cin >> nom;
                cout << "Prénom : ";
                cin >> prenom;
                bool trouve = false;

                for (auto it = liste.begin(); it != liste.end(); ++it) {
                    if (it->nom == nom && it->prenom == prenom) {
                        liste.erase(it);
                        cout << "Note supprimée." << endl;
                        trouve = true;
                        break;
                    }
                }

                if (!trouve) {
                    cout << "Étudiant non trouvé." << endl;
                }
                break;
            }

            case 4: {
                if (liste.empty()) {
                    cout << "Aucune note pour calculer la moyenne." << endl;
                } else {
                    float somme = 0;
                    for (const auto& e : liste) {
                        somme += e.note;
                    }
                    float moyenne = somme / liste.size();
                    cout << "Moyenne des notes : " << fixed << setprecision(2) << moyenne << endl;
                }
                break;
            }

            case 5:
                cout << "Au revoir !" << endl;
                break;

            default:
                cout << "Choix invalide. Réessayez." << endl;
        }
    } while (choix != 5);

    return 0;
}
