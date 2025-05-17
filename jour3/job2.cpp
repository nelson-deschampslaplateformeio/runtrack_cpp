#include <iostream>
#include <string>
using namespace std;

bool estVoyelle(char c) {
    c = tolower(c); // rendre la lettre minuscule
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
    string texte = "vive la plateforme !";
    string resultat = "";

    for (char c : texte) {
        if (!estVoyelle(c)) {
            resultat += c;
        }
    }

    cout << "Texte sans voyelles : " << resultat << endl;

    return 0;
}
