#ifndef _TRIANGLE_H
#define _TRIANGLE_H
#define NB_POINTS 3

#include "../include/Point.h"
#include "../include/Figure.h"
#include "../include/Couleur.h"
#include "../include/Plan.h"

using namespace std;

class Triangle : public Figure
{
	public:
		Triangle();
		Triangle(Point* a, Point* b, Point* c, Point* oeil, Couleur* d,Couleur* s,double shi,int transf,Transformation transfoCourant,Checker dami);
		virtual double intersection(Vecteur& d, Point& oeil);
		virtual void affiche();
		virtual Vecteur calculNormale(Point& p);
	private:
		Point a;
		Point b;
		Point c;
		Vecteur normale;
		Point* oeilCam;
		double projectionOeil;
		Vecteur BC;
		Vecteur AB;
		Vecteur CA;
		//double optiCoeff;
}; 

#endif
