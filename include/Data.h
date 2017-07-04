#ifndef _DATA_H
#define _DATA_H
#define CAMERA 10
#define TAB3 20

#include <vector>
#include "../include/Point.h"
#include "../include/Triangle.h"
#include "../include/Sphere.h"
#include "../include/Plan.h"
#include "../include/Camera.h"
#include "../include/Directional.h"
#include "../include/Checker.h"
#include "../include/Ponctual.h"
#include "../include/Transformation.h"
#include <string>   // pour std::string 

using namespace std;

class Data
{
	public:
		Data();
        void miseAJourData(string c) ;
        void recSize(char* p);
        void recOutput(char* c);
        void recCamera(char* c);
        void recAmbient(char* c);
        void recDiffuse(char* c);
        void afficheData();
        void recSpecular(char* c);
        void recDirectional(char* p);
        void recPoint(char *p);
        void recMaxverts(char *p);
        void recVertex(char *p);
        void recTri(char *p);
        void recSphere(char *p);
        void recPlan(char *p);
        void recShininess(char *p);
        void recMaxDepth(char *p);
        void recRotate(char *p);
        void recScale(char *p);
        void recTranslate(char *p);
        void recPushTransformation();
        void recPopTransformation();
        void recChecker(char *p);

		double getShininess();
		int getWidth();
		void setWidth(int width);
		int getHeight();
		int getMaxDepth();
		void setHeight(int height);
		Camera* getCamera();
		vector<Point*> getTabPoints();
		vector<Lumiere*> getTabLumiere();
		vector<Figure*> getTabFigure();
		Couleur* getAmbient();
		string getOutput();
        ~Data();
	private:
		int maxDepth;
		int transf;
		int size_height;
        int size_width;
        int lecture;
        int damierBoul;
        int maxverts;
        double shininess;
		string output;
        Camera* camera;
        Couleur* ambient;
        Couleur* diffuse;
        Couleur* specular;
        vector<Transformation> pileTransform;
        vector<Point*> tabPoints;
        vector<Figure*> tabFigure;
        vector<Lumiere*> tabLumiere;
        Checker damier;
        //changer tableau en vector TODO
};

//lecture du fichier
Data* parcours (char *nomF);
//calcul de la taille d'un entier
int calcul(int nombre);
void extraireDouble(char** p, double& a, double& b, double& c);
#endif
