#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

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

class Pingouin : public Aquatique, public Terrestre, public std::enable_shared_from_this<Pingouin> {
private:
    std::string nom;
    double vitesse_glisse;

public:
    static std::vector<std::shared_ptr<Pingouin>> tous_les_pingouins;

    Pingouin(const std::string& nom, double v_nage, double v_marche, double v_glisse)
        : Aquatique(v_nage), Terrestre(v_marche), nom(nom), vitesse_glisse(v_glisse) {
        // Ajout différé : fait par une fabrique ou après shared_from_this()
        std::cout << "Pingouin " << nom << " créé." << std::endl;
    }

    ~Pingouin() {
        // Retirer ce pingouin du vector (si toujours présent)
        auto it = std::remove_if(tous_les_pingouins.begin(), tous_les_pingouins.end(),
            [this](const std::shared_ptr<Pingouin>& p) {
                return p.get() == this;
            });
        tous_les_pingouins.erase(it, tous_les_pingouins.end());

        std::cout << "Pingouin " << nom << " détruit." << std::endl;
    }

    void sePresenter() const {
        std::cout << "Bonjour, je suis un pingouin nommé " << nom << "." << std::endl;
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

    void setVitesseGlisse(double v) {
        vitesse_glisse = v;
    }

    // Fabrique sécurisée pour s’assurer que shared_from_this fonctionne
    static std::shared_ptr<Pingouin> creer(const std::string& nom, double v_nage, double v_marche, double v_glisse) {
        std::shared_ptr<Pingouin> p = std::make_shared<Pingouin>(nom, v_nage, v_marche, v_glisse);
        tous_les_pingouins.push_back(p);
        return p;
    }
};

// Initialisation du vector statique
std::vector<std::shared_ptr<Pingouin>> Pingouin::tous_les_pingouins;

int main() {
    {
        auto p1 = Pingouin::creer("Pingo", 2.0, 1.0, 3.5);
        auto p2 = Pingouin::creer("Tux", 1.8, 0.9, 3.0);

        for (const auto& p : Pingouin::tous_les_pingouins) {
            p->sePresenter();
        }

        std::cout << "Nombre de pingouins en mémoire : " << Pingouin::tous_les_pingouins.size() << std::endl;
    }

    // Après destruction automatique de p1 et p2 (fin du bloc)
    std::cout << "Après destruction : " << Pingouin::tous_les_pingouins.size() << " pingouins restants." << std::endl;

    return 0;
}
