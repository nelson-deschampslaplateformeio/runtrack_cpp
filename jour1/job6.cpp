#include <iostream>

int main() {
    int nombre;

    std::cout << "Entrez un entier : ";
    std::cin >> nombre;

    std::cout << "Table de multiplication de " << nombre << " :" << std::endl;

    for (int i = 1; i <= 10; ++i) {
        std::cout << nombre << " x " << i << " = " << nombre * i << std::endl;
    }

    return 0;
}
