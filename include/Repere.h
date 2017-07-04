#ifndef _REPERE_H_
#define _REPERE_H_
class Repere{
	private:
		Vecteur* w;
		Vecteur* v;
		Vecteur* u;
	public:
		Repere();
		Repere(Vecteur*, Vecteur*, Vecteur*);
		~Repere();
		Vecteur* getW();
		Vecteur* getV();
		Vecteur* getU();

		void afficheRepere();

};

#endif

