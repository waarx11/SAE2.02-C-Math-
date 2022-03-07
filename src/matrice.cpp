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
    for(int i=0;i<int(tableauObjet.size())-1;i++){
        // matriceCraft[i].push_back(0);
        // matriceCraft[int(tableauObjet.size())-1].push_back(0);
        matriceCraft[0][0]=0;
        // matriceCraft[int(tableauObjet.size())-1][0]=0;
        cout<<i<<endl;
    }
    // matriceCraft[int(tableauObjet.size())-1].push_back(0);
}