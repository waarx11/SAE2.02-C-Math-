#ifndef RESEAU_HPP
#define RESEAU_HPP
#include <string>
#include <vector>
#include <iostream>


class Objet{
	std::string nom;
	std::vector<Objet> listeCraft;
public:
	Objet(std::string nom);
	void ajouterCraft(Objet o);
	void afficherCraft();
	void supprimerCraft(Objet o);
	~Objet();
	friend std::ostream& operator<< (std::ostream& s, Objet& o);
	friend bool operator== (Objet& o1, Objet& o2);
};


#endif