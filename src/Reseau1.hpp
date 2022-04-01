/**
 * @file Reseau1.hpp
 * @author Verdier Nathan
 * @brief Implemente un réseau à l'aide d'une classe Reseau1
 * @date 2022-03-30
 */
#ifndef RESEAU1_HPP
#define RESEAU1_HPP
#include <string>
#include <list>
#include <vector>
#include <map>
#include <iostream>

class Reseau1{
    std::map<std::string,std::list<std::string>> mapDesTransfo;
    public:
        static std::vector<std::string> listCraftIndirectVisited;
        Reseau1();
        void insertCraft(std::string o, std::list<std::string> l1);
        void afficherObjet() const;
        void afficherObjetCraft() const;
        void afficherCraft(std::list<std::string>) const;
        void appCheminIndirect(std::string o);
        void cheminIndirect(std::list<std::string> l1);
        void afficherObjetCraftPrec(std::string o) const;
        void supprimerObjet(std::string o);
        void ajouterCraft(std::string obj, std::string const at);
};

#endif
