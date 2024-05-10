// Nom du fichier : temps.c
// Auteur : Julien d'Aboville


#include "stdio.h"
#include "stdlib.h"
#include "temps.h"
#include "graphe.h"
#include "chemin.h"
#include <time.h>

void mesureTemps(int taille,FILE *fic) {
	int **adjacente = malloc(sizeof(int*) * taille);
	if (adjacente==NULL){
		printf("probleme de memoire");
	}
	for (int i = 0; i < taille; i++) {
		adjacente[i] = malloc(sizeof(int) * taille);
		if (adjacente[i]==NULL){
				printf("probleme de memoire");
			}

	}

	double proba = 0.3;


	int lm[taille];
	int pred[taille];

	genereGraphe(adjacente,taille,proba);

	clock_t temps_deb=clock();

	plusCourtChemin(adjacente, taille, 0,lm,pred);

	clock_t temps_fin=clock();

	double temps_ecoule=(double)(temps_fin-temps_deb)/CLOCKS_PER_SEC;

	fprintf(fic,"%d,%.8f\n",taille,temps_ecoule);

	printf("Taille du graphe :%d, Temps de calcul : %.8f secondes \n",taille,temps_ecoule);

	for(int i=0;i<taille;i++){
		free(adjacente[i]);
	}
	free(adjacente);

}
