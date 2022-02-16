#ifndef RESEAU_HPP
#define RESEAU_HPP
#include <string>
#include <vector>
#include <iostream>


class Objet{
	std::string nom;
	std::vector<Objet> craft;
public:
	Objet(std::string nom);
	~Objet();
	friend std::ostream& operator<< (std::ostream& s, Objet& o);
};


#endif