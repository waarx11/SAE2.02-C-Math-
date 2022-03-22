#ifndef MATRICE_HPP
#define MATRICE_HPP
#include <string>
#include <vector>
#include <iostream>

class Matrice{
    std::vector<std::string> tableauObjet;
    std::vector<std::vector<int> >matriceCraft {{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}};
    public:
        Matrice();
        void ajouterObjet(std::string o);
        void ajouterCraft(std::string o1,std::string o2);
        void supprimerCraft(std::string o1,std::string o2);
        void afficherCraftDirect(std::string o);
};






#endif
