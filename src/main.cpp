#include <iostream>
//#include "reseau.hpp"
//#include "matrice.hpp"
#include "Reseau1.hpp"
#include <string>
using namespace std;

// void Matrice1(){
// 	Objet bois("Bois");
// 	Objet baton("Bâton");
// 	Objet torche("Torche");
// 	Objet epee("Épée");
// 	Objet pioche("Pioche");
// 	Objet barriere("Barrière");
// 	Objet portail("Portail");
// 	Objet echelle("Échelle");
// 	Objet planche("Planche");
// 	Objet charbon("Charbon");
// 	Objet bibliotheque("Bibliothèque");
// 	Objet coffre("Coffre");
// 	Objet porte("Porte");
// 	Objet table("Table");

// 	bois.ajouterCraft(baton);
// 	bois.ajouterCraft(planche);
// 	baton.ajouterCraft(torche);
// 	baton.ajouterCraft(epee);
// 	baton.ajouterCraft(pioche);
// 	baton.ajouterCraft(barriere);
// 	baton.ajouterCraft(echelle);
// 	epee.ajouterCraft(pioche);
// 	pioche.ajouterCraft(epee);
// 	pioche.ajouterCraft(baton);
// 	echelle.ajouterCraft(baton);
// 	barriere.ajouterCraft(portail);
// 	planche.ajouterCraft(baton);
// 	planche.ajouterCraft(charbon);
// 	planche.ajouterCraft(bibliotheque);
// 	planche.ajouterCraft(coffre);
// 	planche.ajouterCraft(porte);
// 	planche.ajouterCraft(table);
// 	bibliotheque.ajouterCraft(coffre);
// 	coffre.ajouterCraft(bibliotheque);
// 	porte.ajouterCraft(planche);
// 	porte.ajouterCraft(table);
// 	table.ajouterCraft(planche);

// 	// bois.afficherCraft();
// 	// baton.afficherCraft();
// 	// epee.afficherCraft();
// 	// pioche.afficherCraft();
// 	// echelle.afficherCraft();
// 	// barriere.afficherCraft();
// 	// planche.afficherCraft();
// 	// bibliotheque.afficherCraft();
// 	// coffre.afficherCraft();
// 	// porte.afficherCraft();
// 	// table.afficherCraft();
// 	bois.afficherSuccessionGlob();
// }

// void Matrice2(){
// 	Matrice m2;
// 	m2.ajouterObjet("Bois");
// 	m2.ajouterObjet("Planche");
// 	m2.ajouterObjet("Bâton");
// 	m2.ajouterObjet("Torche");
// 	m2.ajouterObjet("Épée");
// 	m2.ajouterObjet("Pioche");
// 	m2.ajouterObjet("Barrière");
// 	m2.ajouterObjet("Portail");
// 	m2.ajouterObjet("Échelle");
// 	m2.ajouterObjet("Charbon");
// 	m2.ajouterObjet("Bibliothèque");
// 	m2.ajouterObjet("Coffre");
// 	m2.ajouterObjet("Porte");
// 	m2.ajouterObjet("Table");
// 	m2.ajouterCraft("Bois","Bâton");
// 	m2.ajouterCraft("Bois","Planche");
// 	m2.ajouterCraft("Bâton","Torche");
// 	m2.ajouterCraft("Bâton","Épée");
// 	m2.ajouterCraft("Bâton","Pioche");
// 	m2.ajouterCraft("Bâton","Échelle");
// 	m2.ajouterCraft("Épée","Pioche");
// 	m2.ajouterCraft("Pioche","Épée");
// 	m2.ajouterCraft("Pioche","Bâton");
// 	m2.ajouterCraft("Échelle","Bâton");
// 	m2.ajouterCraft("Barrière","Portail");
// 	m2.ajouterCraft("Planche","Bâton");
// 	m2.ajouterCraft("Planche","Charbon");
// 	m2.ajouterCraft("Planche","Bibliothèque");
// 	m2.ajouterCraft("Planche","Coffre");
// 	m2.ajouterCraft("Planche","Porte");
// 	m2.ajouterCraft("Planche","Table");
// 	m2.ajouterCraft("Bibliothèque","Coffre");
// 	m2.ajouterCraft("Coffre","Bibliothèque");
// 	m2.ajouterCraft("Porte","Planche");
// 	m2.ajouterCraft("Porte","Table");
// 	m2.ajouterCraft("Table","Planche");
// 	m2.afficherCraft("Bibliothèque");
// 	// for(int pos=0;pos<m2.tableauObjet.size();pos++){
// 	// 	for(int pos2=0;pos2<m2.tableauObjet.size();pos2++)
// 	// 	{
// 	// 		cout<<m2.matriceCraft[pos][pos2]<<" ";
// 	// 	}
// 	// 	cout<<endl;}
// 	m2.afficherCraftsuccessifGlob("Bois");
// }

void transfoDirect(){
	Reseau1 d1;
	d1.insertCraft("Bois",{"Bâton","Planche"});
	d1.insertCraft("Bâton",{"Torche","Épée","Pioche","Échelle"});
	d1.insertCraft("Épée",{"Pioche"});
	d1.insertCraft("Pioche",{"Épée","Bâton"});
	d1.insertCraft("Échelle",{"Bâton"});
	d1.insertCraft("Barrière",{"Portail"});
	d1.insertCraft("Planche",{"Bâton","Charbon","Bibliothèque","Coffre","Porte","Table"});
	d1.insertCraft("Bibliothèque",{"Coffre"});
	d1.insertCraft("Coffre",{"Bibliothèque"});
	d1.insertCraft("Porte",{"Planche","Table"});
	d1.insertCraft("Table",{"Planche"});
	// d1.supprimerObjet("Table");
	// d1.supprimerObjet("Planche");
	// d1.supprimerObjet("Coffre");
	// d1.supprimerObjet("Bois");
	// d1.supprimerObjet("Bâton");
	// d1.supprimerObjet("Bibliothèque");
	//d1.afficherObjet();
	//d1.afficherObjetCraft();

    // d1.appCheminIndirect("Bois");
    // d1.appCheminIndirect("Pioche");
    // d1.appCheminIndirect("Charbon");

	d1.ajouterCraft("Bibliothèque","oui");
	d1.ajouterCraft("Bibliothèque","oui");
	d1.ajouterCraft("Bibliothèque","oui");
	d1.afficherObjetCraftPrec("Bibliothèque");
}


// 	bois.ajouterCraft(baton);
// 	bois.ajouterCraft(planche);
// 	baton.ajouterCraft(torche);
// 	baton.ajouterCraft(epee);
// 	baton.ajouterCraft(pioche);
// 	baton.ajouterCraft(barriere);
// 	baton.ajouterCraft(echelle);
// 	epee.ajouterCraft(pioche);
// 	pioche.ajouterCraft(epee);
// 	pioche.ajouterCraft(baton);
// 	echelle.ajouterCraft(baton);
// 	barriere.ajouterCraft(portail);
// 	planche.ajouterCraft(baton);
// 	planche.ajouterCraft(charbon);
// 	planche.ajouterCraft(bibliotheque);
// 	planche.ajouterCraft(coffre);
// 	planche.ajouterCraft(porte);
// 	planche.ajouterCraft(table);
// 	bibliotheque.ajouterCraft(coffre);
// 	coffre.ajouterCraft(bibliotheque);
// 	porte.ajouterCraft(planche);
// 	porte.ajouterCraft(table);
// 	table.ajouterCraft(planche);

int main(){
	transfoDirect();
	return 0;
}



