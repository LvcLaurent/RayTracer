#include <iostream>
#include "../include/Point.h"
#include "../include/Vecteur.h"

using namespace std;

void Point::affichePoint(){
	cout << endl << "\tx : " << this->x << "\ty :" << this->y << "\tz :" << this->z;
}
Point::Point():x(0),y(0),z(0){
}
Point::Point(double a, double b, double c){
	this->x=a;
	this->y=b;
	this->z=c;
}
void Point::copie(Point& p){
	this->x=p.x;
	this->y=p.y;
	this->z=p.z;
}
Point Point::coordonneeSoustract(Point& p){
	return Point(this->x - p.x, this->y - p.y, this->z - p.z);
}
Vecteur operator-(Point& p1,Point& p2){
	Vecteur res(p1.getX() - p2.getX(),p1.getY() - p2.getY(),p1.getZ() - p2.getZ());
	return res;
}

void Point::operator-=(Vecteur& v){
	this->x-=v.getX();
	this->y-=v.getY();
	this->z-=v.getZ();
}
void Point::operator+=(Vecteur& v){
	this->x+=v.getX();
	this->y+=v.getY();
	this->z+=v.getZ();
}

void Point::operator*=(int d){
	this->x*=d;
	this->y*=d;
	this->z*=d;
}

int Point::compare(Point& p){
	int res = 1;
	if(this->x != p.x || this->y != p.y || this->z != p.z) res = 0;
	return res;
}

double Point::getX(){
	return this->x;
}
double Point::getY(){
	return this->y;
}
double Point::getZ(){
	return this->z;
}
Point operator+(Vecteur& v, Point& p){
	return p+v;
}

Point operator+(Point& p,Vecteur& v){
	Point copie(p);
	copie +=v;
	return copie;
}
