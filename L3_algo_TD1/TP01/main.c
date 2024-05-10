#include <stdio.h>
// Nom du fichier : main.c
// Auteur : Julien d'Aboville



#include <stdlib.h>
#include "graphe.h"
#include "grapheLinea.h"

int main() {

	Graph *g = chargeGraphe();

	// Affichage des voisins pour chaque sommet et de tous les voisins

	// Exemple pour un Graphe avec 4 sommets avec un sommet de debut different

    // Start avec le Sommet 1
	printf("Start Sommet 1\n");
	marquerVoisins(g->adj, g->V, 1);
	marquerTousLesVoisins(g->adj, g->V, 1);

    // Start avec le Sommet 2
	printf("Start Sommet 2\n");
	marquerVoisins(g->adj, g->V, 2);
	marquerTousLesVoisins(g->adj, g->V, 2);

    // Start avec le Sommet 3
	printf("Start Sommet 3\n");
	marquerVoisins(g->adj, g->V, 3);
	marquerTousLesVoisins(g->adj, g->V, 3);

    // Start avec le Sommet 4
	printf("Start Sommet 4\n");
	marquerVoisins(g->adj, g->V, 4);
	marquerTousLesVoisins(g->adj, g->V, 4);




    return 0;
}
