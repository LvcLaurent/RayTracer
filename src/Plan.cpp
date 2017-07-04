#include "../include/Point.h"
#include "../include/Figure.h"
#include "../include/Triangle.h"
#include "../include/Vecteur.h"
#include "../include/Plan.h"
#include "../include/Sphere.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Plan::Plan(Point* p, Point* oeil, Vecteur* v,Couleur* d,Couleur* s,double shi,int transf,Transformation transfoCourant,Checker dami) : Figure(d,s,shi,transf,transfoCourant,dami){
	this->point = p;
	this->oeilCam = oeil;
	this->normale = Vecteur(*v);
    this->normale.normalisation();
	Vecteur oeilPoint = *this->point - *oeil;
	this->projectionOeil = oeilPoint * this->normale;
}
double Plan::intersection(Vecteur &d, Point &oeil){
	double projectRayon = d * this->normale;
	double res,res2;
	if(projectRayon == 0) return -1;
	if (oeil.getX() != this->oeilCam->getX() && oeil.getY() != this->oeilCam->getY() && oeil.getZ() != this->oeilCam->getZ()){
		Vecteur oeilPoint = *this->point - oeil;
		res2 = oeilPoint * this->normale;
		res = res2/projectRayon;
		//return -1;
	}
	else 
		res = this->projectionOeil/projectRayon;
	if(res<EPSILON) return -1;
	return res;
}

Plan::Plan(){
	this->projectionOeil =0;
}
Plan::~Plan(){
}
Vecteur Plan::calculNormale(Point& p){
	return this->normale;
}
void Plan::affiche(){
	cout << endl <<"Plan Point : ";
	this->point->affichePoint();
	cout << endl <<"Normale : ";
	this->normale.afficheVecteur();
	Figure::affiche();
}
