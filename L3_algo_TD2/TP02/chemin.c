// Nom du fichier : chemin.c
// Auteur : Julien d'Aboville


#include <stdio.h>
#include <stdlib.h>
#include "chemin.h"
#include "graphe.h"
#include "file.h"


void plusCourtChemin(int **adjacence, int ordre, int s, int *lm, int *pred) {
	int *marques;
	int x, y;
	file *f = NouvelFile(-1);

	marques = malloc(sizeof(int) * ordre);
	if (marques==NULL){
		printf("probleme de memoire");
	}

	for (x = 0; x < ordre; x++) {
		marques[x] = 0;
		lm[x] = 0;
	}

	marques[s] = 1;
	file *X1 = NouvelFile(s);
	InsererFile(indeF, X1, f);
//indeF=0 puis 1

	while (EstVideFile(f) == FALSE) {
		x = SupprimeFile(1, f);
		for (y = 0; y < ordre; y++) {
			if (adjacence[x][y] && !marques[y]) {
				marques[y] = 1;
				file *Y = NouvelFile(y);
				InsererFile(indeF, Y, f);

				pred[y] = x;
				lm[y] = lm[x] + 1;

			}
		}

	}
/* affiche les distance minimal de s vert chaque sommet et tous les predecesseurs des sommets
	for (int i = 0; i < ordre; i++) {
		printf(" lm[%d] ==> %d \n", i, lm[i]);

	}

	for (int i = 0; i < ordre; i++) {
		printf(" pred[%d] ==> %d \n", i, pred[i]);

	}

*/
}
