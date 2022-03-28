#ifndef RESEAU_HPP
#define RESEAU_HPP
#include <string>
#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <algorithm>


class Objet{
	std::string nom;
	std::vector<Objet*> listeCraft;
public:
	Objet(std::string nom);
	void ajouterCraft(Objet *o);
	void afficherCraftDirect();
	void supprimerCraft(Objet *o);
	~Objet();
	friend std::ostream& operator<< (std::ostream& s, Objet& o);
	friend bool operator== (Objet& o1, Objet& o2);
	std::vector<Objet*> getCrafts();
	void afficherSuccessionGlob();
};
	std::vector<Objet*>::iterator Recherche(std::vector<Objet*>::iterator itDebut, std::vector<Objet*>::iterator itFin, Objet *valeur);
	std::list<Objet*>::iterator Recherche(std::list<Objet*>::iterator itDebut, std::list<Objet*>::iterator itFin, Objet *valeur);


#endif
