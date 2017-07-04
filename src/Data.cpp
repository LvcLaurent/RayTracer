#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <cstring>
#include <iostream> // pour std::cout 
#include <string>   // pour std::string 

#include "../include/Camera.h"
#include "../include/Data.h"



#define MAX 1000

using namespace std;

Data::Data(){
	this->transf = 0 ;
    this->size_height = 0;
    this->size_width = 0;
    this->lecture = 0;
    this->shininess = 1;
    this->maxDepth = 1;
    this->damierBoul = 0;
    this->diffuse = NULL;
    this->specular = NULL;
    Transformation m = Transformation();
    m.initIdentite();
    this->pileTransform.push_back(m);
}
 
int Data::getWidth(){
	return this->size_width;
}

int Data::getMaxDepth(){
	return this->maxDepth;
}
 
void Data::setWidth(int width){
	this->size_width = width;
}
 
int Data::getHeight(){
	return this->size_height;
}

void Data::setHeight(int height){
	this->size_height = height;
}

Camera* Data::getCamera()
{
	return this->camera;
}

vector<Point*> Data::getTabPoints()
{
	return this->tabPoints;
}

vector<Figure*> Data::getTabFigure()
{
	return this->tabFigure;
}

vector<Lumiere*> Data::getTabLumiere()
{
	return this->tabLumiere;
}

Couleur* Data::getAmbient(){
	return this->ambient;
}

Data::~Data(){
	int i;
	for(i=0; i<this->tabLumiere.size(); i++) delete(this->tabLumiere[i]);
	//for(i=0; i<this->tabFigure.size(); i++) delete(this->tabFigure[i]);
	for(i=0; i<this->tabPoints.size(); i++) delete(this->tabPoints[i]);
	delete(this->ambient);
    delete(this->specular);
	delete(this->camera);
}

/*void Data::afficheData(){
	int cpt;
	printf("La taille %dx%d\n",this->getHeight(),this->getWidth());
	printf("output : %s\n",this->output);
	printf("camera : \n");
	this->camera->affiche();
	printf("ambient : ");
	if(this->ambient)
		this->ambient->afficheCouleur();
	printf("\ndiffuse : ");
	if(this->diffuse)	
		this->diffuse->afficheCouleur();
	printf("specular : \n");
	if(this->specular)	
		this->specular->afficheCouleur();
	printf("\nmaxverts : %d\n",this->maxverts);
	cout << this->tabFigure.size() << endl;
	for(int i=0; i<this->tabLumiere.size(); i++) this->tabLumiere[i]->affiche();
	for(int i=0; i<this->tabFigure.size(); i++) this->tabFigure[i]->affiche();
}*/

string Data::getOutput(){
	return this->output;
}

void Data::miseAJourData (string c){
	char * cstr = new char [c.length()+1];
	std::strcpy (cstr, c.c_str());
	char * p = std::strtok (cstr," ");
	string test(p);
	p = std::strtok(NULL," ");
    if (test == "size"){
		this->recSize(p);}
    if(test == "output"){
		this->recOutput(p);} 
	if(test == "camera"){
		if(this->lecture == 1) 
			this->recCamera(p);}
	if(test == "ambient"){
		this->recAmbient(p);}
	if(test == "diffuse"){
		this->recDiffuse(p);
	}
	if(test == "specular"){
		this->recSpecular(p);}
	if(test == "directional"){
		this->recDirectional(p);}
	if(test == "point"){
		this->recPoint(p);
	}
	if(test == "maxverts"){
		if(this->lecture == 2)
			this->recMaxverts(p);}
	if(test == "vertex"){
		if(this->lecture == 3)
			this->recVertex(p);}
	if(test == "tri"){
		if(this->tabPoints.size() > 2 )
			this->recTri(p);
	}
	if(test == "sphere"){
		this->recSphere(p);}
	if(test == "plane"){
		this->recPlan(p);}
	if(test == "shininess"){
		this->recShininess(p);}
	if(test == "maxdepth"){
		this->recMaxDepth(p);}
	if(test == "scale"){
		this->recScale(p);}
	if(test == "rotate"){
		this->recRotate(p);}
	if(test == "translate"){
		this->recTranslate(p);}
	if(test == "pushTransform"){
		this->recPushTransformation();}
	if(test == "popTransform"){
		this->recPopTransformation();}
	if(test == "checker"){
		this->recChecker(p);}
		
	delete[] cstr;
}

void Data::recChecker(char *p){
    this->damierBoul = 1;
    double taille;
	double a,b,c;
	Couleur c1,c2;
	extraireDouble(&p,a,b,c);
	c1 = Couleur(a,b,c);
	extraireDouble(&p,a,b,c);
	c2 = Couleur(a,b,c);
	taille = atof(p);
    this->damier = Checker(taille,c1,c2);
}

void Data::recPushTransformation(){
	this->pileTransform.push_back(this->pileTransform.back());
}

void Data::recPopTransformation(){
	if(this->pileTransform.size() > 1){
		this->pileTransform.pop_back();
	}
}

void Data::recMaxDepth(char *p){
	this->maxDepth = atof(p);
}

void Data::recShininess(char *p){
	this->shininess = atof(p);
}

double Data::getShininess(){
	return this->shininess;
}

void Data::recRotate(char* p){
	this->transf = 1;
	double a,b,c;
	Vecteur vecteur;
	extraireDouble(&p,a,b,c);
	vecteur = Vecteur(a,b,c);
	a = atof(p);
	b = (a* M_PI) / 180 ;
	Transformation rotate = Transformation();
	rotate.initRotate(b,vecteur);
	this->pileTransform[this->pileTransform.size()-1] *= rotate ;
}

