#ifndef DEF_VECTEUR
#define DEF_VECTEUR
class Vecteur{
	private:
		double x;
		double y;
		double z;
	public:
		Vecteur();
		Vecteur(double, double, double);
		~Vecteur();
		double getX() const;
		double getY() const;
		double getZ() const;
		
		double getNorme();
		void afficheVecteur();
		void operator+=(Vecteur const&);
		void operator-=(Vecteur const&);
		void operator*=(double const);		//multiplication par un scalaire
		void produitVectoriel(Vecteur*, Vecteur const&);
		void normalisation();
		void autreSens();
};
Vecteur operator+(Vecteur const&, Vecteur const&);
Vecteur operator-(Vecteur const&, Vecteur const&);
double operator*(Vecteur const& , Vecteur const&);	//produit scalaire
Vecteur operator*(Vecteur const&, double const);
Vecteur operator*(double const, Vecteur const&);

#endif
