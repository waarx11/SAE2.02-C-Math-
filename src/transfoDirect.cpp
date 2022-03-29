#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include "transfoDirect.hpp"
using namespace std;

vector<string> Direct::listCraftIndirectVisited;

Direct::Direct(){}

// void Direct::ajouterObjet(string o){
//     vector<string>::iterator it;
//     it = find(Direct::listObjet.begin(), Direct::listObjet.end(), o);
//     if (it == Direct::listObjet.end())
//         Direct::listObjet.push_back(o);
// }

void Direct::insertCraft(string o, list<string> l1)
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

void Direct::afficherObjet() const
{
    for (auto it : mapDesTransfo)
        cout << it.first << endl;
}

void Direct::afficherObjetCraft() const
{
    for(auto it : mapDesTransfo)
    {
        cout << "Voici les crafts pour l'objets " << it.first << " :" << endl;
        this->afficherCraft(it.second);
    }
}

void Direct::afficherCraft(list<string> l1) const
{
    for (auto it : l1)
        cout << "   " << it << endl;
}

void Direct::supprimerObjet(std::string o)
{
//     for (auto it=mapDesTransfo.begin(); it!=mapDesTransfo.end(); ++it)
//     {
//         if (o==it->first)
//         {
//             mapDesTransfo.erase(it);
//             cout << "Objet " << o << " supprimer avec succès!"<<endl;
//         }
//     }
}

void Direct::appCheminIndirect(string o)
{
    cout << "Voici le chemin indirect de l'objet : " << o << endl;
    for (auto it=mapDesTransfo.begin(); it!=mapDesTransfo.end(); ++it)
        if (o==it->first)
            cheminIndirect(it->second);
}

void Direct::cheminIndirect(list<string> l1)
{
    list<string>::iterator itfind;
    map<string,list<string>>::iterator itfind2;
    for (auto it : listCraftIndirectVisited)
    {
        itfind = find(l1.begin(), l1.end(), it);
        if (itfind != l1.end())
            l1.erase(itfind);
    }
    
    if (l1.size()==0)
    {
        return;
    }
    
    if (mapDesTransfo.size()==0)
        return;

    cout << "  " << *l1.begin() << endl;
    listCraftIndirectVisited.push_back(*l1.begin());
    itfind2 = find(mapDesTransfo.begin(), mapDesTransfo.end(), *l1.begin());
    if (itfind2 != mapDesTransfo.end())
        cheminIndirect(mapDesTransfo.find(((*l1.begin())))->second);
}

// void Matrice::ajouterCraft(string o1, string o2){
//     int pos1=0,pos2=0;
//     for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
//         if (*it==o1){
//             break;
//         }
//         pos1++;
//     }

//     for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
//         if (*it==o2){
//             break;
//         }
//         pos2++;
//     }
//     if(pos1==int(tableauObjet.size()) || pos2==int(tableauObjet.size()))
//     {
//         cout<< "Pas trouvé"<<endl;;
//         return;
//     }
//     matriceCraft.push_back({0});
//     matriceCraft[pos1][pos2]=true;
// }

// void Matrice::supprimerCraft(string o1, string o2){
//     int pos1=0,pos2=0;
//     for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
//         if (*it==o1){
//             break;
//         }
//         pos1++;
//     }

//     for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
//         if (*it==o2){
//             break;
//         }
//         pos2++;
//     }
//     if(pos1==int(tableauObjet.size()) || pos2==int(tableauObjet.size()))
//     {
//         cout<< "Pas trouvé"<<endl;;
//         return;
//     }
//     matriceCraft[pos1][pos2]=false;
// }

// void Matrice::afficherCraft(string o){
//     int pos=0,pos2;
//     for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
//         if (*it==o){
//             break;
//         }
//         pos++;
//     }
//     if(pos==tableauObjet.size())
//     {
//         cout << "Objet introuvable !" <<endl;
//         return;
//     }

//     cout<< "Craft à partir de : "<< o << endl;
//     for(pos2=0;pos2<int(tableauObjet.size());pos2++){
//         if(matriceCraft[pos][pos2]==true){
//             cout<<tableauObjet[pos2]<<", ";
//         }
//     }
//     cout<<endl;
// }


// void Matrice::afficherCraftsuccessifGlob(string o){
//     int pos=0,pos2;
//     vector<string> visited;
//     for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
//         if (*it==o){
//             break;
//         }
//         pos++;
//     }
//     if(pos==tableauObjet.size())
//     {
//         cout << "Objet introuvable !" <<endl;
//         return;
//     }
//     cout<< "Craft grâce à : "<< o << endl;
//     for(pos2=0;pos2<int(tableauObjet.size());pos2++){
//         if(matriceCraft[pos][pos2]==true){
//             auto it=visited.begin();
//             for(it;it!=visited.end();it++)
//                 if(tableauObjet[pos2]==*it)
//                     break;
//             if(it==visited.end())
//             { 
//                 cout<<tableauObjet[pos2]<<", ";
//                 visited.push_back(tableauObjet[pos2]);
//                 visited=afficherCraftsuccessif(tableauObjet[pos2],visited);
//             } 
//         }
//     }
// }

// vector<string> Matrice::afficherCraftsuccessif(string o,vector<string> visited){
//     int pos=0,pos2;
//     for(vector<string>::iterator it = tableauObjet.begin(); it != tableauObjet.end(); it++){
//         if (*it==o){
//             break;
//         }
//         pos++;
//     }

//     for(pos2=0;pos2<int(tableauObjet.size());pos2++){
//         if(matriceCraft[pos][pos2]==true){
//             auto it=visited.begin();
//             for(it;it!=visited.end();it++)
//                 if(tableauObjet[pos2]==*it)
//                     break;
//             if(it==visited.end())
//             { 
//                 cout<<tableauObjet[pos2]<<", ";
//                 visited.push_back(tableauObjet[pos2]);
//                 visited=afficherCraftsuccessif(tableauObjet[pos2],visited);
//             } 
//         }
//     } 
//     return visited;
// } 

// void supprimerObjet(std::string o)
// {
//     for(list<string>::iterator it = listObjet.begin(); it != listObjet.end(); it++){
//         if (*it==o){
             
//             return;
//         }
//     }
//     listObjet.push_back(o);
// }

bool operator==(string o1, string o2){return o1==o2;}
bool operator<(string o1, string o2){return o1<o2;}
// ostream& operator<<(ostream& s, string o)
// {
//     s << "Objet : " << o << endl;
//     return s;
// }