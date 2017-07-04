CC=icpc
CFLAGS= -O3 -pthread -std=c++11 -I./include

OBJS=bin/Checker.o bin/Multicore.o bin/Lumiere.o bin/Directional.o bin/Ponctual.o bin/Matrice.o bin/Camera.o bin/Point.o bin/Vecteur.o bin/Couleur.o bin/Figure.o bin/Sphere.o bin/Triangle.o bin/Plan.o bin/Data.o bin/lodepng.o bin/Transformation.o bin/Scene.o bin/RayTracer.o

.PHONY: clean

RayTracer: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o RayTracer 

bin/RayTracer.o: include/RayTracer.h include/Data.h include/Matrice.h include/Couleur.h  include/Vecteur.h include/Point.h src/RayTracer.cpp
	$(CC) $(CFLAGS) -c src/RayTracer.cpp -o bin/RayTracer.o 

bin/Matrice.o: include/Matrice.h src/Matrice.cpp
	$(CC) $(CFLAGS) -c src/Matrice.cpp -o bin/Matrice.o

bin/Point.o: include/Vecteur.h include/Point.h src/Point.cpp
	$(CC) $(CFLAGS) -c src/Point.cpp -o bin/Point.o

bin/Vecteur.o: include/Vecteur.h src/Vecteur.cpp
	#$(CC) -g -pthread -std=c++11 -I./include -c src/Vecteur.cpp -o bin/Vecteur.o
	$(CC) $(CFLAGS) -c src/Vecteur.cpp -o bin/Vecteur.o

bin/Couleur.o: include/Couleur.h src/Couleur.cpp
	$(CC) $(CFLAGS) -c src/Couleur.cpp -o bin/Couleur.o

bin/Camera.o: include/Camera.h src/Camera.cpp
	$(CC) $(CFLAGS) -c src/Camera.cpp -o bin/Camera.o

bin/Data.o: include/Plan.h include/Sphere.h include/Triangle.h include/Figure.h include/Vecteur.h include/Point.h include/Data.h include/Camera.h src/Data.cpp
	$(CC) $(CFLAGS) -c src/Data.cpp -o bin/Data.o
	
bin/Figure.o: include/Figure.h src/Figure.cpp
	$(CC) $(CFLAGS) -c src/Figure.cpp -o bin/Figure.o

bin/Sphere.o: include/Figure.h include/Sphere.h src/Sphere.cpp
	$(CC) $(CFLAGS) -c src/Sphere.cpp -o bin/Sphere.o
	
bin/Triangle.o: include/Figure.h include/Triangle.h src/Triangle.cpp
	$(CC) $(CFLAGS) -c src/Triangle.cpp -o bin/Triangle.o
	
bin/Plan.o: include/Plan.h src/Plan.cpp
	$(CC) $(CFLAGS) -c src/Plan.cpp -o bin/Plan.o
	
bin/Lumiere.o: include/Lumiere.h src/Lumiere.cpp
	$(CC) $(CFLAGS) -c src/Lumiere.cpp -o bin/Lumiere.o
	
bin/Directional.o: include/Lumiere.h include/Directional.h src/Directional.cpp
	$(CC) $(CFLAGS) -c src/Directional.cpp -o bin/Directional.o

bin/Ponctual.o: include/Lumiere.h include/Ponctual.h src/Ponctual.cpp
	$(CC) $(CFLAGS) -c src/Ponctual.cpp -o bin/Ponctual.o

bin/lodepng.o: include/lodepng.h src/lodepng.cpp
	icpc $(CFLAGS) -c src/lodepng.cpp -o bin/lodepng.o
	
bin/Scene.o: include/lodepng.h include/Plan.h include/Scene.h src/Scene.cpp
	$(CC) $(CFLAGS) -c src/Scene.cpp -o bin/Scene.o

bin/Transformation.o: include/Transformation.h src/Transformation.cpp
	$(CC) $(CFLAGS) -c src/Transformation.cpp -o bin/Transformation.o

bin/Multicore.o: include/Multicore.h src/Multicore.cpp
	$(CC) $(CFLAGS) -c src/Multicore.cpp -o bin/Multicore.o

bin/Checker.o: include/Checker.h src/Checker.cpp
	$(CC) $(CFLAGS) -c src/Checker.cpp -o bin/Checker.o
	
clean:
	@rm -f bin/*.o RayTracer

