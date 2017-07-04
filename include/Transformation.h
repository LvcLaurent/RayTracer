#ifndef _TRANSFORMATION_H
#define _TRANSFORMATION_H

#include "../include/Couleur.h"
#include "../include/Vecteur.h"
#include "../include/Point.h"
#include "../include/Matrice.h"

class Transformation : public Matrice {
	public :
		Transformation();
		~Transformation();
		void initTranslate(Vecteur v);
		void initRotate(double angle, Vecteur v);
		void initScale(Vecteur v);
		virtual void affiche();
};
#endif
