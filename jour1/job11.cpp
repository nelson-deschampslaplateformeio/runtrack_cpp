#include <iostream>

int main() {
    int n, m, temp;

    std::cout << "Entrez la valeur de n : ";
    std::cin >> n;

    std::cout << "Entrez la valeur de m : ";
    std::cin >> m;

    std::cout << "\nAvant l'échange : n = " << n << ", m = " << m << std::endl;

    // Échange des valeurs avec une variable temporaire
    temp = n;
    n = m;
    m = temp;

    std::cout << "Après l'échange : n = " << n << ", m = " << m << std::endl;

    return 0;
}
