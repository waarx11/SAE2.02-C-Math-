#ifndef RESEAU1_HPP
#define RESEAU1_HPP
#include <string>
#include <list>
#include <vector>
#include <map>
#include <iostream>

class Reseau1{
    std::list<std::string> listCraft;
    std::map<std::string,std::list<std::string>> mapDesTransfo;
    public:
        static std::vector<std::string> listCraftIndirectVisited;
        Reseau1();
        // void ajouterObjet(std::string o);
        void insertCraft(std::string o, std::list<std::string> l1);
        void afficherObjet() const;
        void afficherObjetCraft() const;
        void afficherCraft(std::list<std::string>) const;
        void appCheminIndirect(std::string o);
        void cheminIndirect(std::list<std::string> l1);
        void afficherObjetCraftPrec(std::string o) const;
        void supprimerObjet(std::string o);
        void ajouterCraft(std::string obj, std::string const at);
        friend bool operator==(std::string o1, std::string o2);
        friend bool operator<(std::string o1, std::string o2);
};

#endif
