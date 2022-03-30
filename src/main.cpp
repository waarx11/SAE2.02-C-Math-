#include <iostream>
#include "reseau.hpp"
#include "matrice.hpp" 
#include <string>
using namespace std;

void Exo3(){
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

	cout << endl;
	cout << endl;
	
	table.ajouterCraft(&planche);
	porte.ajouterCraft(&table);
	porte.ajouterCraft(&planche);
	coffre.ajouterCraft(&bibliotheque);
	bibliotheque.ajouterCraft(&coffre);
	planche.ajouterCraft(&table);
	planche.ajouterCraft(&porte);
	planche.ajouterCraft(&coffre);
	planche.ajouterCraft(&bibliotheque);
	planche.ajouterCraft(&charbon);
	planche.ajouterCraft(&baton);
	barriere.ajouterCraft(&portail);
	echelle.ajouterCraft(&baton);
	pioche.ajouterCraft(&baton);
	pioche.ajouterCraft(&epee);
	epee.ajouterCraft(&pioche);
	baton.ajouterCraft(&echelle);
	baton.ajouterCraft(&barriere);
	baton.ajouterCraft(&pioche);
	baton.ajouterCraft(&epee);
	baton.ajouterCraft(&torche);
	bois.ajouterCraft(&planche);	
	bois.ajouterCraft(&baton);
	
	cout << endl;
	cout << endl;

	bois.afficherCraftDirect();
	baton.afficherCraftDirect();
	epee.afficherCraftDirect();
	pioche.afficherCraftDirect();
	echelle.afficherCraftDirect();
	barriere.afficherCraftDirect();
	planche.afficherCraftDirect();
	bibliotheque.afficherCraftDirect();
	coffre.afficherCraftDirect();
	porte.afficherCraftDirect();
	table.afficherCraftDirect();

	cout << endl;
	cout << endl;
		
	bois.afficherSuccessionGlob();
	baton.afficherSuccessionGlob();
	epee.afficherSuccessionGlob();
	pioche.afficherSuccessionGlob();
	echelle.afficherSuccessionGlob();
	barriere.afficherSuccessionGlob();
	planche.afficherSuccessionGlob();
	bibliotheque.afficherSuccessionGlob();
	coffre.afficherSuccessionGlob();
	porte.afficherSuccessionGlob();
	table.afficherSuccessionGlob();

}

void Exo4(){
	Matrice m2;
	m2.ajouterObjet("Bois");
	m2.ajouterObjet("Planche");
	m2.ajouterObjet("Bâton");
	m2.ajouterObjet("Torche");
	m2.ajouterObjet("Épée");
	m2.ajouterObjet("Pioche");
	m2.ajouterObjet("Barrière");
	m2.ajouterObjet("Portail");
	m2.ajouterObjet("Échelle");
	m2.ajouterObjet("Charbon");
	m2.ajouterObjet("Bibliothèque");
	m2.ajouterObjet("Coffre");
	m2.ajouterObjet("Porte");
	m2.ajouterObjet("Table");

	m2.ajouterCraft("Bois","Bâton");
	m2.ajouterCraft("Bois","Planche");
	m2.ajouterCraft("Bâton","Torche");
	m2.ajouterCraft("Bâton","Épée");
	m2.ajouterCraft("Bâton","Pioche");
	m2.ajouterCraft("Bâton","Échelle");
	m2.ajouterCraft("Épée","Pioche");
	m2.ajouterCraft("Pioche","Épée");
	m2.ajouterCraft("Pioche","Bâton");
	m2.ajouterCraft("Échelle","Bâton");
	m2.ajouterCraft("Barrière","Portail");
	m2.ajouterCraft("Planche","Bâton");
	m2.ajouterCraft("Planche","Charbon");
	m2.ajouterCraft("Planche","Bibliothèque");
	m2.ajouterCraft("Planche","Coffre");
	m2.ajouterCraft("Planche","Porte");
	m2.ajouterCraft("Planche","Table");
	m2.ajouterCraft("Bibliothèque","Coffre");
	m2.ajouterCraft("Coffre","Bibliothèque");
	m2.ajouterCraft("Porte","Planche");
	m2.ajouterCraft("Porte","Table");
	m2.ajouterCraft("Table","Planche");
	
	m2.afficherCraft("Bois");
	m2.afficherCraft("Planche");
	m2.afficherCraft("Bâton");
	m2.afficherCraft("Torche");
	m2.afficherCraft("Épée");
	m2.afficherCraft("Pioche");
	m2.afficherCraft("Barrière");
	m2.afficherCraft("Portail");
	m2.afficherCraft("Échelle");
	m2.afficherCraft("Charbon");
	m2.afficherCraft("Bibliothèque");
	m2.afficherCraft("Coffre");
	m2.afficherCraft("Porte");
	m2.afficherCraft("Table");

	m2.afficherCraftsuccessifGlob("Bois");
	m2.supprimerObjet("Planche");
	m2.afficherCraftsuccessifGlob("Bois");

	for(int pos=0;pos<int(m2.tableauObjet.size());pos++){
		for(int pos2=0;pos2<int(m2.tableauObjet.size());pos2++)
		{
			cout<<m2.matriceCraft[pos][pos2]<<" ";
		}
		cout<<endl;
	}
} 


void Exo1(){
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


int main(){
	Exo1();
	cout << "\n------------------------------------------------------------------\n" << endl;
	Exo3();
	cout << "\n------------------------------------------------------------------\n" << endl;
	Exo4();
	return 0;
}



