#include <iostream>
#include "reseau.hpp"
#include <string>
using namespace std;


void testR1(){
	Objet bois("bois");
	Objet planche("planche");
	cout << bois;
	cout << planche;
}


int main(){
	testR1();
	return 0;
}
