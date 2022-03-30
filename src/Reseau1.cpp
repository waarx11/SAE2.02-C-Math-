#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include "Reseau1.hpp"
using namespace std;

vector<string> Reseau1::listCraftIndirectVisited;

Reseau1::Reseau1(){}

// void Direct::ajouterObjet(string o){
//     vector<string>::iterator it;
//     it = find(Direct::listObjet.begin(), Direct::listObjet.end(), o);
//     if (it == Direct::listObjet.end())
//         Direct::listObjet.push_back(o);
// }

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

void Reseau1::afficherObjet() const
{
    for (auto it : mapDesTransfo)
        cout << it.first << endl;
}

void Reseau1::afficherObjetCraft() const
{
    for(auto it : mapDesTransfo)
    {
        cout << "Voici les crafts pour l'objets " << it.first << " :" << endl;
        this->afficherCraft(it.second);
    }
}

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

void Reseau1::afficherCraft(list<string> l1) const
{
    for (auto it : l1)
        cout << "   " << it << endl;
}

void Reseau1::supprimerObjet(std::string o)
{
    map<string,list<string>>::iterator it;
    it = mapDesTransfo.find(o);
    mapDesTransfo.erase(it);
    cout << "Objet " << o << " supprimer avec succès!"<<endl;
}

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

bool operator==(string o1, string o2){return o1==o2;}
bool operator<(string o1, string o2){return o1<o2;}