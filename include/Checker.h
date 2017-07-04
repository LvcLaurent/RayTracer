#ifndef _CHECKER_H
#define _CHECKER_H

#include "../include/Couleur.h"
#include "../include/Point.h"

class Checker{
	public:
		// Constructeur
        Checker();
		Checker(double taille,Couleur c1,Couleur c2);
        Couleur getCoul1();
        Couleur getCoul2();
        int getTaille();
        Couleur getCouleur(Point& p);
	private:
		int taille;
        Couleur coul1;
        Couleur coul2;
};

#endif
