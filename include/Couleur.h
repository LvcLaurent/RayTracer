#ifndef DEF_COULEUR
#define DEF_COULEUR

class Couleur
{
	public:
		Couleur();
		Couleur(double r,double g,double b);
		void remiseAUn();
		void operator+=(Couleur const& c);
		void operator*=(double d);
		void operator*=(Couleur const& c);
		void afficheCouleur();
		double getR();
		double getG();
		double getB();
	private:
		double r;
		double g;
		double b;
};
Couleur operator*(Couleur const& c1, Couleur const& c2);
Couleur operator*(Couleur const& c1, double const d);
#endif
