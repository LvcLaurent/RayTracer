#ifndef _SCENE_H
#define _SCENE_H

#include "../include/Data.h"

using namespace std;

class Scene
{
	public:
		~Scene();
        Scene(Data* d);
        Camera* getCamera();
        Vecteur directionPixel(int i, int j);
        void lanceurRayon(vector<unsigned char>* image);
        void initPixel(vector<unsigned char>* image, int i, int j, Couleur c);
        Point calculIntersection(double t, Point& oeil, Vecteur& d);
        Vecteur calculHalfVecteur(Vecteur& lightDir, Vecteur& d);
        double calculCosinusSpecular(Vecteur& n, Point& p, Lumiere* l, Vecteur& d,Figure* f);
        double calculCosinusDiffuse(Vecteur& n, Point& p, Lumiere* l);
        Couleur calculCouleur(double resScalaire, Lumiere* l, Couleur& diffuse);
        //Couleur calculCouleur(Vecteur& n, Vecteur& v, Point& p, Lumiere* l, Couleur& diffuse);
        double intersectionLumiere(Point &oeil, Vecteur &d);
        Vecteur calculDirectionRef(Figure* f,Vecteur d,Point p);
        void trouveFigure(Vecteur d, Point oeil,double* figureProche,Figure** figureIntersec);
        Couleur generationPixel(Point oeil,Vecteur d,Figure* figureIntersec,double figureProche);
        Couleur reflechissant(int max,Figure * fig,Vecteur d, Point p);
        void generationCouleur(Couleur* enr, Figure* figureIntersec,Point p,Vecteur n,Vecteur d);
        int getSizeHeight();
        int getSizeWidth();
        string output;
        int numLigne;
        
    private:
		int i;
		int j;
		int size_height;
        int size_width;
        int maxDepth;
		double hauteurPixel;
		double largeurPixel;
        int nbVertex;
        Camera* camera;
        vector<Point*> tabPoints;
        vector<Figure*> tabFigure;
        vector<Lumiere*> tabLumiere;
        Couleur* ambient;
        double shininess;
        Couleur refl;
        Couleur couleurPixel;
};
void encodeOneStep(const char* filename, vector<unsigned char>& image, unsigned width, unsigned height);
#endif
