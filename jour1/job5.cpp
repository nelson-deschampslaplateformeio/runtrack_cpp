#include <iostream>

int main() {
    int a, b;

    std::cout << "Entrez le premier nombre : ";
    std::cin >> a;

    std::cout << "Entrez le deuxième nombre : ";
    std::cin >> b;

    int produit = a * b;

    std::cout << "Le produit est : " << produit << std::endl;

    return 0;
}
