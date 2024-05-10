// Nom du fichier : grapheLinea.c
// Auteur : Julien d'Aboville


#include <stdio.h>
#include <stdlib.h>

#include "grapheLinea.h"
#include "graphe.h"

void marquerTousLesVoisinsLinearise(int *adjacence, int ordre, int s) {
	int x, y, i = 0;
	int ordreMarquage[ordre];
	int indiceOrdre = 0;

	printf("Ordre marquable : %d\n", ordre);

	// Initialisation du tableau d'ordre de marquage
	for (x = 0; x < ordre; x++) {
		ordreMarquage[x] = -1;
	}

	ordreMarquage[indiceOrdre++] = s - 1; // Marquer le sommet de départ
	printf(
			"Valeur du dernier élément dans ordreMarquage (normalement -1) : %d\n",
			ordreMarquage[ordre - 1]);

	while (ordreMarquage[ordre - 1] == -1) {
		x = ordreMarquage[i++];
		printf("x : %d\n", x);
		for (y = 0; y < ordre; y++) {
			printf("y : %d\n", y);
			if (adjacence[x * ordre + y]
					&& (appartient(y, ordreMarquage, ordre) == 0)) {
				ordreMarquage[indiceOrdre++] = y;
				printf("Ajout de %d à l'ordre de marquage\n", y + 1);
			}
		}
	}

	// Affichage de l'ordre de marquage
	printf("Ordre de marquage (tous les voisins) : ");
	for (i = 0; i < ordre; i++) {
		printf("%d \t", ordreMarquage[i] + 1);
	}
	printf("\n");
}

Graphl* chargeGrapheLinearise() {
	Graphl *G = malloc(sizeof(Graphl));
	if (!G) {
		printf("Memory Null");
	}
	printf("Entre le nombre de sommets et d'arêtes : ");
	scanf("%d %d", &G->V, &G->E);

	G->adj = malloc(sizeof(int) * (G->V * G->V));

	int i, u, v;

	for (u = 0; u < G->V * G->V; u++) {
		G->adj[u] = 0;
	}

	for (i = 0; i < G->E; i++) {
		printf("Choisissez u et v, les sommets reliés par une arête : ");
		scanf("%d %d", &u, &v);
		u--, v--;
		G->adj[u * G->V + v] = 1;
		G->adj[v * G->V + u] = 1;
	}

	return G;
}
