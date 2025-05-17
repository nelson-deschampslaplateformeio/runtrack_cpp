#include <iostream>
#include <string>

// Classe Aquatique
class Aquatique {
protected:
    double vitesse_nage; // en m/s

public:
    Aquatique(double v_nage = 0.0) : vitesse_nage(v_nage) {}

    virtual void nage() const {
        std::cout << "Je nage à " << vitesse_nage << " m/s." << std::endl;
    }
};

// Classe Terrestre
class Terrestre {
protected:
    double vitesse_marche; // en m/s

public:
    Terrestre(double v_marche = 0.0) : vitesse_marche(v_marche) {}

    virtual void marche() const {
        std::cout << "Je marche à " << vitesse_marche << " m/s." << std::endl;
    }
};

// Classe Pingouin qui hérite de Aquatique et Terrestre
class Pingouin : public Aquatique, public Terrestre {
private:
    std::string nom;

public:
    Pingouin(std::string nom, double v_nage, double v_marche)
        : Aquatique(v_nage), Terrestre(v_marche), nom(nom) {}

    void sePresenter() const {
        std::cout << "Bonjour, je suis un pingouin et je m'appelle " << nom << "." << std::endl;
    }

    // Redéfinition des méthodes
    void nage() const override {
        std::cout << nom << " nage à " << vitesse_nage << " m/s." << std::endl;
    }

    void marche() const override {
        std::cout << nom << " marche à " << vitesse_marche << " m/s." << std::endl;
    }
};

int main() {
    Pingouin p("Pingo", 2.3, 1.1);

    p.sePresenter();
    p.nage();
    p.marche();

    return 0;
}
