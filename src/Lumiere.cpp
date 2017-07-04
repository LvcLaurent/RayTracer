
#include <iostream>
#include "../include/Lumiere.h"

using namespace std;

Lumiere::Lumiere(Couleur *c){
	this->couleur = c;
}
void Lumiere::affiche(){
	cout << "couleur : ";
	this->couleur->afficheCouleur();
}
Couleur Lumiere::getCouleur(){
	return *(this->couleur);
}
Lumiere::~Lumiere(){
	delete this->couleur;
}
