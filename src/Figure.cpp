#include <iostream>
#include "../include/Figure.h"
#include "../include/Checker.h"
#include "../include/Couleur.h"

using namespace std;

Figure::Figure(Couleur* d, Couleur* s, double shi,int transf,Transformation transfoCourant,Checker dami){
	this->diffuse = d;
	this->specular = s;
	this->shininess = shi;
	this->transf = transf;
	this->transform = transfoCourant;
    this->damier = dami;
}

Checker Figure::getDamier(){
    return this->damier;
}

Figure::Figure(){
	this->diffuse = NULL;
	this->specular = NULL;
}
void Figure::affiche(){
	cout << endl <<"Diffuse :";
	this->diffuse->afficheCouleur();
	cout << endl <<"Spécular :";
	this->specular->afficheCouleur();
}

double Figure::getShininess(){
	return this->shininess;
}

Couleur Figure::getDiffuse(){
	if(this->diffuse)
		return *(this->diffuse);
	return Couleur(0,0,0);
}
Couleur Figure::getSpecular(){
	if(this->specular)
		return *(this->specular);
	return Couleur(0,0,0);
}
Figure::~Figure(){
	if(this->specular) delete(this->specular);
	if(this->diffuse) delete(this->diffuse);
}
