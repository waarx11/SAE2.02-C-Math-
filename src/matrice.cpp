/**
 * @file matrice.cpp
 * @author Eloan ANDRE
 * @brief Implemente un réseau à l'aide d'une classe Matrice contenant un tableau 2 dimensions de booleen (True quand le craft existe)
 * @version 0.1
 * @date 2022-03-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <algorithm>
#include <string>
#include "matrice.hpp"
using namespace std;

/**
 * @brief Constructeur d'un reseau de type matrice
 * 
 */
Matrice::Matrice(){}

/**
 * @brief Ajout un objet au tableau des objets
 * 
 * @param o string 
 */
void Matrice::ajouterObjet(string o){
    // tableauObjet.push_back(o);
    for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
        if (*it==o){
            cout<<"Objet déjà présent : "<< o <<endl; 
            return;
        }
    }
    tableauObjet.push_back(o);

}


/**
 * @brief Supprime un objet dans le tableau d'objet et les craft le concernant dans la matrice
 * 
 * @param o string
 */
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


/**
 * @brief Ajoute un craft dans la matrice à la place de o1->o2
 * 
 * @param o1 string
 * @param o2 string
 */
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


/**
 * @brief Supprime un craft à la matrice
 * 
 * @param o1 string
 * @param o2 string
 */
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


/**
 * @brief Affiche les craft directs d'un objet
 * 
 * @param o string
 */
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

/**
 * @brief Affiche l'ensemble des craft disponible à partir d'un objet avec un affichage de l'objet de base
 * 
 * @param o string
 */
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


/**
 * @brief Affiche l'ensemble des craft disponible à partir d'un objet
 * 
 * @param o string
 * @param visited vector<string>
 * @return vector<string> le tableau des objets déjà visité qui ne doivent plus être parcourus 
 */
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
