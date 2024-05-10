// Nom du fichier : main.c
// Auteur : Julien d'Aboville

#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include "t_arete.h"
#include "prim.h"

int main() {

    Graph *g = chargeGraphe();


    t_arete **arbre = prim(g->adj, g->V);

    // Afficher la matrice d'adjacence du graphe
    printf("Matrice d'adjacence du graphe :\n");
    for (int i = 0; i < g->V; i++) {
        for (int j = 0; j < g->V; j++) {
            printf("%f ", g->adj[i][j]);
        }
        printf("\n");
    }

    // Afficher les arêtes de l'arbre de poids minimal
    for (int i = 0; i < g->V - 1; i++) {
        printf("Arete (%d,%d)\n", arbre[i]->sommet1, arbre[i]->sommet2);
    }



    return 0;
}
