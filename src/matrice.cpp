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
            cout<<"Objet déjà présent : "<< o <<endl; 
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

void Matrice::supprimerObjet(string o){
    int pos=0;
    for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
        if (*it==o){
            break;
        }
        pos++;
    }
    for(int i=0;i<tableauObjet.size();i++){
        matriceCraft[i].erase(matriceCraft[i].begin()+pos);
    } 
    matriceCraft.erase(matriceCraft.begin()+pos);
    tableauObjet.erase(tableauObjet.begin()+pos);
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
    matriceCraft.push_back({0});
    matriceCraft[pos1][pos2]=true;
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
    matriceCraft[pos1][pos2]=false;
}

void Matrice::afficherCraft(string o){
    int pos=0,pos2;
    for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
        if (*it==o){
            break;
        }
        pos++;
    }
    if(pos==tableauObjet.size())
    {
        cout << "Objet introuvable !" <<endl;
        return;
    }

    cout<< "Craft à partir de : "<< o << endl;
    for(pos2=0;pos2<int(tableauObjet.size());pos2++){
        if(matriceCraft[pos][pos2]==true){
            cout<<tableauObjet[pos2]<<", ";
        }
    }
    cout<<endl;
}


void Matrice::afficherCraftsuccessifGlob(string o){
    int pos=0,pos2;
    vector<string> visited;
    for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
        if (*it==o){
            break;
        }
        pos++;
    }
    if(pos==tableauObjet.size())
    {
        cout << "Objet introuvable !" <<endl;
        return;
    }
    cout<< "Craft grâce à : "<< o << endl;
    for(pos2=0;pos2<int(tableauObjet.size());pos2++){
        if(matriceCraft[pos][pos2]==true){
            auto it=visited.begin();
            for(it;it!=visited.end();it++)
                if(tableauObjet[pos2]==*it)
                    break;
            if(it==visited.end())
            { 
                cout<<tableauObjet[pos2]<<", ";
                visited.push_back(tableauObjet[pos2]);
                visited=afficherCraftsuccessif(tableauObjet[pos2],visited);
            } 
        }
    }
    cout<<endl;
}

vector<string> Matrice::afficherCraftsuccessif(string o,vector<string> visited){
    int pos=0,pos2;
    for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
        if (*it==o){
            break;
        }
        pos++;
    }

    for(pos2=0;pos2<int(tableauObjet.size());pos2++){
        if(matriceCraft[pos][pos2]==true){
            auto it=visited.begin();
            for(it;it!=visited.end();it++)
                if(tableauObjet[pos2]==*it)
                    break;
            if(it==visited.end())
            { 
                cout<<tableauObjet[pos2]<<", ";
                visited.push_back(tableauObjet[pos2]);
                visited=afficherCraftsuccessif(tableauObjet[pos2],visited);
            } 
        }
    } 
    return visited;
} 
