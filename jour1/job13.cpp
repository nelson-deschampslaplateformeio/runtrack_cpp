#include <iostream>

int main() {
    int N;
    long long somme = 0; // Utiliser long long pour éviter les débordements si N est grand

    std::cout << "Entrez un entier N (≥ 5) : ";
    std::cin >> N;

    if (N < 5) {
        std::cout << "Erreur : N doit être supérieur ou égal à 5." << std::endl;
        return 1;
    }

    for (int i = 5; i <= N; ++i) {
        somme += static_cast<long long>(i) * i * i; // i^3
    }

    std::cout << "La somme des cubes de 5^3 à " << N << "^3 est : " << somme << std::endl;

    return 0;
}
