#ifndef _MULTICORE_H
#define _MULTICORE_H

#include <iostream>
#include <vector>
#include <thread>

#include "../include/Scene.h"

using namespace std;

class Multicore
{
	public:
		~Multicore();
		Multicore(Scene *scene, int affichage,int coeur);
		int start(Scene *scene);
        void sansMulti(Scene *scene);
	private:
        int affichage;
        int coeur;
        vector<unsigned char> *image;

};
void appelThread(Scene *scene,vector<unsigned char>* image, int cpt);
void appelThread2(Scene *scene,vector<unsigned char>* image,int cpt);

#endif


