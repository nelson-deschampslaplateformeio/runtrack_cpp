#include <iostream>
#include <string>

// Classe Aquatique
class Aquatique {
protected:
    double vitesse_nage;

public:
    Aquatique(double v_nage = 0.0) : vitesse_nage(v_nage) {}

    virtual void nage() const {
        std::cout << "Je nage à " << vitesse_nage << " m/s." << std::endl;
    }

    void setVitesseNage(double v) {
        vitesse_nage = v;
    }
};

// Classe Terrestre
class Terrestre {
protected:
    double vitesse_marche;

public:
    Terrestre(double v_marche = 0.0) : vitesse_marche(v_marche) {}

    virtual void marche() const {
        std::cout << "Je marche à " << vitesse_marche << " m/s." << std::endl;
    }

    void setVitesseMarche(double v) {
        vitesse_marche = v;
    }
};

// Classe Pingouin
class Pingouin : public Aquatique, public Terrestre {
private:
    std::string nom;
    double vitesse_glisse;

public:
    // Constructeur principal
    Pingouin(std::string nom, double v_nage, double v_marche, double v_glisse)
        : Aquatique(v_nage), Terrestre(v_marche), nom(nom), vitesse_glisse(v_glisse) {}

    // Constructeur de copie
    Pingouin(const Pingouin& other)
        : Aquatique(other.vitesse_nage), Terrestre(other.vitesse_marche),
          nom(other.nom), vitesse_glisse(other.vitesse_glisse) {
        std::cout << "Constructeur de copie appelé pour " << nom << std::endl;
    }

    void sePresenter() const {
        std::cout << "Bonjour, je suis un pingouin et je m'appelle " << nom << "." << std::endl;
    }

    void nage() const override {
        std::cout << nom << " nage à " << vitesse_nage << " m/s." << std::endl;
    }

    void marche() const override {
        std::cout << nom << " marche à " << vitesse_marche << " m/s." << std::endl;
    }

    void glisse() const {
        std::cout << nom << " glisse à " << vitesse_glisse << " m/s." << std::endl;
    }

    // Méthode pour modifier la vitesse de glisse
    void setVitesseGlisse(double v) {
        vitesse_glisse = v;
    }
};

int main() {
    Pingouin p1("Pingo", 2.3, 1.1, 3.5);

    p1.sePresenter();
    p1.nage();
    p1.marche();
    p1.glisse();

    std::cout << "\n--- Création d'une copie ---" << std::endl;
    Pingouin p2 = p1;  // Appel du constructeur de copie
    p2.setVitesseGlisse(4.0);
    p2.glisse();

    return 0;
}
