/**
 * @file Reseau1.cpp
 * @author Verdier Nathan
 * @brief crée une map d'objet, parcours tout les objet crée, et les attributs, affiche tout les transformation direct et indirect d'un objet 
 * @date 2022-03-30
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include "Reseau1.hpp"
using namespace std;

vector<string> Reseau1::listCraftIndirectVisited;

/**
 * @brief Constructeur de reseau 1
 * 
 */
Reseau1::Reseau1(){}

/**
 * @brief insert dans une map un string comme key de le map et une liste de string comme attribue de cette map
 * 
 * @param o string destiner a devinir la key de la map mapDesTransfo
 * @param l1 liste de string qui devientdra les attributs de la map mapDesTransfo
 */
void Reseau1::insertCraft(string o, list<string> l1)
{
    list<string>::iterator itfind;
    if (mapDesTransfo.size()==0)
        mapDesTransfo.insert(pair<string,list<string>>{o,l1});
    for (auto it=mapDesTransfo.begin(); it!=mapDesTransfo.end(); ++it)
    {
        if (o==it->first)
        {
            for (list<string>::iterator itlist=it->second.begin(); itlist!=it->second.end(); ++itlist)
            {
                itfind = find(l1.begin(), l1.end(), *itlist);
                if (itfind != l1.end())
                    l1.erase(itfind);
            }
            if (l1.size()!= 0)
            {
                for (list<string>::iterator itlist2=it->second.begin(); itlist2!=it->second.end(); ++itlist2)
                    l1.push_back(*itlist2);
                mapDesTransfo[o]=l1;
            }
        }
        else
            mapDesTransfo.insert(pair<string,list<string>>{o,l1});
    }
}

/**
 * @brief Affiche tout les objets existant
 * 
 */
void Reseau1::afficherObjet() const
{
    for (auto it : mapDesTransfo)
        cout << it.first << endl;
}

/**
 * @brief affiche tout les objets de la map et fait appel a la fonction afficherCraft en donnant les attribues de chaque objet
 * 
 */
void Reseau1::afficherObjetCraft() const
{
    for(auto it : mapDesTransfo)
    {
        cout << "Voici les crafts pour l'objets " << it.first << " :" << endl;
        this->afficherCraft(it.second);
    }
}

/**
 * @brief affiche un objet et fait appel a la fonction afficherCraft en donnant les attribues de cette objet
 * 
 * @param o string
 */
void Reseau1::afficherObjetCraftPrec(string o) const
{
    for(auto it : mapDesTransfo)
    {
        if (it.first==o)
        {
            cout << "Voici les crafts pour l'objets " << it.first << " :" << endl;
            this->afficherCraft(it.second);
        }
    }
}

/**
 * @brief parcours une liste reçu en paramètre et affiche chaque élément
 * 
 * @param l1 liste de string
 */
void Reseau1::afficherCraft(list<string> l1) const
{
    for (auto it : l1)
        cout << "   " << it << endl;
}

/**
 * @brief supprime un élément de la map dont la key est égale au string passer en paramètre
 * 
 * @param o string, nom de l'objet
 */
void Reseau1::supprimerObjet(std::string o)
{
    map<string,list<string>>::iterator it;
    it = mapDesTransfo.find(o);
    mapDesTransfo.erase(it);
    cout << "Objet " << o << " supprimer avec succès!"<<endl;
}

/**
 * @brief cherche dans la map mapDesTransfo la key qui correspond au string passer en paramètre puis appel la fonction cheminIndirect en lui donnant en paramètre l'attribue de la key
 * 
 * @param o string, nom de l'objet
 */
void Reseau1::appCheminIndirect(string o)
{
    for (auto it=mapDesTransfo.begin(); it!=mapDesTransfo.end(); ++it)
        if (o==it->first)
        {
            cout << "Voici le chemin indirect de l'objet : " << o << endl;
            cheminIndirect(it->second);
	        cout << endl;
        }
    Reseau1::listCraftIndirectVisited = {};
}

/**
 * @brief affiche tout les attribut indirect de la map pour chaque élément de la liste
 * 
 * @param l1 liste de string 
 */
void Reseau1::cheminIndirect(list<string> l1)
{
    list<string>::iterator itfind;
    map<string,list<string>>::iterator itfind2;
    while (l1.size()!=0)
    {
        for (auto it : listCraftIndirectVisited)
        {
            itfind = find(l1.begin(), l1.end(), it);
            if (itfind != l1.end())
                l1.erase(itfind);
        }
        
        if (mapDesTransfo.size()==0) return;

        if (l1.size()==0) return;

        cout << *l1.begin() << ",  ";
        listCraftIndirectVisited.push_back(*l1.begin());
        itfind2 = mapDesTransfo.find(*l1.begin());
        
        if (itfind2 != mapDesTransfo.end())
            cheminIndirect(itfind2->second);
    }
}

void Reseau1::ajouterCraft(std::string obj, std::string const at)
{
    list<string>::iterator it2;
    for (auto it : mapDesTransfo)
        if (it.first==obj)
        {
            it2 = find(it.second.begin(), it.second.end(),at);
            if (it2==it.second.end())
            {
                it.second.push_back(at);
                mapDesTransfo[obj]=it.second;
            }
        }
}

/**
 * @brief redéfinie l'opérator ==, utiliser dans l'insertion pour les map
 * 
 * @param o1 string
 * @param o2 string 
 * @return true si les deux string sont égaux
 * @return false si les deux string ne sont pas égaux
 */
bool operator==(string o1, string o2){return o1==o2;}

/**
 * @brief redéfinie l'opérator <, utiliser dans l'insertion des map pour les triés
 * 
 * @param o1 string
 * @param o2 string
 * @return true si o1 est inférieur a o2
 * @return false si les deux string sont égaux ou que o1 est supérieur a o2
 */
bool operator<(string o1, string o2){return o1<o2;}