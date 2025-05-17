#include <iostream>

int main() {
    float prixHT, kilos, tva;

    std::cout << "Entrez le prix HT d'un kilo de carottes : ";
    std::cin >> prixHT;

    std::cout << "Entrez le nombre de kilos de carottes : ";
    std::cin >> kilos;

    std::cout << "Entrez le taux de TVA (en %) : ";
    std::cin >> tva;

    float prixTotalHT = prixHT * kilos;
    float prixTTC = prixTotalHT * (1 + tva / 100);

    std::cout << "Le prix TTC est : " << prixTTC << " euros" << std::endl;

    return 0;
}
