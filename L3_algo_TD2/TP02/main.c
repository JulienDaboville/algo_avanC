

// Nom du fichier : main.c
// Auteur : Julien d'Aboville


#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include <time.h>
#include <math.h>
#include "temps.h"
#include "file.h"

#include "chemin.h"









int main(){
	int choix=0;

	printf("Veux tu creer des graphes automotiquement(0) ou le creer toi meme(1)");
	scanf("%d",&choix);



	if( choix==0){//Pour creer des graphes automatiquement ainsi que leur complexites
		srand48(time(NULL));
			char NomFichier[200]="donnees_complexite.csv";
			FILE *Fic=fopen(NomFichier,"w");
			if(Fic==NULL){
				printf("Erreur a l'ouverture du fichier %s\n",NomFichier);

			}

			fprintf(Fic, "Taille du graphe,Temps de calcul\n");





			for(int taille=100;taille<=1000;taille+=100){
				mesureTemps(taille,Fic);
			}

			fclose(Fic);

	}
	else {//Pour creer un graphe manuellement
		int s;


		Graph *G=chargeGraphe();
	 	int lm[G->V];
		int pred[G->V];
		printf("Choisit a partir de quelles sommet tu veux commencer :\n");
		scanf("%d",&s);

		plusCourtChemin(G->adj, G->V, s,lm,pred);

		for(int i=0;i<G->V;i++){
			printf(" lm[%d] ==> %d \n",i,lm[i]);

		}
		pred[s]=0;
		for(int i=0;i<G->V;i++){
				printf(" pred[%d] ==> %d \n",i,pred[i]);

			}


	}


















	return 0;






}
