// Nom du fichier : t_arete.c
// Auteur : Julien d'Aboville



#include <stdio.h>
#include <stdlib.h>
#include "t_arete.h"






void creerArete (t_arete **arbre,int sommet1,int sommet2,int indice){
	arbre[indice]=malloc(sizeof(t_arete));
	arbre[indice]->sommet1=sommet1;
	arbre[indice]->sommet2=sommet2;


}
