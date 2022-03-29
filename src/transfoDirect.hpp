#ifndef TRDIRECT_HPP
#define TRDIRECT_HPP
#include <string>
#include <list>
#include <vector>
#include <map>
#include <iostream>

class Direct{
    std::list<std::string> listCraft;
    std::map<std::string,std::list<std::string>> mapDesTransfo;
    public:
        static std::vector<std::string> listCraftIndirectVisited;
        Direct();
        void ajouterObjet(std::string o);
        void ajoutCraft(std::string o, std::list<std::string> l1);
        void insertCraft(std::string o, std::list<std::string> l1);
        void afficherObjet() const;
        void afficherObjetCraft() const;
        void afficherCraft(std::list<std::string>) const;
        void appCheminIndirect(std::string o);
        void cheminIndirect(std::list<std::string> l1);
        // void ajouterCraft(std::string o1,std::string o2);
        // void supprimerCraft(std::string o1,std::string o2);
        // void afficherCraft(std::string o);
        // void afficherCraftsuccessifGlob(std::string o);
        // std::vector<std::string> afficherCraftsuccessif(std::string o,std::vector<std::string> visited);
        void supprimerObjet(std::string o);
        friend bool operator==(std::string o1, std::string o2);
        friend bool operator<(std::string o1, std::string o2);
        friend std::ostream& operator<<(std::ostream& s1, std::string o);
};

#endif
