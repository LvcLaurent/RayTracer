#include <iostream>

#include "../include/Ponctual.h"

using namespace std;
	
Ponctual::Ponctual(Point* p,Couleur* c) : Lumiere(c){
	this->origine = p;
}

Ponctual::~Ponctual(){
	delete(this->origine);
}
Vecteur Ponctual::getDirection(Point& p){
	Vecteur tmp = *(this->origine) - p;
	tmp.normalisation();
	return tmp;
}

int Ponctual::testDistance(Vecteur tmpVecteur, Point p,double distanceFigure){
	Vecteur tmp = *(this->origine) - p;
	double test = tmp.getNorme();
	if (test > distanceFigure)
		return 0;
	else
		return 1;
}

void Ponctual::affiche(){
	cout << "\nPonctual :" << endl;
	cout << "origine : ";
	this->origine->affichePoint();
	cout << "couleur : ";
	this->couleur->afficheCouleur();
}

