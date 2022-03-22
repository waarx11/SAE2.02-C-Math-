#include <iostream>
#include <algorithm>
#include <string>
#include "matrice.hpp"
using namespace std;

Matrice::Matrice(){}


void Matrice::ajouterObjet(string o){
    // tableauObjet.push_back(o);
    for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
        if (*it==o){
            cout<<"Objet déjà présent"<<endl; 
            return;
        }
    }
    tableauObjet.push_back(o);

    //Erreur lorsque on esssaye d'ajouter une colonne donc on fait a l'initialisation mais taille fixe
    // for(int i=0;i<int(tableauObjet.size())-1;i++){ 
        // matriceCraft[i][int(tableauObjet.size())-1]=0;
        // matriceCraft[int(tableauObjet.size())-1][i]=0; 
    // }
}

void Matrice::ajouterCraft(string o1, string o2){
    int pos1=0,pos2=0;
    for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
        if (*it==o1){
            break;
        }
        pos1++;
    }

    for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
        if (*it==o2){
            break;
        }
        pos2++;
    }
    if(pos1==int(tableauObjet.size()) || pos2==int(tableauObjet.size()))
    {
        cout<< "Pas trouvé"<<endl;;
        return;
    }
    matriceCraft[pos1][pos2]=1;
}

void Matrice::supprimerCraft(string o1, string o2){
    int pos1=0,pos2=0;
    for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
        if (*it==o1){
            break;
        }
        pos1++;
    }

    for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
        if (*it==o2){
            break;
        }
        pos2++;
    }
    if(pos1==int(tableauObjet.size()) || pos2==int(tableauObjet.size()))
    {
        cout<< "Pas trouvé"<<endl;;
        return;
    }
    matriceCraft[pos1][pos2]=0;
}

void Matrice::afficherCraft(string o){
    int pos=0,pos2=0;
    for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
        if (*it==o2){
            break;
        }
        pos++;
    }

    cout<< "Craft à partir de : "<< o << endl;
    for(vector<string>::iterator it = matriceCraft[pos].begin(); it != matriceCraft[pos].end(); it++){
        if(*it==1){
            cout<<tableauObjet[pos2]<<", ";
        }
        pos2++;
    }
    cout<<endl;
}