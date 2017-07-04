#ifndef _MATRICE_H
#define _MATRICE_H

#include <iostream>

#include <vector>
#include "../include/Point.h"
#include "../include/Vecteur.h"

using namespace std;

class Matrice {
	
	// Atributs
	protected:
		vector< vector<double	> > grille;
		int taille;
		
	//Methode
	public:
		//constructeurs
		Matrice();
		Matrice(int taille);
		Matrice(Matrice const& matACopier);
		
		void initIdentite();
		void initCase(int i, int j, double elt);
		void copie(Matrice& ACopier);
		Matrice transposer();
		double determinant();
		Matrice comatrice();
		void reduction(Matrice&, int, int);
		Matrice inversion();
		Point mult(Point& pointATransform);
		Vecteur mult(Vecteur& vecteurATranform);
		void toString() const;
		
		//accesseur
		int getTaille() const;
		//operateur
		void operator+=(Matrice const& m);
		void operator-=(Matrice const& m);
		void operator*=(Matrice const& m);
		void operator*=(double d);
};
Matrice operator+(Matrice const& m1,Matrice const& m2);
Matrice operator-(Matrice const& m1,Matrice const& m2);
Matrice operator*(Matrice const& m1,Matrice const& m2);
Matrice operator*(Matrice const& m1, double d);

#endif

