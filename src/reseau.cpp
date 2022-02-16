#include <iostream>
#include <string>
#include "reseau.hpp"
using namespace std;


Objet::Objet(string nom):nom(nom){}

Objet::~Objet(){}

ostream& operator<< (ostream& s, Objet& o){
	s << o.nom << endl;
	return s;
}
