#ifndef _PONCTUAL_H
#define _PONCTUAL_H


#include "../include/Point.h"
#include "../include/Couleur.h"
#include "../include/Lumiere.h"

class Ponctual : public Lumiere
{
	public:
		// Constructeur
		Ponctual(Point* v,Couleur* c);
		Vecteur getDirection(Point& p);
		virtual void affiche();
		virtual ~Ponctual();
		int testDistance(Vecteur tmpVecteur, Point p,double distanceFigure);
		// Methode
	private:
		Point* origine;
};

#endif
