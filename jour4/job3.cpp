#include <iostream>
#include <cstring> // pour strlen
using namespace std;

int main() {
    char chaine[100];

    cout << "Entrez une chaine de caracteres : ";
    cin.getline(chaine, 100); // lire la chaîne avec espaces si nécessaire

    // Définir deux pointeurs
    char* debut = chaine;
    char* fin = chaine + strlen(chaine) - 1;

    // Inverser la chaîne avec les pointeurs
    while (debut < fin) {
        char temp = *debut;
        *debut = *fin;
        *fin = temp;
        debut++;
        fin--;
    }

    cout << "Chaine inversee : " << chaine << endl;

    return 0;
}
