#include <iostream>
#include <stdio.h>   // pour std::string 

using namespace std;

#include "../include/Point.h"
#include "../include/Vecteur.h"
#include "../include/Couleur.h"
#include "../include/Camera.h"



Camera::Camera(Point* oeil, Point* cible, Vecteur* direction, double fovr)
{
	this->oeil = oeil;
	this->cible = cible;
	this->direction = direction;
	this->fov = fovr;
	this->initRepere();
}
Camera::Camera(){
	this->oeil = new Point(0,0,0);
	this->direction = new Vecteur(0,0,0);
	this->fov = 0;
}

Camera::~Camera(){
	delete(this->oeil);
	delete(this->cible);
	delete(this->direction);
}

void Camera::initRepere()
{	
	this->repereOrth.w = *(this->oeil) - *(this->cible);
	this->repereOrth.w *= 1/this->repereOrth.w.getNorme(); 
	this->direction->produitVectoriel(&this->repereOrth.u,this->repereOrth.w);
	this->repereOrth.u *= 1/this->repereOrth.u.getNorme(); 
	this->repereOrth.w.produitVectoriel(&this->repereOrth.v,this->repereOrth.u);
	this->repereOrth.w *= 1/this->repereOrth.w.getNorme(); 
}

void Camera::affiche(){
	printf("oeil : ");
	this->oeil->affichePoint();
	printf("\ncible : ");
	this->cible->affichePoint();
	printf("\ndirection : ");
	this->direction->afficheVecteur();
	printf("\nfov : %f\n",this->fov);
}
void Camera::afficheRepere(){
	printf("u : ");
	this->repereOrth.u.afficheVecteur();
	printf("v : ");
	this->repereOrth.v.afficheVecteur();
	printf("w: ");
	this->repereOrth.w.afficheVecteur();
} 
Point* Camera::getOeil(){
	return this->oeil;
}
Point* Camera::getCible(){
	return this->cible;
}
Repere* Camera::getRepere(){
	return &(this->repereOrth);
}
Vecteur* Camera::getDirection(){
	return this->direction;
}
double Camera::getFov(){
	return this->fov;
}
	

