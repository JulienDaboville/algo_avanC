// Nom du fichier : graphe.c
// Auteur : Julien d'Aboville

#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void genereGraphe(int **adjacente, int taille, double probabilité) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if ((i != j) && (drand48() < probabilité)) {
                adjacente[i][j] = 1;
                adjacente[j][i] = 1;
            }
        }
    }
}

Graph* chargeGraphe() {
    Graph *G = malloc(sizeof(Graph));
    if (!G) {
        printf("Problème de mémoire");
    }

    printf("Entre le nombre de sommets et d'arêtes : ");
    scanf("%d %d", &G->V, &G->E);

    G->adj = malloc(sizeof(int*) * G->V);

    int i, u, v;
    for (i = 0; i < G->V; i++) {
        G->adj[i] = malloc(sizeof(int) * G->V);
        if (G->adj[i] == NULL) {
            printf("Problème de mémoire");
        }
    }

    for (u = 0; u < G->V; u++) {
        for (v = 0; v < G->V; v++) {
            G->adj[u][v] = 0;
        }
    }

    for (i = 0; i < G->E; i++) {
        printf("Choisissez u et v qui sont les sommets reliés par une arête : ");
        scanf("%d %d", &u, &v);
        G->adj[u][v] = 1;
        G->adj[v][u] = 1;
    }

    return G;
}

