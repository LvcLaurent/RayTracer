#ifndef _FIGURE_H
#define _FIGURE_H
#define EPSILON 0.00001

#include "../include/Point.h"
#include "../include/Couleur.h"
#include "../include/Vecteur.h"
#include "../include/Checker.h"
#include "../include/Transformation.h"

class Figure // classe abstraite 
{ 
	public:
		Figure(Couleur* d, Couleur* s,double shi,int transf,Transformation transfoCourant,Checker dami);
		Figure();
		virtual ~Figure();
		virtual double intersection(Vecteur& d,Point& oeil) = 0;
		virtual void affiche();
		virtual Vecteur calculNormale(Point& p) = 0;
		Couleur getDiffuse();
		double getShininess();
		Couleur getSpecular();
        Checker getDamier();
		
	protected:
		int transf;
		Transformation transform;
		Couleur* diffuse;
		Couleur* specular;
		double shininess;
        Checker damier;

};

#endif
