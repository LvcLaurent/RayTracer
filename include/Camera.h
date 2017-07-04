#ifndef _CAMERA_H
#define _CAMERA_H

#include "../include/Point.h"
#include "../include/Vecteur.h"
#include "../include/Couleur.h"


using namespace std;

typedef struct Repere{
	Vecteur u;
	Vecteur v;
	Vecteur w;
}Repere;

class Camera
{
	public:
		// Constructeur
		Camera();
		Camera(Point* oeil, Point* cible, Vecteur* direction, double fovr);
		void initRepere();
		void affiche();
		void afficheRepere();
		// Methode
		
		//Getter Setter
		Point* getOeil();
		Point* getCible();
		Vecteur* getDirection();
		Repere* getRepere();
		double getFov();
		~Camera();
	private:
		Repere repereOrth;
		Point* oeil;
		Point* cible;
		Vecteur* direction;
		double fov;
			
};
#endif