void Data::recScale(char* p){
	this->transf = 1;
	double a,b,c;
	Vecteur vecteur;
	extraireDouble(&p,a,b,c);
	vecteur = Vecteur(a,b,c);
	Transformation scale = Transformation();
	scale.initScale(vecteur);
	this->pileTransform[this->pileTransform.size()-1] *= scale ;
}

void Data::recTranslate(char* p){
	this->transf = 1;
	double a,b,c;
	Vecteur vecteur;
	extraireDouble(&p,a,b,c);
	vecteur = Vecteur(a,b,c);
	Transformation translate = Transformation();
	translate.initTranslate(vecteur);
	this->pileTransform[this->pileTransform.size()-1] *= translate ;
}
void Data::recPlan(char *p){
	double a,b,c;
	double u,v,w;
	Vecteur* vecteur;
	Point* point;
    extraireDouble(&p,a,b,c);
    extraireDouble(&p,u,v,w);
	point=new Point(a,b,c);
	vecteur=new Vecteur(u,v,w);
	this->tabFigure.push_back(new Plan(point,this->camera->getOeil(),vecteur,this->diffuse, this->specular,this->shininess,this->transf,this->pileTransform.back(),this->damier));
    this->damier = Checker();
}

void Data::recSphere(char *p){
	double a,b,c;
	double rayon;
	Point* point;
    extraireDouble(&p,a,b,c);
	rayon = atof(p);
	point=new Point(a,b,c);
	this->tabFigure.push_back(new Sphere(point,this->camera->getOeil(),rayon,this->diffuse,this->specular,this->shininess,this->transf,this->pileTransform.back(),this->damier));
    this->damier = Checker();
}

void Data::recTri(char *p){
	int a,b,c;
	a = atoi(p);
	p = std::strtok(NULL," ");
	b = atoi(p);
	p = std::strtok(NULL," ");
	c = atoi(p);
	p = std::strtok(NULL," ");
	this->tabFigure.push_back(new Triangle(this->tabPoints[a],this->tabPoints[b],this->tabPoints[c], this->camera->getOeil(), this->diffuse, this->specular,this->shininess,this->transf,this->pileTransform.back(),this->damier));
    this->damier = Checker();
	
}

void Data::recVertex(char* p){
	double a,b,c;
    extraireDouble(&p,a,b,c);
	this->tabPoints.push_back(new Point(a,b,c));
}

void Data::recMaxverts(char* p){
	this->maxverts = atoi(p);
    this->lecture = 3;
}

void Data::recPoint(char* p){
	double a,b,c;
	Point* point;
	Couleur* cou;
    extraireDouble(&p,a,b,c);
	point = new Point(a,b,c);
    extraireDouble(&p,a,b,c);
	cou = new Couleur(a,b,c);
    this->tabLumiere.push_back(new Ponctual(point,cou));
}

void Data::recDirectional(char* p){
	double a,b,c;
	Vecteur* v;
	Couleur* cou;
    extraireDouble(&p,a,b,c);
	v = new Vecteur(a,b,c);
    extraireDouble(&p,a,b,c);
	cou = new Couleur(a,b,c);
	/*this->directional = new Directional(v,cou);
    this->lecture = 4;*/
    this->tabLumiere.push_back(new Directional(v,cou));
}

void Data::recSpecular(char* p){
	double a,b,c;
    extraireDouble(&p,a,b,c);
	this->specular = new Couleur(a,b,c);
}

void Data::recDiffuse(char* p){
	double a,b,c;
    extraireDouble(&p,a,b,c);
	this->diffuse = new Couleur(a,b,c);
}

void Data::recAmbient(char* p){
	double a,b,c;
    extraireDouble(&p,a,b,c);
	this->ambient = new Couleur(a,b,c);
    this->lecture = 3;
}

void Data::recCamera(char* p){
	double a,b,c;
	Point* oeil;
	Point* cible;
	Vecteur* direction;
    extraireDouble(&p,a,b,c);
	oeil = new Point(a,b,c);
    extraireDouble(&p,a,b,c);
	cible = new Point(a,b,c);
    extraireDouble(&p,a,b,c);
	direction = new Vecteur(a,b,c);
    a=atof(p);
    b=(a* M_PI) / 180 ;
	this->camera = new Camera(oeil,cible,direction,b);
	this->lecture = 2;
}

void Data::recOutput(char* p){
	char *tmp;
	int i;
	this->output = string(p);
}

void Data::recSize(char* p){
    this->setWidth(atoi(p));
	p = std::strtok(NULL," ");
    this->setHeight(atoi(p));
    this->lecture = 1;
}
void extraireDouble(char** p, double& a, double& b, double& c){
	a = atof(*p);
	*p = std::strtok(NULL," ");
	b = atof(*p);
	*p = std::strtok(NULL," ");
	c = atof(*p);
	*p = std::strtok(NULL," ");
}
Data* parcours(char* nomF) {
    Data* d=new Data();
	string contenu;
	ifstream fichier(nomF, ios::in);
	//Parcours du fichier ligne/ligne
	if (fichier){	
		while (getline(fichier, contenu)){ 
			//Suppression des commentaires
			//cout << contenu << endl ;
			if( contenu[0]=='#' || contenu[0]=='\n' || !((contenu[0]<='z' && contenu[0]>='a') || (contenu[0]<='Z' && contenu[0]>'A'))); //cout << "supligne" << endl;
            else d->miseAJourData(contenu);
		}
		fichier.close();
	}
	else{		
		printf("Erreur de lecture du fichier");
		exit(1);
	}
    return d;
}
