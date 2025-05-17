#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
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

public:
    static std::vector<std::shared_ptr<Pingouin>> colony;
    static std::list<std::string> lieux_rencontre;

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

    static void ajouterLieu(const std::string& lieu) {
        lieux_rencontre.push_back(lieu);
    }

    static void retirerLieu(const std::string& lieu) {
        auto it = std::find(lieux_rencontre.begin(), lieux_rencontre.end(), lieu);
        if (it != lieux_rencontre.end()) lieux_rencontre.erase(it);
    }

    static void afficherLieux() {
        std::cout << "\n--- Lieux de rencontre ---\n";
        for (const auto& lieu : lieux_rencontre) {
            std::cout << "- " << lieu << std::endl;
        }
    }

    void ajouterCompetence(const std::string& c, int niveau) {
        competences[c] = niveau;
    }

    void supprimerCompetence(const std::string& c) {
        competences.erase(c);
    }

    void listerCompetences() const {
        std::cout << "\nCompétences de " << nom << " :\n";
        for (const auto& c : competences) {
            std::cout << "- " << c.first << " : niveau " << c.second << std::endl;
        }
    }

    void ajouterJournal(const std::string& date, const std::string& desc) {
        journal[date] = desc;
    }

    void afficherJournal() const {
        std::cout << "\nJournal de " << nom << " :\n";
        for (const auto& e : journal) {
            std::cout << e.first << " : " << e.second << std::endl;
        }
    }

    void ajouterAmi(const std::shared_ptr<Pingouin>& ami) {
        if (ami.get() != this) amis.insert(ami);
    }

    void listerAmis() const {
        std::cout << "\nAmis de " << nom << " :\n";
        for (const auto& wp : amis) {
            if (auto sp = wp.lock()) {
                std::cout << "- " << sp->nom << std::endl;
            }
        }
    }

    // === Compétitions ===
    void ajouterTempsCompetition(double temps) {
        temps_competitions.insert(temps);
        std::cout << nom << " a enregistré un temps de " << temps << " secondes en compétition." << std::endl;
    }

    void afficherTempsCompetitions() const {
        std::cout << "\nTemps de compétition de " << nom << " (ordre croissant) :" << std::endl;
        for (double t : temps_competitions) {
            std::cout << "- " << t << " s" << std::endl;
        }
    }
};

// Initialisation des membres statiques
std::vector<std::shared_ptr<Pingouin>> Pingouin::colony;
std::list<std::string> Pingouin::lieux_rencontre;

int main() {
    auto p1 = Pingouin::creer("Pingo", 2.0, 1.0, 3.5);
    auto p2 = Pingouin::creer("Tux", 1.8, 0.9, 3.0);

    p1->ajouterTempsCompetition(65.2);
    p1->ajouterTempsCompetition(62.7);
    p1->ajouterTempsCompetition(66.3);
    p1->ajouterTempsCompetition(62.7); // doublon

    p1->afficherTempsCompetitions();

    return 0;
}
