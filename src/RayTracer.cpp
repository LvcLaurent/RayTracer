#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>     /* atoi */
#include <vector>

#include "../include/Matrice.h"
#include "../include/Data.h"
#include "../include/Point.h"
#include "../include/Vecteur.h"
#include "../include/Couleur.h"
#include "../include/RayTracer.h"
#include "../include/Scene.h"
#include "../include/Multicore.h"

using namespace std;

int main(int argc, char *argv[]){
	/*
	 * Appel du Parser
     * seul : -c pour le multi thread
     *        -a pour l'affichage
     * 
     * -[ca] int : pour le nombre de coeur
	*/
	Data* d;
    int coeur,test = 0;
	Scene* scene;
    Multicore* m;
    if (argc >= 3 ){
        if (argc == 3) d=parcours(argv[2]);
        else d=parcours(argv[3]);
        scene = new Scene(d);
        if(argv[1][1] == 'a'){
            if (argc == 3) coeur = 4;
            else coeur = atoi(argv[2]);
            m = new Multicore(scene,1,coeur);
            m->start(scene);
        }
        else if(argv[1][1] == 'c'){
            if (argc == 3) coeur = 4;
            else coeur = atoi(argv[2]);
            m = new Multicore(scene,0,coeur);
            m->start(scene);
        }
        else{        
            m = new Multicore(scene,0,0);
            m->start(scene);
        }
    }
    else{
        cout << argc <<endl ;
        d=parcours(argv[1]);
        scene = new Scene(d);
        m = new Multicore(scene,0,0);
        m->sansMulti(scene);
    }
    delete(m);
    delete(scene);
	delete(d);
	return 0;
	
}
