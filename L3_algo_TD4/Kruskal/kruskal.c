// Nom du fichier : kruskal.c
// Auteur : Julien d'Aboville

#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"


int comparaison(const void* a, const void* b) {
    return ((t_arete*)a)->poids - ((t_arete*)b)->poids;
}
t_arete* kruskal(t_arete* graphe, int ordre, int s, int n) {

    t_arete* arbre;
    int* connexe;
    int indiceA = 0, indiceG = 0;
    int x, s1, s2;
    t_arete u;

    arbre = (t_arete*)malloc((ordre - 1) * sizeof(t_arete));

    connexe = (int*)malloc(ordre * sizeof(int));

    for (x = 0; x < ordre; x++) connexe[x] = x;
    qsort(graphe, n, sizeof(t_arete), comparaison);

    while (indiceA < ordre - 1 && indiceG < n) {
        u = graphe[indiceG];
        s1 = connexe[u.x];
        s2 = connexe[u.y];


        if (s1 == s2)
            indiceG++;
        else {
            arbre[indiceA] = u;
            indiceA++;
            indiceG++;


            for (x = 0; x < ordre; x++)
                if (connexe[x] == s1) connexe[x] = s2;
        }
    }

    if (indiceA < ordre - 1) {
        printf("Le graphe n'est pas connexe\n");
    }

    free(connexe);
    return arbre;
}
