#include <iostream>
#include <string>
#include <cctype> // pour toupper

int main() {
    std::string texte = "vive la plateforme !";

    for (char &c : texte) {
        c = std::toupper(static_cast<unsigned char>(c));
    }

    std::cout << texte << std::endl;

    return 0;
}
