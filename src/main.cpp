#include <iostream>
#include "reseau.hpp"
#include <string>
using namespace std;

void Matrice1(){
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

	bois.ajouterCraft(baton);
	bois.ajouterCraft(planche);
	baton.ajouterCraft(torche);
	baton.ajouterCraft(epee);
	baton.ajouterCraft(pioche);
	baton.ajouterCraft(barriere);
	baton.ajouterCraft(echelle);
	epee.ajouterCraft(pioche);
	pioche.ajouterCraft(epee);
	pioche.ajouterCraft(baton);
	echelle.ajouterCraft(baton);
	barriere.ajouterCraft(portail);
	planche.ajouterCraft(baton);
	planche.ajouterCraft(charbon);
	planche.ajouterCraft(bibliotheque);
	planche.ajouterCraft(coffre);
	planche.ajouterCraft(porte);
	planche.ajouterCraft(table);
	bibliotheque.ajouterCraft(coffre);
	coffre.ajouterCraft(bibliotheque);
	porte.ajouterCraft(planche);
	porte.ajouterCraft(table);
	table.ajouterCraft(planche);

	// bois.afficherCraft();
	// baton.afficherCraft();
	// epee.afficherCraft();
	// pioche.afficherCraft();
	// echelle.afficherCraft();
	// barriere.afficherCraft();
	// planche.afficherCraft();
	// bibliotheque.afficherCraft();
	// coffre.afficherCraft();
	// porte.afficherCraft();
	// table.afficherCraft();
	bois.afficherSuccessionGlob();
}


int main(){
	Matrice1();
	return 0;
}
