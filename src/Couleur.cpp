#include <iostream>
#include <stdio.h>
#include "../include/Couleur.h"

using namespace std;

void Couleur::operator+=(Couleur const& c){
	this->r+=c.r;
	this->g+=c.g;
	this->b+=c.b;
}
void Couleur::remiseAUn(){
	if(this->r > 1) this->r = 1;
	if(this->g > 1) this->g = 1;
	if(this->b > 1) this->b = 1;
}
void Couleur::operator*=(double d){
	this->r*=d;
	this->g*=d;
	this->b*=d;
}

void Couleur::operator*=(Couleur const& c){
	this->r*=c.r;
	this->g*=c.g;
	this->b*=c.b;
}

void Couleur::afficheCouleur(){
	if(this)
		printf("%.1f %.1f %.1f\n",this->r,this->g,this->b);
}

Couleur::Couleur(){
	this->r=0;
	this->g=0;
	this->b=0;
}

Couleur::Couleur(double r,double g,double b){
	this->r=r;
	this->g=g;
	this->b=b;
}

double Couleur::getR(){
	return this->r;
}
double Couleur::getG(){
	return this->g;
}
double Couleur::getB(){
	return this->b;
}
Couleur operator*(Couleur const& c1, double const d){
	Couleur copie(c1);
	copie*=d;
	return copie;
}
Couleur operator*(double const d, Couleur const& c1){
	return c1*d;
}
Couleur operator*(Couleur const& c1, Couleur const& c2){
	Couleur copie(c1);
	copie*=c2;
	return copie;
}
