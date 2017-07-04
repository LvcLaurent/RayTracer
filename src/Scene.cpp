//#define EPSILON 0.00001

#include <cstring>
#include <iostream> // pour std::cout 
#include <string>   // pour std::string 
#include <math.h>
#include <typeinfo>
#include <stdio.h>
#include <mutex>


#include "../include/lodepng.h"
#include "../include/Scene.h"
#include "../include/Data.h"
#include "../include/Camera.h"
#include "../include/Couleur.h"
#include "../include/Point.h"
#include "../include/Vecteur.h"

using namespace std;

Scene::Scene(Data* d){
	this->maxDepth = d->getMaxDepth();
	this->shininess = d->getShininess();
    this->camera = d->getCamera();
    this->tabPoints = d->getTabPoints();
    this->tabLumiere = d->getTabLumiere();
    this->tabFigure = d->getTabFigure();
    this->size_width = d->getWidth();
    this->size_height = d->getHeight();
    this->hauteurPixel = tan(this->camera->getFov()/2);
    this->largeurPixel = this->hauteurPixel*(double) (this->size_width)/this->size_height;
    this->ambient = d->getAmbient();
    this->output = d->getOutput();
    this->numLigne = 0;
}	

void Scene::trouveFigure(Vecteur d, Point oeil,double *figureProche,Figure** figureIntersec){
	double tmp;
	for(int k=0; k<this->tabFigure.size(); k++){
		if(*figureProche == -1){
			*figureProche = this->tabFigure[k]->intersection(d,oeil);
			*figureIntersec = this->tabFigure[k];
		} 
		else{
			tmp = this->tabFigure[k]->intersection(d,oeil);
			if(tmp!=-1 && tmp < *figureProche) {
				*figureProche = tmp;
				*figureIntersec = this->tabFigure[k]; 
			}
		}
	}
}

void Scene::generationCouleur(Couleur* enr, Figure* figureIntersec,Point p,Vecteur n,Vecteur d){
	Couleur diffuseFigure,specularFigure;
	double tmp = 0, figureProche,distanceFig = 0;
	Vecteur tmpVecteur;
    if(figureIntersec->getDamier().getTaille()){
        diffuseFigure = figureIntersec->getDamier().getCouleur(p);
    }
    else
	    diffuseFigure = figureIntersec->getDiffuse();
	specularFigure = figureIntersec->getSpecular();
	
	for(int k=0; k<this->tabLumiere.size(); k++){
		tmpVecteur = this->tabLumiere[k]->getDirection(p);
		figureProche = -1;
		for(int z=0; z<this->tabFigure.size(); z++){
			if (figureProche == -1 ){
				figureProche = this->tabFigure[z]->intersection(tmpVecteur,p);
				if (this->tabLumiere[k]->testDistance(tmpVecteur, p, figureProche)) figureProche = -1;
			}
		}
		if(figureProche == -1){
			tmp = this->calculCosinusDiffuse(n, p, this->tabLumiere[k]);
			*enr+=this->calculCouleur(tmp, this->tabLumiere[k], diffuseFigure);
			if (figureIntersec->getSpecular().getR()!=0 || figureIntersec->getSpecular().getG()!=0 || figureIntersec->getSpecular().getB()!=0){
				tmp = this->calculCosinusSpecular(n, p, this->tabLumiere[k], d,figureIntersec);
				*enr+=this->calculCouleur(tmp, this->tabLumiere[k], specularFigure);
			}
		}
	}
	
}

Couleur Scene::generationPixel(Point oeil,Vecteur d,Figure* figureIntersec,double distance){
	Couleur diffuseFigure,specularFigure;
	Couleur calcul, couleurPixel;
	double tmp = 0, figureProche ;
	Vecteur n;
	Point p = this->calculIntersection(distance, oeil, d);
	n = figureIntersec->calculNormale(p);
	generationCouleur(&couleurPixel,figureIntersec,p,n,d);
	if (figureIntersec->getSpecular().getR()!=0 || figureIntersec->getSpecular().getG()!=0 || figureIntersec->getSpecular().getB()!=0){
		this->refl=this->reflechissant(this->maxDepth,figureIntersec,d,p);
		couleurPixel += this->refl;
	}
	if(this->ambient)
		couleurPixel+=*(this->ambient);
	couleurPixel.remiseAUn();
    return couleurPixel;
}

Couleur Scene::reflechissant(int max,Figure * fig,Vecteur d, Point p){
	Couleur specularFigure, diffuseFigure, spe = fig->getSpecular(),couleurFigure;
	Couleur coulTmp = Couleur(0,0,0);
	if (max < 2) return coulTmp;
	double tmp,figureProche=-1;
	Vecteur tmp2;
	Figure* figureIntersec=NULL;
	Vecteur r = calculDirectionRef(fig,d,p);
	trouveFigure(r, p,&figureProche,&figureIntersec);
	if(figureProche!=-1){
		Point poi = this->calculIntersection(figureProche, p, r);
		tmp2 = figureIntersec->calculNormale(poi);
		if (figureIntersec->getSpecular().getR()!=0 || figureIntersec->getSpecular().getG()!=0 || figureIntersec->getSpecular().getB()!=0){
			coulTmp += reflechissant(max-1,figureIntersec,r,poi);
		}
		if(this->ambient)
			coulTmp+=*(this->ambient);
		generationCouleur(&coulTmp,figureIntersec,poi,tmp2,r);
		coulTmp*=fig->getSpecular();
	}
	return coulTmp;
}

