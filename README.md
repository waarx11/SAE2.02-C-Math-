# SAE2.02

SAE 2.02 - Maths C++

* git add .
* git status //facultatif, permet de voir tout ce qui a été add
* git commit -m "commentaire"   --> git commit -m ":fire:"
* git push

* git clone <lien>
* git pull

* git rm file // supp le file sur le dépot


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
