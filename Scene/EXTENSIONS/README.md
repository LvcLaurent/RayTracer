# extensions possible du lanceur de rayons


L'objectif est que chaque groupe implémente une fonctionnalité particulière dans son lanceur de rayons.
Il y a exactement le même nombre de fonctionnalités que de groupe. Le choix des fonctionnalités à réaliser se fera sur Moodle vendredi 27 février à 10h.

## Nouveaux objets

Pour l'instant, nous manipulons des plans, des sphères et des rectangles. On souhaite manipuler d'autres types d'objets primitifs.

+ Manipulation d'un [cyclindre](http://fr.wikipedia.org/wiki/Cylindre)
+ Manipulation d'un [cône](http://fr.wikipedia.org/wiki/Cône_(géométrie))
+ Manipulation d'un [tore](http://fr.wikipedia.org/wiki/Tore)

La plus grande difficulté dans ce cadre est de devoir correctement gérer l'application des transformations (qui seront vues après l'interruption pédagogique) sur ces objets.

## prise en compte des textures (texture mapping)

Il s'agit dans ce cas de [manipuler des textures](http://en.wikipedia.org/wiki/Texture_mapping) qui se trouvent dans un fichier, et de les appliquer sur la surface d'un objet.
La principale difficulté pour les cas de base est de trouver une solution qui produise une image réaliste sur des objets spécifique. Attention aux textures utilisées.

Cas de base :

+ Appliquer une texture sur un plan dont l'orientation est fixe (de normale (0,1,0) par exemple).
+ Appliquer une texture sur une sphère unitaire (centrée en (0,0,0) et de rayon 1).
+ Appliquer une texture sur un triangle.

Plus difficile :

+ Appliquer une texture sur un plan quelconque.
+ Appliquer une texture sur une sphère quelconque.
+ Appliquer une texture sur un ensemble de triangles (un cube au minimun, un dragon au maximum).

Les textures peuvent aussi être procédurales (comme le damier).

+ Appliquer une texture procédurale de type Marbre.

## modifier l'aspect des objets (bump mapping)

Il s'agit de changer le rendu d'une surface en modifiant le calcul de la normale à partir de données externes (généralement une image en N&B).

+ [Bump mapping](http://en.wikipedia.org/wiki/Bump_mapping) d'une surface plane (plan, triangle)
+ [Bump mapping](http://en.wikipedia.org/wiki/Bump_mapping) d'une sphère

+ [Displacement mapping](http://en.wikipedia.org/wiki/Displacement_mapping) d'une surface plane
+ [Displacement mapping](http://en.wikipedia.org/wiki/Displacement_mapping) d'une sphère

## gestion des surfaces transparentes

Il s'agit dans ce cas de modéliser la lumière reçue [par réfraction](http://en.wikipedia.org/wiki/Refraction) au niveau de l'objet.

+ Gestion d'une surface transparente plane sans épaisseur
+ Gestion d'une surface transparente sphérique sans épaisseur

