#ifndef DEF_POINT
#define DEF_POINT

#include "../include/Vecteur.h"


class Point
{
	public:
		Point();
		Point(double a, double b, double c);
		void operator-=(Vecteur& v);
		void operator+=(Vecteur& v);
		void operator*=(int d);
		Point coordonneeSoustract(Point& p);
		void copie(Point& p);
		double getX();
		double getY();
		double getZ();
		int compare(Point& p);
		void affichePoint();
	private:
		double x;
		double y;
		double z;
};

Vecteur operator-(Point& p1,Point& p2);
Point operator+(Vecteur& v, Point& p);
Point operator+(Point& p,Vecteur& v);
#endif
