#include <iostream>
#include <string>
#include "reseau.hpp"
using namespace std;


Objet::Objet(string nom):nom(nom){}

void Objet::ajouterCraft(Objet o){
	listeCraft.push_back(o);
}

void Objet::afficherCraft(){
	cout << "Liste des recettes de " << *this << ": " << endl << "-> ";
	for(vector<Objet>::iterator it = listeCraft.begin(); it != listeCraft.end(); it++){
		it == listeCraft.end()-1 ? cout << *it << endl : cout << *it << ", ";
		
	}
}

void Objet::supprimerCraft(Objet o){
	for(vector<Objet>::iterator it = listeCraft.begin(); it != listeCraft.end(); it++){	
		if( *it == o ){
			listeCraft.erase(it);
			cout << "Craft: " << o <<" supprimé dans: " << *this<< endl;
			return;
		}		
	}
	cout << "Cette fabrication n'existe pas !" << endl;
}


Objet::~Objet(){}

ostream& operator<< (ostream& s, Objet& o){
	s << o.nom;
	return s;
}

bool operator== (Objet& o1, Objet& o2){
	return o1.nom==o2.nom;
}