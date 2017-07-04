#include "../include/Point.h"
#include "../include/Figure.h"
#include "../include/Sphere.h"
#include "../include/Vecteur.h"
#include "../include/Transformation.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

Sphere::~Sphere(){
	//if(this->oeilCentre) delete(this->oeilCentre);
	//if(this->centre) delete(this->centre);
    //if(this->oeilCam) delete(this->oeilCam);
}

Sphere::Sphere(Point* p, Point* oeil, double d,Couleur* di,Couleur* s,double shi,int transf,Transformation transfoCourant,Checker dami) : Figure(di,s,shi,transf,transfoCourant,dami){
	this->centre = p;
	this->rayon = d;
	this->coeffA = 1;
	this->oeilCam = oeil;
	this->oeilCentre = new Vecteur(oeil->getX()-this->centre->getX(), oeil->getY()-this->centre->getY(), oeil->getZ()-this->centre->getZ());
	this->coeffC = oeilCentre->getX()*oeilCentre->getX()+oeilCentre->getY()*oeilCentre->getY()+oeilCentre->getZ()*oeilCentre->getZ()-this->rayon*this->rayon;
	this->coeffC *=4.0d;
	this->inverse = this->transform.inversion();
}
void Sphere::initCoeff(Point &oeil,Vecteur &oeilL,double &coeffL){
	oeilL = oeil - *this->centre ;
	coeffL = oeilL.getX()*oeilL.getX()+oeilL.getY()*oeilL.getY()+oeilL.getZ()*oeilL.getZ()-this->rayon*this->rayon; 	 
	coeffL *=4;
}
void Sphere::affiche(){
	cout << "Sphere centre : ";
	this->centre->affichePoint();
	cout << endl << "Rayon :"<< this->rayon;
	cout << endl << "Diffuse : ";
	Figure::affiche();
	cout << endl << "======================" << endl;
}
double Sphere::intersection(Vecteur &d, Point &oeil){
	double discriminant, x, rac, res, tmp;
	Vecteur dprime;
	Point oprime, pointTrans;
	Point pprime;
	Vecteur po;
	Vecteur distance;
	//this->inverse.toString();
	if(this->transf){
		dprime = this->inverse.mult(d);
		dprime.normalisation();
		oprime = this->inverse.mult(oeil);
		res = this->calculDistance(dprime, oprime);
		/*cout << endl;
		dprime.afficheVecteur();
		oprime.affichePoint();
		if((int)res == -1){cout << "ohoh" << endl; return -1;}*/
		if (res != -1){
			distance = dprime * res;
			pprime = oprime + distance;
			pointTrans = this->transform.mult(pprime);
			po = pointTrans - oeil;
			if((tmp = d.getX()) != 0) res = (po.getX())/tmp;
			else if((tmp = d.getY()) != 0) res = (po.getY())/tmp;
			else if((tmp = d.getZ()) != 0) res = (po.getZ())/tmp;
			else res = -1;
		}
	}else{
		res = this->calculDistance(d, oeil);
	}
	return res;
}
double Sphere::calculDistance(Vecteur &d, Point &oeil){
	double discriminant, x, rac, res;
	//if (this->oeilCam->compare(oeil) || this->oeilPrime.compare(oeil)){
        Vecteur oeilL(0,0,0);
        double coeffL = 0;
		this->initCoeff(oeil,oeilL,coeffL);
		d.normalisation();
		double coeffB = 2*(oeilL.getX()*d.getX()+oeilL.getY()*d.getY()+oeilL.getZ()*d.getZ());
		discriminant = coeffB * coeffB - coeffL;
	/*}
	else{
		this->coeffB = 2*(oeilCentre->getX()*d.getX()+oeilCentre->getY()*d.getY()+oeilCentre->getZ()*d.getZ());
		discriminant = this->coeffB * this->coeffB - this->coeffC;
	}*/
	if(discriminant > 0){
		rac = sqrt(discriminant);
		x=-coeffB - sqrt(discriminant);
		if(x>EPSILON) res = x / 2;
		else
		{
			x=-coeffB + sqrt(discriminant);
			if (x>EPSILON) res = x / 2;
			else res = -1;
		}
	}else if(!discriminant){
		res = -coeffB / 2;
		
	}else
		return -1;
	return res;
}
Vecteur Sphere::calculNormale(Point& p){
	Vecteur res;
	Point pointNonTrans;
	Matrice transpose = Matrice(4);
	if(this->transf){
		pointNonTrans = this->inverse.mult(p);
		res = pointNonTrans - *(this->centre);
	}
	else res = p - *(this->centre);
	transpose = this->inverse.transposer();
	if(this->transf) res = transpose.mult(res);
	res.normalisation();
	return res;
}


