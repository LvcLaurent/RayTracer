#include <iostream>

#include "../include/Checker.h"
#include <math.h>

using namespace std;

Checker::Checker(){
    this->taille = 0;    
}
	
Checker::Checker(double taille,Couleur c1,Couleur c2){
	this->taille = taille;
    this->coul1 = c1;
    this->coul2 = c2;
}

int Checker::getTaille(){
    return this->taille;
}

Couleur Checker::getCoul1(){
    return this->coul1;
}

Couleur Checker::getCoul2(){
    return this->coul2;
}

Couleur Checker::getCouleur(Point& p){
    double x=fmod(p.getX(),this->taille * 2);
    double z=fmod(p.getZ(),this->taille * 2);
    int n = 0;
    if(fabs(x) >= this->taille)
        n++;
    if(fabs(z) >= this->taille)
        n++;
    if(n!=1) return this->coul2;
    else return this->coul1;
}
