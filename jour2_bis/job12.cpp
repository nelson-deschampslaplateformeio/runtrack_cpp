#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <memory>
#include <algorithm>
#include <random>

class Aquatique {
protected:
    double vitesse_nage;

public:
    Aquatique(double v_nage = 0.0) : vitesse_nage(v_nage) {}
    virtual void nage() const {
        std::cout << "Je nage à " << vitesse_nage << " m/s." << std::endl;
    }
    void setVitesseNage(double v) { vitesse_nage = v; }
};

class Terrestre {
protected:
    double vitesse_marche;

public:
    Terrestre(double v_marche = 0.0) : vitesse_marche(v_marche) {}
    virtual void marche() const {
        std::cout << "Je marche à " << vitesse_marche << " m/s." << std::endl;
    }
    void setVitesseMarche(double v) { vitesse_marche = v; }
};

class Pingouin : public Aquatique, public Terrestre, public std::enable_shared_from_this<Pingouin> {
private:
    std::string nom;
    double vitesse_glisse;
    std::map<std::string, int> competences;
    std::unordered_map<std::string, std::string> journal;
    std::set<std::weak_ptr<Pingouin>, std::owner_less<std::weak_ptr<Pingouin>>> amis;
    std::multiset<double> temps_competitions;
    std::unordered_set<std::string> emplacements_tresors;

public:
    static std::vector<std::shared_ptr<Pingouin>> colony;
    static std::list<std::string> lieux_rencontre;
    static std::unordered_map<std::string, std::string> lieux_tresors;

    Pingouin(const std::string& nom, double v_nage, double v_marche, double v_glisse)
        : Aquatique(v_nage), Terrestre(v_marche), nom(nom), vitesse_glisse(v_glisse) {
        std::cout << "Pingouin " << nom << " créé." << std::endl;
    }

    ~Pingouin() {
        auto it = std::remove_if(colony.begin(), colony.end(),
                                 [this](const std::shared_ptr<Pingouin>& p) {
                                     return p.get() == this;
                                 });
        colony.erase(it, colony.end());
        std::cout << "Pingouin " << nom << " détruit." << std::endl;
    }

    static std::shared_ptr<Pingouin> creer(const std::string& nom, double v_nage, double v_marche, double v_glisse) {
        auto ptr = std::make_shared<Pingouin>(nom, v_nage, v_marche, v_glisse);
        colony.push_back(ptr);
        std::sort(colony.begin(), colony.end(),
                  [](const std::shared_ptr<Pingouin>& a, const std::shared_ptr<Pingouin>& b) {
                      return a->tempsParcours() < b->tempsParcours();
                  });
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

    void setVitesseGlisse(double v) { vitesse_glisse = v; }

    double tempsParcours() const {
        double temps = 0.0;
        if (vitesse_glisse > 0) temps += 15.0 / vitesse_glisse;
        if (vitesse_marche > 0) temps += 20.0 / vitesse_marche;
        if (vitesse_nage > 0)   temps += 50.0 / vitesse_nage;
        if (vitesse_marche > 0) temps += 15.0 / vitesse_marche;
        return temps;
    }

    static void afficherTousLesTemps() {
        std::cout << "\n--- Temps de parcours de tous les pingouins (triés) ---\n";
        for (const auto& p : colony) {
            std::cout << p->nom << " : " << p->tempsParcours() << " secondes\n";
        }
    }

    void ajouterEmplacementTresor(const std::string& lieu) {
        emplacements_tresors.insert(lieu);
        std::cout << nom << " a découvert un trésor à : " << lieu << std::endl;
    }

    void afficherEmplacementsTresors() const {
        std::cout << "\nTrésors connus de " << nom << " :" << std::endl;
        if (emplacements_tresors.empty()) {
            std::cout << "(Aucun trésor découvert)" << std::endl;
        } else {
            for (const auto& t : emplacements_tresors) {
                std::cout << "- " << t << std::endl;
            }
        }
    }

    // Nouvelle méthode : aller à un lieu et tenter de trouver un trésor
    void seRendreAuLieu(const std::string& lieu) {
        std::cout << nom << " se rend à " << lieu << "..." << std::endl;
        auto it = lieux_tresors.find(lieu);
        if (it != lieux_tresors.end()) {
            // Lieu contient un trésor
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(0, 1); // 50 % de chance
            if (dist(gen) == 1) {
                std::string tresor = it->second;
                ajouterEmplacementTresor(tresor);
            } else {
                std::cout << "Mais il n'a rien trouvé cette fois." << std::endl;
            }
        } else {
            std::cout << "Il n'y a pas de trésor enregistré à ce lieu." << std::endl;
        }
    }
};

// Initialisation des membres statiques
std::vector<std::shared_ptr<Pingouin>> Pingouin::colony;
std::list<std::string> Pingouin::lieux_rencontre;
std::unordered_map<std::string, std::string> Pingouin::lieux_tresors;

int main() {
    // Définir les trésors disponibles aux lieux de meetup
    Pingouin::lieux_tresors["lac bleu"] = "perle rare";
    Pingouin::lieux_tresors["glacier secret"] = "cristal gelé";
    Pingouin::lieux_tresors["grotte cachée"] = "or antique";

    auto p1 = Pingouin::creer("Pingo", 2.0, 1.0, 3.5);

    // Tenter plusieurs lieux
    p1->seRendreAuLieu("lac bleu");
    p1->seRendreAuLieu("glacier secret");
    p1->seRendreAuLieu("zone vide");

    p1->afficherEmplacementsTresors();

    return 0;
}
