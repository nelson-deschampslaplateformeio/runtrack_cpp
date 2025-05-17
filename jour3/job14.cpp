#include <iostream>
#include <string>
using namespace std;

// Fonction qui vérifie si une chaîne est un palindrome
bool estPalindrome(const string& mot) {
    int gauche = 0;
    int droite = mot.length() - 1;

    while (gauche < droite) {
        if (mot[gauche] != mot[droite]) {
            return false;
        }
        gauche++;
        droite--;
    }
    return true;
}

int main() {
    // Tableau de mots
    string tab[] = {"radar", "hello", "lvel", "stats", "world"};
    int taille = sizeof(tab) / sizeof(tab[0]);

    cout << "Palindromes trouvés dans le tableau : " << endl;
    for (int i = 0; i < taille; ++i) {
        if (estPalindrome(tab[i])) {
            cout << "- " << tab[i] << endl;
        }
    }

    return 0;
}
