#include <iostream>

int main() {
    int a, b;

    std::cout << "Entrez le premier nombre : ";
    std::cin >> a;

    std::cout << "Entrez le deuxième nombre : ";
    std::cin >> b;

    int somme = a + b;

    std::cout << "La somme est : " << somme << std::endl;

    return 0;
}
