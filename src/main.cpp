#include <iostream>
#include "reseau.hpp"
#include "matrice.hpp"
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

void Matrice2(){
	Matrice m2;
	m2.ajouterObjet("e");
	m2.ajouterObjet("ei");
}


int main(){
	Matrice2();
	return 0;
}
