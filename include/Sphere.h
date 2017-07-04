#ifndef _SPHERE_H
#define _SPHERE_H

#include "../include/Point.h"
#include "../include/Figure.h"
#include "../include/Couleur.h"
#include "../include/Vecteur.h"
#include "../include/Figure.h"

using namespace std;

class Sphere : public Figure
{ 
	public:
		Sphere(Point* p, Point *oeil, double t,Couleur* d,Couleur* s,double shi,int transf,Transformation transfoCourant,Checker dami);
		void initCoeff(Point &oeil,Vecteur &oeilL,double &coeffL);
		virtual void affiche();
		virtual double intersection(Vecteur &d, Point &oeil);
		double calculDistance(Vecteur &d, Point &oeil);
		virtual Vecteur calculNormale(Point& p);
		virtual ~Sphere();
	private:
		Point* centre;
		Point* oeilCam;
		double rayon;
		double coeffA;
		double coeffB;
		double coeffC;
		double coeffL;
		Vecteur oeilL;
		Vecteur* oeilCentre;
		Matrice inverse;
}; 
#endif
