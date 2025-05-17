#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
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
    void setVitesseNage(double v) { vitesse_nage = v; }
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
    void setVitesseMarche(double v) { vitesse_marche = v; }
};

// Classe Pingouin
class Pingouin : public Aquatique, public Terrestre, public std::enable_shared_from_this<Pingouin> {
private:
    std::string nom;
    double vitesse_glisse;
    std::map<std::string, int> competences;
    std::set<std::weak_ptr<Pingouin>, std::owner_less<std::weak_ptr<Pingouin>>> amis;
    std::unordered_map<std::string, std::string> journal;

public:
    static std::vector<std::shared_ptr<Pingouin>> colony;
    static std::list<std::string> lieux_rencontre;

    Pingouin(const std::string& nom, double v_nage, double v_marche, double v_glisse)
        : Aquatique(v_nage), Terrestre(v_marche), nom(nom), vitesse_glisse(v_glisse) {
        std::cout << "Pingouin " << nom << " créé." << std::endl;
    }

    Pingouin(const Pingouin& other)
        : Aquatique(other.vitesse_nage), Terrestre(other.vitesse_marche),
          nom(other.nom), vitesse_glisse(other.vitesse_glisse),
          competences(other.competences), journal(other.journal) {}

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

    void setVitesseGlisse(double v) {
        vitesse_glisse = v;
    }

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
        std::cout << "Lieu ajouté : " << lieu << std::endl;
    }

    static void retirerLieu(const std::string& lieu) {
        auto it = std::find(lieux_rencontre.begin(), lieux_rencontre.end(), lieu);
        if (it != lieux_rencontre.end()) {
            lieux_rencontre.erase(it);
            std::cout << "Lieu retiré : " << lieu << std::endl;
        } else {
            std::cout << "Lieu non trouvé : " << lieu << std::endl;
        }
    }

    static void afficherLieux() {
        std::cout << "\n--- Lieux de rencontre des pingouins ---\n";
        for (const auto& lieu : lieux_rencontre) {
            std::cout << "- " << lieu << std::endl;
        }
    }

    void ajouterCompetence(const std::string& nom, int niveau) {
        competences[nom] = niveau;
        std::cout << "Compétence ajoutée : " << nom << " (niveau " << niveau << ")" << std::endl;
    }

    void modifierCompetence(const std::string& nom, int nouveau_niveau) {
        auto it = competences.find(nom);
        if (it != competences.end()) {
            it->second = nouveau_niveau;
            std::cout << "Compétence modifiée : " << nom << " (niveau " << nouveau_niveau << ")" << std::endl;
        } else {
            std::cout << "Compétence introuvable : " << nom << std::endl;
        }
    }

    void supprimerCompetence(const std::string& nom) {
        if (competences.erase(nom)) {
            std::cout << "Compétence supprimée : " << nom << std::endl;
        } else {
            std::cout << "Compétence non trouvée : " << nom << std::endl;
        }
    }

    void listerCompetences() const {
        std::cout << "\nCompétences de " << nom << " :\n";
        if (competences.empty()) {
            std::cout << "(Aucune compétence)" << std::endl;
        } else {
            for (const auto& c : competences) {
                std::cout << "- " << c.first << " : niveau " << c.second << std::endl;
            }
        }
    }

    void ajouterAmi(const std::shared_ptr<Pingouin>& ami) {
        if (ami.get() != this) {
            amis.insert(ami);
            std::cout << nom << " est maintenant ami avec " << ami->nom << std::endl;
        }
    }

    void retirerAmi(const std::shared_ptr<Pingouin>& ami) {
        if (amis.erase(ami)) {
            std::cout << nom << " n'est plus ami avec " << ami->nom << std::endl;
        } else {
            std::cout << ami->nom << " n'était pas un ami de " << nom << std::endl;
        }
    }

    void listerAmis() const {
        std::cout << "\nAmis de " << nom << " :\n";
        if (amis.empty()) {
            std::cout << "(Aucun ami)" << std::endl;
        } else {
            for (const auto& wp : amis) {
                if (auto sp = wp.lock()) {
                    std::cout << "- " << sp->nom << std::endl;
                }
            }
        }
    }

    // === Journal ===
    void ajouterJournal(const std::string& date, const std::string& description) {
        journal[date] = description;
        std::cout << "Événement ajouté pour le " << date << std::endl;
    }

    void modifierJournal(const std::string& date, const std::string& nouvelle_description) {
        auto it = journal.find(date);
        if (it != journal.end()) {
            it->second = nouvelle_description;
            std::cout << "Événement modifié pour le " << date << std::endl;
        } else {
            std::cout << "Aucun événement trouvé pour " << date << std::endl;
        }
    }

    void supprimerJournal(const std::string& date) {
        if (journal.erase(date)) {
            std::cout << "Événement supprimé pour le " << date << std::endl;
        } else {
            std::cout << "Aucun événement trouvé à supprimer pour " << date << std::endl;
        }
    }

    void afficherJournal() const {
        std::cout << "\nJournal de " << nom << " :\n";
        if (journal.empty()) {
            std::cout << "(Aucun événement enregistré)" << std::endl;
        } else {
            for (const auto& entry : journal) {
                std::cout << entry.first << " : " << entry.second << std::endl;
            }
        }
    }
};

// Initialisation des membres statiques
std::vector<std::shared_ptr<Pingouin>> Pingouin::colony;
std::list<std::string> Pingouin::lieux_rencontre;

// === MAIN ===
int main() {
    auto p1 = Pingouin::creer("Pingo", 2.0, 1.0, 3.5);
    auto p2 = Pingouin::creer("Tux", 1.8, 0.9, 3.0);

    p1->ajouterJournal("2025-05-13", "Grande plongée dans le lac");
    p1->ajouterJournal("2025-05-14", "Chasse au poisson");
    p1->modifierJournal("2025-05-13", "Exploration du fond du lac");
    p1->supprimerJournal("2025-05-14");
    p1->afficherJournal();

    return 0;
}
