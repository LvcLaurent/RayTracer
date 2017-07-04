#ifndef _LUMIERE_H
#define _LUMIERE_H

#include "../include/Couleur.h"
#include "../include/Vecteur.h"
#include "../include/Point.h"

class Lumiere{
	public :
		Lumiere(Couleur* c);
		virtual void affiche();
		virtual ~Lumiere();
		Couleur getCouleur();
		virtual Vecteur getDirection(Point& p) = 0;
		virtual int testDistance(Vecteur tmpVecteur, Point p,double distanceFigure) = 0 ;
	protected:
		Couleur* couleur;
};
#endif
