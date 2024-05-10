// Nom du fichier : graphe.c
// Auteur : Julien d'Aboville

#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void genereGraphe(float **adjacente, int taille, double probabilite) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (i != j && drand48() < probabilite) {
                adjacente[i][j] = 1;
                adjacente[j][i] = 1;
            }
        }
    }
}

Graph* chargeGraphe() {
    Graph *G = malloc(sizeof(Graph));
    if (!G) {
        printf("Problème d'allocation mémoire");
        exit(EXIT_FAILURE);
    }

    printf("Entrez le nombre de sommets et d'arêtes : ");
    scanf("%d %d", &G->V, &G->E);

    G->adj = malloc(sizeof(float*) * G->V);
    if (!G->adj) {
        printf("Problème d'allocation mémoire");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < G->V; i++) {
        G->adj[i] = malloc(sizeof(float) * G->V);
        if (!G->adj[i]) {
            printf("Problème d'allocation mémoire");
            exit(EXIT_FAILURE);
        }
    }

    for (int u = 0; u < G->V; u++) {
        for (int v = 0; v < G->V; v++) {
            G->adj[u][v] = 0;
        }
    }

    for (int i = 0; i < G->E; i++) {
        int u, v;
        float poids;
        printf("Choisissez u, v et le poids de l'arête : ");
        scanf("%d %d %f", &u, &v, &poids);
        G->adj[u][v] = poids;
        G->adj[v][u] = poids;
    }

    printf("Fin de chargeGraphe()\n");

    return G;
}

