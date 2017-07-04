#include <iostream>

#include "../include/Multicore.h"

static const int num_threads = 4;

using namespace std;

void appelThread(Scene *scene,vector<unsigned char>* image,int cpt){
    cout << "Rayon Lancé par le thread "<< cpt + 1 << endl;
    scene->lanceurRayon(image);

}

void appelThread2(Scene *scene,vector<unsigned char>* image,int cpt){
    cout << "Affichage Lancé par le thread "<< cpt << endl;
    while(scene->numLigne < (scene->getSizeHeight()-1))
        encodeOneStep(scene->output.c_str(), *image, scene->getSizeWidth(), scene->getSizeHeight());
}



Multicore::Multicore(Scene *scene, int aff,int c){
    this->image = new vector<unsigned char>();
    this->image->resize(scene->getSizeWidth() * scene->getSizeHeight() * 4);
    this->affichage = aff ;
    this->coeur = c;
}

void Multicore::sansMulti(Scene *scene){
    cout << "Rayon Lancé par un seul thread "<< endl;
    scene->lanceurRayon(image);
}
    

Multicore::~Multicore(){
    delete(image);
}

int Multicore::start(Scene *scene){
    std::vector<std::thread> threads;
    
    //Lancement des threads
    
    if(this->affichage){
        for (int i = 0; i < this->coeur - 1 ; i++) {
            threads.push_back(thread(appelThread,scene,this->image,i));
        }
        threads.push_back(thread(appelThread2,scene,this->image,this->coeur));
    }
    else
        for (int i = 0; i < this->coeur ; i++) {
            threads.push_back(thread(appelThread,scene,this->image,i));
        }
    std::cout << "Launched from the main\n";

    //Join the threads with the main thread
    for(auto& thread : threads){
        thread.join();
    }
    //scene->lanceurRayon(num_threads, image,3);
	encodeOneStep(scene->output.c_str(), *this->image, scene->getSizeWidth(), scene->getSizeHeight());
    return 0;
}
