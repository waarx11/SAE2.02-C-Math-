/**
 * @file reseau.cpp
 * @brief Exercice 3
 * @author Baptiste Bonneau
 * @date 30/03/2022
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "reseau.hpp"
using namespace std;

/**
  *	@brief Constructeur d'un objet
  *	@param nom Nom de l'objet
*/
Objet::Objet(string nom):nom(nom){
	cout << "Création objet: " << nom << endl;
}

/**
  *	@brief Ajout d'un craft à la liste des crafts d'un objet
  *	@param o Adresse d'un Objet
*/
void Objet::ajouterCraft(Objet *o){
	cout << "Ajout craft: " << *this << " -> " << *o << endl;
	listeCraft.push_back(o);
}

/**
  *	@brief Affiche les crafts d'un objet
*/
void Objet::afficherCraftDirect(){
	cout << "Liste des recettes de " << *this << ": " << endl << "-> ";
	for (Objet *o : this->getCrafts()){
		cout << *o << " ";
	}
	cout << endl;
}

/**
  *	@brief Renvoie la liste des crafts d'un objet
  *	@return Nouvelle liste des crafts de l'objet
*/
vector<Objet*> Objet::getCrafts(){
	return listeCraft;
}

/**
  *	@brief Supprime un objet de la liste des crafts d'un objet
  *	@param o Objet à supprimer de la liste des crafts
*/
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


/**
  *	@brief Destructeur d'un objet
*/
Objet::~Objet(){}

/**
  *	@brief Redéfinition de l'opérateur d'affichage << 
  *	@param s Flux 
  *	@param o Objet à afficher
  * @return Flux 
*/
ostream& operator<<(ostream& s, Objet& o){
	s << o.nom;
	return s;
}

/**
  *	@brief Redéfinition de l'opérateur d'égalité == 
  *	@param o1 Objet 
  *	@param o2 Objet
  * @return true Si les deux objets sont égaux, false sinon
*/
bool operator==(Objet& o1, Objet& o2){
	return o1.nom==o2.nom;
}


/**
  *	@brief Fonction de recherche dans une liste
  *	@param itDebut Itérateur de début d'une liste
  *	@param itFin Itérateur de fin d'une liste
  *	@param valeur Adresse de la valeur a trouver
  * @return Place dans la liste si trouvé, taille de la liste sinon
*/
list<Objet*>::iterator Recherche(list<Objet*>::iterator itDebut, list<Objet*>::iterator itFin, Objet *valeur){
	for (auto it = itDebut; it != itFin; it ++){
		if (*it == valeur){
			return it;
		}
	}
	return itFin;
}


/**
  *	@brief Affiche la liste de tous les crafts possibles en partant d'un objet
*/
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

