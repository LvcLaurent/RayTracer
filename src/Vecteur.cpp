#include <iostream>
#include "../include/Vecteur.h"
#include <cmath>

using namespace std;
Vecteur::Vecteur():x(0),y(0),z(0)
{
}

Vecteur::Vecteur(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vecteur::~Vecteur(){ 
	
}

//accesseur
double Vecteur::getX() const{
	return this->x;
}

double Vecteur::getY() const{
	return this->y;
}

double Vecteur::getZ() const{
	return this->z;
}

//surcharge operateur de classe
void Vecteur::operator+=(Vecteur const& v){
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
}
void Vecteur::operator-=(Vecteur const& v){
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
}

void Vecteur::operator*=(double d){
	this->x *= d;
	this->y *= d;
	this->z *= d;
}

Vecteur operator+(Vecteur const& v1, Vecteur const& v2){
    Vecteur copie(v1);
    copie+=v2;
    return copie;
}

Vecteur operator-(Vecteur const& v1, Vecteur const& v2){
    Vecteur copie(v1);
    copie-=v2;
    return copie;
}

double operator*(Vecteur const& v1, Vecteur const& v2){
	return v1.getX()*v2.getX() + v1.getY()*v2.getY() + v1.getZ()*v2.getZ(); 
}

Vecteur operator*(Vecteur const& v1, double const d){
	Vecteur copie(v1);
    copie*=d;
    return copie; 
    //return Vecteur(v1.getX() * d, v1.getY() * d, v1.getZ() * d);
}

Vecteur operator*(double const d, Vecteur const& v1){
	return v1 * d;
}

//methode 
void Vecteur::autreSens(){
	this->x = -this->x;
	this->y = -this->y;
	this->z = -this->z;
}

double __attribute__ ((noinline)) Vecteur::getNorme(){
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

void Vecteur::produitVectoriel(Vecteur* res, Vecteur const& v){
	res->x = this->y*v.z - this->z*v.y;
	res->y = this->z*v.x - this->x*v.z;
	res->z = this->x*v.y - this->y*v.x;
}

//normalise un vecteur
void Vecteur::normalisation(){
	double norme = this->getNorme();
	this->x /= norme;
	this->y /= norme;
	this->z /= norme;
}

//affichage
void Vecteur::afficheVecteur(){
	cout<<"("<<this->x<<","<<this->y<<","<<this->z<<")"<<endl;	
}
