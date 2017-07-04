# Fichier de compilation ant

Les deux fichiers suivants permettent de compiler un programme Java et de
générer un jar autoexécutable.

Pour l'utiliser :

* Installer [Ant](http://ant.apache.org/) sur votre machine (c'est déjà fait en salle TP.
* Modifier le fichier `project.properties` pour l'adapter à votre cas.
   + `src` correspond au chemin contenant les sources de votre programme.
   + `main.class` correspond au chemin complètement qualifié de la classe contenant la méthode main.
   + `jarname` correspond au nom du fichier jar à générer.
* taper `ant`
* votre jar autoexécutable est prêt.

Exemple de configuration :

```
src=src
main.class=fr.univartois.l3mi.prj2.RayTracer
jarname=dlbraytracer
```

Exemple d'exécution :

```
$ ant
Buildfile: /Users/leberre/git/myraytracer/DLBRayTracer/build.xml

clean:
   [delete] Deleting directory /Users/leberre/git/myraytracer/DLBRayTracer/build

prepare:
    [mkdir] Created dir: /Users/leberre/git/myraytracer/DLBRayTracer/build

build:
    [javac] Compiling 28 source files to /Users/leberre/git/myraytracer/DLBRayTracer/build
    [javac] Note: /Users/leberre/git/myraytracer/DLBRayTracer/src/fr/univartois/l3mi/prj2/Matrix3.java uses unchecked or unsafe operations.
    [javac] Note: Recompile with -Xlint:unchecked for details.
      [jar] Building jar: /Users/leberre/git/myraytracer/DLBRayTracer/dlbraytracer.jar

BUILD SUCCESSFUL
Total time: 1 second
$ java -jar dlbraytracer.jar ~/SCM/prj2-scenes/DIFFICILES/tank.test 
```
