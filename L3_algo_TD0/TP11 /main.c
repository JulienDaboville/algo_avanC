// Nom du fichier : main.c
// Auteur : Julien d'Aboville

#include <stdio.h>
#include <stdlib.h>
#include "cellule.h"

int main() {
    cellule *l, *c;
    point p;
    int place, rep;

    p.x = -1;
    p.y = -1;
    l = NouvelCel(p);

    do {
        printf("Que voulez-vous faire?\n");
        printf("1 - Inserer une nouvelle cellule\n");
        printf("2 - Supprimer une cellule\n");
        printf("3 - Afficher la liste\n");
        printf("4 - Quitter\n");
        scanf("%d", &rep);

        switch(rep) {
            case 1:
                printf("Coordonnées du point à insérer x et y\n");
                scanf("%d %d", &p.x, &p.y);
                printf("Place après laquelle insérer le point?\n");
                scanf("%d", &place);
                c = NouvelCel(p);
                InsererCellule(place, c, l);
                break;

            case 2:
                printf("Place où le point doit être supprimé\n");
                scanf("%d", &place);
                SupprimeCellule(place, l);
                break;

            case 3:
                printf("\nAffichage de la liste\n");
                Afficher(l);
                break;

            case 4:
                break;

            default:
                printf("Mauvais choix\n");
        }
    } while(rep != 4);

    return EXIT_SUCCESS;
}

