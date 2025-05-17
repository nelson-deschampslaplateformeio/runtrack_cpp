#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
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
    std::map<std::string, int> competences;

public:
    // Statique : liste des pingouins instanciés
    static std::vector<std::shared_ptr<Pingouin>> colony;

    // Statique : liste des lieux de rencontre
    static std::list<std::string> lieux_rencontre;

    // Constructeur
    Pingouin(const std::string& nom, double v_nage, double v_marche, double v_glisse)
        : Aquatique(v_nage), Terrestre(v_marche), nom(nom), vitesse_glisse(v_glisse) {
        std::cout << "Pingouin " << nom << " créé." << std::endl;
    }

    // Constructeur de copie
    Pingouin(const Pingouin& other)
        : Aquatique(other.vitesse_nage), Terrestre(other.vitesse_marche),
          nom(other.nom), vitesse_glisse(other.vitesse_glisse), competences(other.competences) {
        std::cout << "Constructeur de copie appelé pour " << nom << std::endl;
    }

    // Destructeur
    ~Pingouin() {
        auto it = std::remove_if(colony.begin(), colony.end(),
                                 [this](const std::shared_ptr<Pingouin>& p) {
                                     return p.get() == this;
                                 });
        colony.erase(it, colony.end());
        std::cout << "Pingouin " << nom << " détruit." << std::endl;
    }

    // Méthode de création avec shared_ptr
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

    // --- Gestion des lieux ---
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

    // --- Gestion des compétences ---
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
};

// Initialisation des membres statiques
std::vector<std::shared_ptr<Pingouin>> Pingouin::colony;
std::list<std::string> Pingouin::lieux_rencontre;

// === MAIN ===

int main() {
    // Gestion des lieux
    Pingouin::ajouterLieu("lac");
    Pingouin::ajouterLieu("glacier");
    Pingouin::ajouterLieu("banquise");
    Pingouin::afficherLieux();

    Pingouin::retirerLieu("glacier");
    Pingouin::afficherLieux();

    // Création de pingouins
    {
        auto p1 = Pingouin::creer("Pingo", 2.0, 1.0, 3.5);
        auto p2 = Pingouin::creer("Tux", 1.8, 0.9, 3.0);

        // Ajout de compétences
        p1->ajouterCompetence("plongée", 4);
        p1->ajouterCompetence("pêche", 5);
        p1->modifierCompetence("plongée", 5);
        p1->supprimerCompetence("chant");
        p1->listerCompetences();

        p2->ajouterCompetence("glisse", 3);
        p2->listerCompetences();

        // Affichage des temps
        Pingouin::afficherTousLesTemps();
    }

    std::cout << "\nAprès destruction automatique : "
              << Pingouin::colony.size() << " pingouin(s) restants." << std::endl;

    return 0;
}
