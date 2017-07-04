#include "../include/Point.h"
#include "../include/Figure.h"
#include "../include/Triangle.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Triangle::Triangle(Point* a, Point* b, Point* c,Point* oeil, Couleur* d,Couleur* s,double shi,int transf,Transformation transfoCourant,Checker dami) : Figure(d,s,shi,transf,transfoCourant,dami){
	this->a = *a;
	this->b = *b;
	this->c = *c;
	if(transf){
		this->a=transform.mult(this->a);
		this->b=transform.mult(this->b);
		this->c=transform.mult(this->c);
	}
	this->normale = Vecteur();
	Vecteur u,v;
	this->CA = this->a - this->c;
	this->AB = this->b - this->a;
	this->BC = this->c - this->b;
	v = -1.0 * this->CA;
	this->AB.produitVectoriel(&this->normale, v);
	this->normale.normalisation();
	this->oeilCam = oeil;
	Vecteur oeilPoint = this->a - *oeil;
	this->projectionOeil = oeilPoint * this->normale;
}

Triangle::Triangle(){
	
}



Vecteur Triangle::calculNormale(Point& p){
	return this->normale;
}
double Triangle::intersection(Vecteur& d, Point& oeil){
	double projectRayon = d* this->normale;
	double res,res2; 
	double alpha, beta, gamma;
	Point p;
	Vecteur u, p_pointTri;
    Vecteur* tampon = new Vecteur();
	if(projectRayon == 0) return -1;
	if (oeil.getX() != this->oeilCam->getX() && oeil.getY() != this->oeilCam->getY() && oeil.getZ() != this->oeilCam->getZ()){
		Vecteur oeilPoint = this->a - oeil;
		res2 = oeilPoint * this->normale;
		res = res2/projectRayon;
	}
	else{
		res = this->projectionOeil/projectRayon;
	}
	if(res<EPSILON){ delete(tampon);return -1;}
	u = d*res;
	p = oeil + u;
	p_pointTri = p - this->a;
	this->AB.produitVectoriel(tampon, p_pointTri);
	if((*tampon * this->normale) < 0){ delete(tampon);return -1;}
	p_pointTri = p - this->b;
	this->BC.produitVectoriel(tampon, p_pointTri);
	if((*tampon * this->normale) < 0){ delete(tampon);return -1;}
	p_pointTri = p - this->c;
	this->CA.produitVectoriel(tampon, p_pointTri);
	if((*tampon * this->normale) < 0){ delete(tampon);return -1;}
    delete(tampon);
	return res;
}
/*bool approche2(Point& P_A){
	if(t!=-1){
		gamma = (P_A.getX() - ((P_A.getY()*this->B_A.getX())/this->B_A.getY()))/this->optiCoeff;
		beta = (-gamma * this->C_A.getY() + P_A.getY())/this->B_A.getY();
		alpha = 1 - beta - gamma;
		cout << "valeur :"<< (P_A.getY()*this->B_A.getX())/this->B_A.getY() << " " << P_A.getY() << " " << B_A.getX() << " " << B_A.getY() << endl;
		//cout << alpha << " " << beta << " " << gamma << endl;
		if(alpha + beta + gamma == 1 && alpha >= 0 && beta >= 0 && gamma >= 0) return t;
		else return -1;
	}else return t;
	return 0;
}*/
void Triangle::affiche(){
	printf("Triangle p1 : ");
	this->a.affichePoint();
	printf("\nTriangle p2 : ");
	this->b.affichePoint();
	printf("\nTriangle p3 : ");
	this->c.affichePoint();
	Figure::affiche();
}
