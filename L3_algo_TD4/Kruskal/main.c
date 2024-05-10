// Nom du fichier : main.c
// Auteur : Julien d'Aboville


#include <stdio.h>
#include "kruskal.h"
#include <stdlib.h>

int main() {
    int ordre = 4;
    int n = 5;     

    // Exemple de graphe avec ses arêtes et leurs poids
    t_arete graphe[5] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    t_arete* arbreCouvrant = kruskal(graphe, ordre, 0, n);

    // Affichage de l'arbre couvrant de poids minimum
    printf("Arbre couvrant de poids minimum : \n");
    for (int i = 0; i < ordre - 1; i++) {
        printf("%d -- %d, poids : %d\n", arbreCouvrant[i].x, arbreCouvrant[i].y, arbreCouvrant[i].poids);
    }

    free(arbreCouvrant);

    return 0;
}
