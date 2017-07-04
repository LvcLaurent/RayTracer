
#include <iostream>
#include <cmath>
#include "../include/Transformation.h"

using namespace std;

Transformation::Transformation() : Matrice(4) {
	this->initIdentite();
}
void Transformation::initTranslate(Vecteur v){
	this->grille[0][3] = v.getX();
	this->grille[1][3] = v.getY();
	this->grille[2][3] = v.getZ();
}
void Transformation::initScale(Vecteur v){
	this->grille[0][0] = v.getX();
	this->grille[1][1] = v.getY();
	this->grille[2][2] = v.getZ();
}
void Transformation::initRotate(double angle, Vecteur v){
	double x = v.getX(), y = v.getY(), z = v.getZ(), tmp, sinus, cosinus;
	Matrice m = Matrice(3);
	Matrice m_prime = Matrice(3);
	Matrice identite = Matrice(3);
	Matrice res = Matrice(3);
	identite.initIdentite();
	
	m.initCase(0,0,x*x);
	m.initCase(1,1,y*y);
	m.initCase(2,2,z*z);
	tmp = x*y;
	m.initCase(0,1,tmp);
	m.initCase(1,0,tmp);
	tmp = x*z;
	m.initCase(2,0,tmp);
	m.initCase(0,2,tmp);
	tmp = y*z;
	m.initCase(1,2,tmp);
	m.initCase(2,1,tmp);
	
	m_prime.initCase(0,1,-z);
	m_prime.initCase(1,0,z);
	m_prime.initCase(0,2,y);
	m_prime.initCase(2,0,-y);
	m_prime.initCase(1,2,-x);
	m_prime.initCase(2,1,x);
	
	cosinus = cos(angle);
	sinus = sin(angle);
	res = identite * cosinus + m * (1 - cosinus) + m_prime * sinus;
	this->copie(res);
	
}

void Transformation::affiche(){
	cout << "vecteur : ";
	//this->v.afficheVecteur();
}
Transformation::~Transformation(){
	
}
