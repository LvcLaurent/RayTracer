#include <iostream>
#include "../include/Matrice.h"

#include <vector>
#include <string.h>


using namespace std;

Matrice::Matrice(int taille)
{
	this->taille=taille;
	
	int i=0;
	for(;i<taille;i++)
	{
		this->grille.push_back(vector<double>(taille,0));
	}
}
Matrice::Matrice()
{
	this->taille=4;
	
	int i=0;
	for(;i<this->taille;i++)
	{
		this->grille.push_back(vector<double>(this->taille,0));
	}
}
Matrice::Matrice(Matrice const& matACopier){
	this->taille = matACopier.taille;
	
	int i,j;
	for(i=0;i<taille;i++)
	{
		this->grille.push_back(vector<double>(taille,0));
	}
	for(i=0;i<taille; i++){	
		for(j=0; j<taille; j++){
			this->grille[i][j] = matACopier.grille[i][j];
		}
	}
	//matACopier.toString();
}
void Matrice::initIdentite(){
	for(int i=0; i<this->taille; i++){
		this->grille[i][i] = 1;
	}
}
void Matrice::copie(Matrice& ACopier){
	if(this->taille >= ACopier.taille){
		for(int i=0;i<ACopier.taille; i++){	
			for(int j=0; j<ACopier.taille; j++){
				this->grille[i][j] = ACopier.grille[i][j];
			}
	}
	}
}
void Matrice::initCase(int i, int j, double elt){
	this->grille[i][j] = elt;
}
// Methode qui retourne le determinant de la Matrice.
Matrice Matrice::transposer(){
	Matrice res(this->taille);
	int i,j;
	for(i=0;i<this->taille;i++)
		for(j=0;j<this->taille;j++)
			res.grille[j][i] = this->grille[i][j];
	return res;
}
Matrice Matrice::inversion(){
	Matrice comatrice;
	Matrice trans;
	double det;
	trans = this->transposer();
	comatrice = trans.comatrice();
	det = this->determinant();
	det = 1/det;
	comatrice *= det;
	return comatrice;
}
double Matrice::determinant()
{
	double resultat=0;
	int signe=1;
	if(this->taille == 2)
	{
		resultat= this->grille[0][0] * this->grille[1][1] - this->grille[1][0] * this->grille[0][1];
		return resultat;
	}
	else
	{
	//cas N
		
		/*vector <Matrice*> listMatrice;
		listMatrice.reserve(this->taille);*/
		Matrice matRed(this->taille-1);
		int i=0;
		for(;i<this->taille;i++)
		{
			//listMatrice[i]=new Matrice(this->taille-1);
			this->reduction(matRed,0,i);

			//listMatrice[i]->toString();
			resultat+= signe*this->grille[0][i]*matRed.determinant();
			signe*=-1;
		}
		return resultat;
	}
}

void Matrice::reduction(Matrice& mt, int x, int y)
{
	int i=0;
	int j=0;
	int i_3=0;
	int j_3=0;
	for(i=0,i_3=0;i<this->taille;i++)
	if(i!=x)
	{
		for(j=0,j_3=0;j<this->taille;j++)
		{
			if(j!=y)
			{
				mt.grille[i_3][j_3]=this->grille[i][j];
				j_3++;
			}
		}
		i_3++;
	}
}

Matrice Matrice::comatrice()
{
	Matrice mt(this->taille);
	Matrice tmp(this->taille-1);
	int i;
	int j;
	int signe=1;
		for(i=0;i<this->taille;i++)
		{
			if(i%2) signe = -1;
			else signe = 1;
			for(j=0;j<this->taille;j++)
			{
				//this->grille[i][j];
				reduction(tmp, i, j);
				//tmp.toString();
				//cout<<tmp->determinant()<<" ";
				mt.grille[i][j]=signe*tmp.determinant();
				signe=signe*-1;
			}
		}
	
	return mt;
}
Point Matrice::mult(Point& pointATransform){
	double elementPoint[4], res[3];
	elementPoint[0] = pointATransform.getX();
	elementPoint[1] = pointATransform.getY();
	elementPoint[2] = pointATransform.getZ();
	elementPoint[3] = 1;
	for(int i=0; i<3; i++){
		res[i] = 0;
		for(int j=0; j<4; j++){
			res[i] += this->grille[i][j]*elementPoint[j];
		}
	}
	return Point(res[0],res[1],res[2]);
}
Vecteur Matrice::mult(Vecteur& vecteurATransform){
	double elementVecteur[4], res[3];
	elementVecteur[0] = vecteurATransform.getX();
	elementVecteur[1] = vecteurATransform.getY();
	elementVecteur[2] = vecteurATransform.getZ();
	elementVecteur[3] = 0;
	for(int i=0; i<3; i++){
		res[i] = 0;
		for(int j=0; j<4; j++){
			res[i] += this->grille[i][j]*elementVecteur[j];
		}
	}
	return Vecteur(res[0],res[1],res[2]);
}
void Matrice::toString() const
{
	int i;
	int j;
	cout<<"\n";
		for(i=0;i<this->taille;i++)
		{
			
			for(j=0;j<this->taille;j++)
			{
				cout<<this->grille[i][j]<<"\t";
			}
			cout<<"\n";
		}
		cout<<"\n";
}
//accesseur
int Matrice::getTaille() const{
	return taille;
}
//operateur
void Matrice::operator+=(Matrice const& m)
{
	int i,j;
	for(i=0;i<this->taille;i++)
	{
		for(j=0;j<this->taille;j++)
		{
			this->grille[i][j] += m.grille[i][j];
		}
	}
}
void Matrice::operator-=(Matrice const& m)
{
	int i,j;
	for(i=0;i<this->taille;i++)
	{
		for(j=0;j<this->taille;j++)
		{
			this->grille[i][j] -= m.grille[i][j];
		}
	}
}
void Matrice::operator*=(Matrice const& m)
{
	Matrice res(this->taille);
	int i,j,k;
	for(i=0;i<this->taille;i++)
		for(j=0;j<this->taille;j++)
			for(k=0;k<this->taille;k++){
				res.grille[i][j]+= this->grille[i][k] * m.grille[k][j]; 
			}
	for(i=0;i<this->taille;i++)
		for(j=0;j<this->taille;j++)
			this->grille[i][j]=res.grille[i][j];
}
void Matrice::operator*=(double d)
{
	int i,j;
	for(i=0;i<this->taille;i++){
		for(j=0;j<this->taille;j++){
			//cout << i <<"<>"<< j << "\n"<<endl;
			this->grille[i][j]*=d;
			//cout << "multi" << endl;
		}
	}
}
Matrice operator+(Matrice const& m1,Matrice const& m2)
{
	Matrice copie(m1);
	copie+=m2;
	return copie;
}
Matrice operator-(Matrice const& m1,Matrice const& m2)
{
	Matrice copie(m1);
	copie-=m2;
	return copie;
}
Matrice operator*(Matrice const& m1,Matrice const& m2)
{
	Matrice copie(m1);
	copie*=m2;
	return copie;
}
Matrice operator*(Matrice const& m1, double d)
{
	Matrice copie(m1);
	//copie.toString();
	copie*=d;
	return copie;
}
