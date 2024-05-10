// Nom du fichier : prim.c
// Auteur : Julien d'Aboville

#include "prim.h"
#include "t_arete.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

t_arete* prim(float **adjacencePoids, int ordre) {
    srand(time(NULL));
    t_arete **arbre;
    int indiceA = 0;
    int *marques;
    int s, x, y, ymin;
    float min;

    arbre = malloc(sizeof(t_arete) * (ordre - 1));
    marques = malloc(sizeof(int) * ordre);

    for (int i = 0; i < ordre; i++) {
        marques[i] = 0;
    }

    s = rand() % ordre;
    printf("s : %d\n", s);
    int var = 0;
    marques[s] = 1;
    printf("ordre : %d\n", ordre);

    while (indiceA < ordre - 1) {
        min = INFINI;
        printf("min avant %f\n", min);
        for (x = 0; x < ordre; x++) {
            printf("x : %d\n", x);
            if (marques[x]) {
                for (y = 0; y < ordre; y++) {
                    printf("y : %d\n", y);
                    if (adjacencePoids[x][y] && !marques[y] && adjacencePoids[x][y] < min) {
                        printf("1 fois\n");
                        printf("min avant %f\n", min);
                        min = adjacencePoids[x][y];
                        printf("min apres %f\n", min);

                        ymin = y;
                        var = x;
                    }
                }
            }
        }
        if (!marques[ymin]) {
            printf("ymin :%d\n", ymin);
            marques[ymin] = 1;

            printf("indiceA : %d\n", indiceA);
            creerArete(arbre, var, ymin, indiceA);

            indiceA++;
        }
    }

    printf("fin prim \n");
    return arbre;
}
