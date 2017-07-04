#ifndef _DIRECTIONAL_H
#define _DIRECTIONAL_H


#include "../include/Point.h"
#include "../include/Couleur.h"
#include "../include/Lumiere.h"

class Directional : public Lumiere
{
	public:
		// Constructeur
		Directional(Vecteur* v,Couleur* c);
		virtual void affiche();
		Vecteur getDirection(Point& p);
		virtual ~Directional();
		int testDistance(Vecteur tmpVecteur, Point p,double distanceFigure);
		// Methode
	private:
		Vecteur* direction;
};

#endif
