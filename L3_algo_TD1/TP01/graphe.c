// Nom du fichier : graphe.c
// Auteur : Julien d'Aboville

#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

Graph* chargeGraphe() {
	Graph *G = malloc(sizeof(Graph));
	if (!G) {
		printf("Memory Null");
	}
	printf("Entrez le nombre de sommets et d'arêtes : ");
	scanf("%d %d", &G->V, &G->E);

	G->adj = malloc(sizeof(int*) * G->V);

	int i, u, v;
	for (i = 0; i < G->V; i++) {
		G->adj[i] = malloc(sizeof(int) * G->V);
	}

	for (u = 0; u < G->V; u++) {
		for (v = 0; v < G->V; v++) {
			G->adj[u][v] = 0;
		}
	}
	printf("chosir des sommets>0\n");
	for (i = 0; i < G->E; i++) {
		printf(
				"Choisissez u et v qui sont les sommets reliés par une arête : ");
		scanf("%d %d", &u, &v);
		u--, v--; // Permet d'entrer les vraies valeurs à partir de 1 et non de 0
		G->adj[u][v] = 1;
		G->adj[v][u] = 1;
	}

	return G;
}

void marquerVoisins(int **adjacence, int ordre, int s) {
	// Variables locales
	int *marques;
	int x, y, i;
	int ordreMarquage[ordre];
	int indiceOrdre = 0;

	marques = (int*) malloc(ordre * sizeof(int));
	// Initialiser les marquages et le tableau des ordres à 0
	for (x = 0; x < ordre; x++) {
		marques[x] = 0;
		ordreMarquage[x] = -1;
	}

	marques[s - 1] = 1;
	ordreMarquage[indiceOrdre++] = s - 1;

	for (x = 0; x < ordre; x++) {
		if (marques[x]) {
			for (y = 0; y < ordre; y++) {
				if (adjacence[x][y] && !marques[y]) {
					marques[y] = 1;
					ordreMarquage[indiceOrdre++] = y;
				}
			}
		}
	}

	// Affichage de l'ordre de marquage
	printf("Ordre de marquage de marquerVoisins : ");
	for (i = 0; i < ordre; i++) {
		printf("%d \t", ordreMarquage[i] + 1);
	}
	printf("\n");
}

int appartient(int y, int *li, int ordre) {
	int bool = 0;
	for (int i = 0; i < ordre; i++) {
		if (y == li[i]) {
			bool = 1;
		}
	}
	return bool;
}

void marquerTousLesVoisins(int **adjacence, int ordre, int s) {
	// Variables locales
	int x, y, i = 0;
	int ordreMarquage[ordre];
	int indiceOrdre = 0;

	for (x = 0; x < ordre; x++) {
		ordreMarquage[x] = -1;
	}

	ordreMarquage[indiceOrdre++] = s - 1;

	while (ordreMarquage[(ordre - 1)] == -1) {
		x = ordreMarquage[i++];
		for (y = 0; y < ordre; y++) {
			if ((adjacence[x][y])
					&& (appartient(y, ordreMarquage, ordre) == 0)) {
				ordreMarquage[indiceOrdre++] = y;
			}
		}
	}

	// Affichage de l'ordre de marquage
	printf("Ordre de marquage de marquerTousLesVoisins : ");
	for (i = 0; i < ordre; i++) {
		printf("%d \t", ordreMarquage[i] + 1);
	}
	printf("\n");
}

