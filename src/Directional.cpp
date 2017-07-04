#include <iostream>

#include "../include/Directional.h"

using namespace std;
	
Directional::Directional(Vecteur* v,Couleur* c) : Lumiere(c){
	this->direction = v;	
}

Directional::~Directional(){
	delete(this->direction);
}
Vecteur Directional::getDirection(Point& p){
	return *(this->direction);
}

int Directional::testDistance(Vecteur tmpVecteur, Point p,double distanceFigure){
	return 0;
}

void Directional::affiche(){
	cout << "\nDirectional :" << endl;
	cout << "direction : ";
	this->direction->afficheVecteur();
	cout << "couleur : ";
	this->couleur->afficheCouleur();
}