int Scene::getSizeHeight(){
	return size_height;
}

int Scene::getSizeWidth(){
	return size_width;
}

void Scene::lanceurRayon(vector<unsigned char>* image){
	std::mutex mutex;
    int j;
    double figureProche;
	Figure* figureIntersec = NULL;
	Lumiere* tmpLum;
	Couleur couleurNoir, couleurPixel;
	Vecteur d;
	Point oeil(*(this->camera->getOeil()));
	unsigned width = this->size_width, height = this->size_height;
	
	/*for(int k=0; k<this->tabLumiere.size(); k++){
		this->tabLumiere[k]->affiche();
	}*/
    mutex.lock();
    j = this->numLigne++;
    mutex.unlock();
    while(j < height){ 
        for(int i = 0; i < width; i++){
            couleurPixel = Couleur(0,0,0);
            this->refl = Couleur(0,0,0);
            d = this->directionPixel(i,j);
            figureProche = -1;
            this->trouveFigure(d,oeil,&figureProche,&figureIntersec);
            if(figureProche != -1){
                couleurPixel = this->generationPixel(oeil,d,figureIntersec,figureProche);
                this->initPixel(image, i, j, couleurPixel);
                
            }else{
                this->initPixel(image, i, j, couleurNoir);
            }
        }
        mutex.lock();
        j = this->numLigne++;
        mutex.unlock();
    }
	//encodeOneStep(this->output.c_str(), image, width, height);
}


double Scene::calculCosinusDiffuse(Vecteur& n, Point& p, Lumiere* l){
	double resScalaire;
	Vecteur v = l->getDirection(p);
	v.normalisation();
	resScalaire = n*v;
	if(resScalaire<EPSILON) resScalaire=0;
	return resScalaire;
}
double Scene::calculCosinusSpecular(Vecteur& n, Point& p, Lumiere* l, Vecteur& d,Figure* f){
	double resScalaire;
	Vecteur v = l->getDirection(p);
	v.normalisation();
	v = this->calculHalfVecteur(v, d); 
	resScalaire = n*v;
	if(resScalaire<EPSILON) resScalaire=0;
	else resScalaire = pow(resScalaire, f->getShininess());
	return resScalaire;
}
Vecteur Scene::calculHalfVecteur(Vecteur& lightDir, Vecteur& d){
	Vecteur oppose = -1 * d;
	//Vecteur oppose = *(this->camera->getOeil()) - *(this->camera->getCible());
	Vecteur res = lightDir + oppose;
	res.normalisation();
	return res;
}
Couleur Scene::calculCouleur(double resScalaire, Lumiere* l, Couleur& diffuse){
	Couleur resCouleur = l->getCouleur();
	resCouleur *= resScalaire;
	//resCouleur.remiseAUn();
	return resCouleur * diffuse;
}

Point Scene::calculIntersection(double t, Point& oeil, Vecteur& d){
	Vecteur u = d*t;
	return oeil + u; 
}

Vecteur Scene::calculDirectionRef(Figure* f,Vecteur d,Point p){
	Vecteur res,tmp(-1 * d);
	double l;
	Vecteur n(f->calculNormale(p));
	l= tmp * n;
	res = l * n;
	res = 2 * res;
	res = d + res;
	return res;
}

void Scene::initPixel(vector<unsigned char>* image, int i, int j, Couleur c){
	(*image)[4 * this->size_width * (this->size_height - j-1) + 4 * i + 0] = 255.0*c.getR()+0.5;
	(*image)[4 * this->size_width * (this->size_height - j-1) + 4 * i + 1] = 255.0*c.getG()+0.5;
	(*image)[4 * this->size_width * (this->size_height - j-1) + 4 * i + 2] = 255.0*c.getB()+0.5;
	(*image)[4 * this->size_width * (this->size_height - j-1) + 4 * i + 3] = 255;
} 
Camera* Scene::getCamera()
{
	return this->camera;
}
Vecteur Scene::directionPixel(int i, int j){
	double a,b,tmp;
	Vecteur d;
	Repere* r;
	tmp = this->size_width/2.0d;
	a = (this->largeurPixel * (i-tmp+0.5))/tmp;
	tmp = this->size_height/2.0d;
	b = (this->hauteurPixel * (j-tmp+0.5))/tmp;
	r = this->camera->getRepere();
	d = (r->u*a) + (r->v*b) - r->w;
	d.normalisation();
	//cout << "largeur pixel : " << this->largeurPixel << " hauteur pixel : " << this->hauteurPixel << endl;	
	return d;
}



void encodeOneStep(const char* filename, vector<unsigned char>& image, unsigned width, unsigned height){
  //Encode the image
  unsigned error = lodepng::encode(filename, image, width, height);

  //if there's an error, display it
  if(error) cout << "encoder error " << error << ": "<< lodepng_error_text(error) << endl;
}


Scene::~Scene(){
	//for(i=0; i<this->tabFigure.size(); i++) delete(this->tabFigure[i]);
}
