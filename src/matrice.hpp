#ifndef MATRICE_HPP
#define MATRICE_HPP
#include <string>
#include <vector>
#include <iostream>

class Matrice{
    std::vector<std::string> tableauObjet;
    std::vector<std::vector<int> >matriceCraft;
    public:
        Matrice();
        void ajouterObjet(std::string o);
};






#endif
