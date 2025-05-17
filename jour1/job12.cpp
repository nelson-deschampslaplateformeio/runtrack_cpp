#include <iostream>

int main() {
    int nombre, somme = 0;

    for (int i = 1; i <= 5; ++i) {
        std::cout << "Entrez le nombre " << i << " : ";
        std::cin >> nombre;
        somme += nombre;
    }

    std::cout << "La moyenne est : " << (somme / 5.0) << std::endl;

    return 0;
}
