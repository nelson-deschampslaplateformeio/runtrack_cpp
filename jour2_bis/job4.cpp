#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

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
class Pingouin : public Aquatique, public Terrestre, public std::enable_shared_from_this<Pingouin> {
private:
    std::string nom;
    double vitesse_glisse;

public:
    // Vector statique contenant tous les pingouins créés
    static std::vector<std::shared_ptr<Pingouin>> tous_les_pingouins;

    // Constructeur principal
    Pingouin(const std::string& nom, double v_nage, double v_marche, double v_glisse)
        : Aquatique(v_nage), Terrestre(v_marche), nom(nom), vitesse_glisse(v_glisse) {
        std::cout << "Pingouin " << nom << " créé." << std::endl;
    }

    // Constructeur de copie
    Pingouin(const Pingouin& other)
        : Aquatique(other.vitesse_nage),
          Terrestre(other.vitesse_marche),
          nom(other.nom),
          vitesse_glisse(other.vitesse_glisse) {
        std::cout << "Constructeur de copie appelé pour " << nom << std::endl;
    }

    // Destructeur
    ~Pingouin() {
        auto it = std::remove_if(tous_les_pingouins.begin(), tous_les_pingouins.end(),
                                 [this](const std::shared_ptr<Pingouin>& p) {
                                     return p.get() == this;
                                 });
        tous_les_pingouins.erase(it, tous_les_pingouins.end());
        std::cout << "Pingouin " << nom << " détruit." << std::endl;
    }

    // Méthode pour créer un pingouin via shared_ptr
    static std::shared_ptr<Pingouin> creer(const std::string& nom, double v_nage, double v_marche, double v_glisse) {
        auto ptr = std::make_shared<Pingouin>(nom, v_nage, v_marche, v_glisse);
        tous_les_pingouins.push_back(ptr);
        return ptr;
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

    // Calcul du temps de parcours
    double tempsParcours() const {
        double temps = 0.0;

        if (vitesse_glisse > 0) temps += 15.0 / vitesse_glisse;
        if (vitesse_marche > 0) temps += 20.0 / vitesse_marche;
        if (vitesse_nage > 0) temps += 50.0 / vitesse_nage;
        if (vitesse_marche > 0) temps += 15.0 / vitesse_marche;

        return temps;
    }

    // Méthode statique pour afficher les temps de tous les pingouins
    static void afficherTousLesTemps() {
        std::cout << "\n--- Temps de parcours de tous les pingouins ---" << std::endl;
        for (const auto& p : tous_les_pingouins) {
            std::cout << p->nom << " : " << p->tempsParcours() << " secondes" << std::endl;
        }
    }
};

// Initialisation du vector statique
std::vector<std::shared_ptr<Pingouin>> Pingouin::tous_les_pingouins;

int main() {
    {
        auto p1 = Pingouin::creer("Pingo", 2.0, 1.0, 3.5);
        auto p2 = Pingouin::creer("Tux", 1.8, 0.9, 3.0);

        p1->sePresenter();
        p2->sePresenter();

        Pingouin::afficherTousLesTemps();
    }

    std::cout << "\nAprès destruction automatique des pingouins : "
              << Pingouin::tous_les_pingouins.size()
              << " pingouin(s) restants." << std::endl;

    return 0;
}
