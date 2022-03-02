#include <iostream>
#include <algorithm>
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

void Objet::afficherSuccessionGlob(){
	list<Objet> visited;
	set<Objet> craft;
	cout << "Liste des recettes à partir de "<< nom << ":" << endl;
	visited.push_back(*this);
	// for(vector<Objet>::iterator it = listeCraft.begin(); it != listeCraft.end(); it++){
	// 	it->afficherCraft();
	// 	it->afficherSuccession(visited);
	// }
	for(int i=0;i<int(listeCraft.size());i++)
		listeCraft[i].afficherCraft();
	
}

// list<Objet> Objet::afficherSuccession(list<Objet> &visited){
// 	cout << nom << ", " ; 
// 	// visited.insert(*this);
// 	for(vector<Objet>::iterator it = listeCraft.begin(); it != listeCraft.end(); it++){
		
// 		list<Objet>::iterator findIter;
// 		findIter = find(visited.begin(), visited.end(), *it);
// 		if(findIter != visited.end()) cout << "pas trouvé fdp" << endl;
		
// 		//it->afficherSuccession(visited);
		
// 	}
		
// 	return visited;

// }
list<Objet> Objet::afficherSuccession(list<Objet> &visited){
	cout << nom << ", " ; 
	visited.push_back(*this);
	// afficherCraft();
	for(vector<Objet>::iterator it = listeCraft.begin(); it != listeCraft.end(); it++){
		cout << "CRAFT !!!!!!";
		it->afficherCraft();
		list<Objet>::iterator it2;
		for(list<Objet>::iterator it2 = visited.begin(); it2 != visited.end(); it2++){
			if (*it2==*it)
				continue;
			it->afficherSuccession(visited);
		}
	}
		
	return visited;

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

ostream& operator<<(ostream& s, Objet& o){
	s << o.nom;
	return s;
}

bool operator==(Objet& o1, Objet& o2){
	if (o1.nom==o2.nom) return true;
	return false;
}