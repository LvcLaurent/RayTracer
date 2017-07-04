#ifndef _PLAN_H
#define _PLAN_H

#include "../include/Point.h"
#include "../include/Vecteur.h"
#include "../include/Figure.h"
#include "../include/Couleur.h"
#include "../include/Figure.h"

using namespace std;

class Plan : public Figure
{ 
	public:
		Plan(Point* p, Point* oeil, Vecteur* v,Couleur* d,Couleur* s,double shi,int transf,Transformation transfoCourant,Checker dami);
		Plan();
		double intersection(Vecteur &d, Point &oeil);
		void affiche();
		Vecteur calculNormale(Point &p);
		virtual ~Plan();
	private:
		Point* oeilCam;
		Couleur* diffuse;
		Couleur* specular;
		Point* point;
		Vecteur normale;
		double projectionOeil;
}; 

#endif
