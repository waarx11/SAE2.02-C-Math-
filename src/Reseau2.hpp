/**
 * @file Reseau2.hpp
 * @author Verdier Nathan
 * @brief Implemente un réseau à l'aide d'une classe Reseau2
 * @date 2022-03-30
 */
#ifndef RESEAU2_HPP
#define RESEAU2_HPP
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <iostream>

class Reseau2{
    std::map<std::string,std::list<std::string>> mapDesTransfo;
    std::set<std::pair<std::string,std::string>> setAffichage;
    public:
        static std::vector<std::string> listCraftIndirectVisited;
        Reseau2();
        void insertCraft(std::string o, std::list<std::string> l1);
        void afficherObjet() const;
        void afficherObjetCraft() const;
        void afficherCraft(std::string o, std::list<std::string>) const;
        void appCheminIndirect(std::string o);
        void cheminIndirect(std::list<std::string> l1);
        void afficherObjetCraftPrec(std::string o) const;
        void supprimerObjet(std::string o);
        void ajouterCraft(std::string obj, std::string const at);
};

#endif
