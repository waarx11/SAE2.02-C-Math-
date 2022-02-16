#include <iostream>
#include "reseau.hpp"
#include <string>
using namespace std;


void testR0(){
	Objet bois("bois");
	Objet planche("planche");
	Objet baton("baton");
	Objet torche("torche");
	bois.ajouterCraft(planche);
	bois.ajouterCraft(baton);
	bois.ajouterCraft(torche);
	bois.supprimerCraft(torche);
	baton.ajouterCraft(torche);
	bois.afficherCraft();
	
}

void testR1(){
	Objet bois("Bois");
	Objet baton("Bâton");
	Objet torche("Torche");
	Objet epee("Épée");
	Objet pioche("Pioche");
	Objet barriere("Barrière");
	Objet portail("Portail");
	Objet echelle("Échelle");
	Objet planche("Planche");
	Objet charbon("Charbon");
	Objet bibliotheque("Bibliothèque");
	Objet coffre("Coffre");
	Objet porte("Porte");
	Objet table("Table");
}


int main(){
	testR1();
	return 0;
}
