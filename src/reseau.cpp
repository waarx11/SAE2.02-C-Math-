#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "reseau.hpp"
using namespace std;


Objet::Objet(string nom):nom(nom){
	cout << "Création objet: " << nom << endl;
}

void Objet::ajouterCraft(Objet *o){
	cout << "Ajout craft: " << *this << " -> " << *o << endl;
	listeCraft.push_back(o);
}

void Objet::afficherCraftDirect(){
	cout << "Liste des recettes de " << *this << ": " << endl << "-> ";
	for (Objet *o : this->getCrafts()){
		cout << *o << " ";
	}
	cout << endl;
}

vector<Objet*> Objet::getCrafts(){
	return listeCraft;
}

void Objet::supprimerCraft(Objet *o){
	for(vector<Objet*>::iterator it = listeCraft.begin(); it != listeCraft.end(); it++){	
		if( *it == o ){
			listeCraft.erase(it);
			cout << "Suppression Craft: " << *this <<" -> " << *o << endl;
			return;
		}		
	}
	cout << "Cette fabrication n'existe pas !" << endl;
}



Objet::~Objet(){}

ostream& operator<<(ostream& s, Objet& o){
	s << o.nom;
	return s;
}

bool operator==(Objet& o1, Objet& o2){
	return o1.nom==o2.nom;
}

vector<Objet*>::iterator Recherche(vector<Objet*>::iterator itDebut, vector<Objet*>::iterator itFin, Objet *valeur){
	for (auto it = itDebut; it != itFin; it ++){
		if (*it == valeur){
			return it;
		}
	}
	return itFin;
}


list<Objet*>::iterator Recherche(list<Objet*>::iterator itDebut, list<Objet*>::iterator itFin, Objet *valeur){
	for (auto it = itDebut; it != itFin; it ++){
		if (*it == valeur){
			return it;
		}
	}
	return itFin;
}



void Objet::afficherSuccessionGlob(){
    list<Objet*> aVisiter ;
	list<Objet*> visited;
	Objet *obj = this;

	cout << "Liste des recettes disponible à partir de " << obj->nom << ": " << endl;

	bool continuer = true;
	list<Objet*>::iterator itVisited;
	while(continuer){
		for(Objet *o : obj->getCrafts()){
			itVisited = Recherche(visited.begin(), visited.end(), o);
			
			if(itVisited == visited.end() ){
				aVisiter.push_back(o);
				aVisiter.unique();
				visited.push_back(o);
				visited.unique();
				cout << *o << " ";
			}
				

		}
		if(aVisiter.size() == 0){
            continuer = false ;		
		}else {	
            obj = aVisiter.front() ;
            aVisiter.pop_front();
		}

	}
	cout << endl;
	cout << endl;


}

