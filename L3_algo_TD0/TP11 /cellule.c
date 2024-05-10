// Nom du fichier : cellule.c
// Auteur : Julien d'Aboville

#include <stdio.h>
#include <stdlib.h>
#include "cellule.h"


cellule *NouvelCel(point p) {
    cellule *c = malloc(sizeof(cellule));
    if (c == NULL) {
        printf("Problème de mémoire");
        return NULL;
    }
    c->p = p;
    c->back = NULL;
    c->next = NULL;
    return c;
}

void InsererCellule(int pl, cellule *cel, cellule *liste) {
    cellule *Celcourante;
    int compteur = 0;
    Celcourante = liste;
    while (pl != compteur && Celcourante != NULL) {
        compteur++;
        Celcourante = Celcourante->next;
    }
    if (Celcourante == NULL) {
        printf("La place n'existe pas");
    } else {
        cel->back = Celcourante;
        Celcourante->next = cel;
    }
}

void Afficher(cellule *liste) {
    cellule *Celcourante;
    int compteur = 0;
    int i = 0;
    Celcourante = liste;
    while (Celcourante->next != NULL) {
        Celcourante = Celcourante->next;
        printf("Place n°%d === %d %d\n", i + 1, Celcourante->p.x, Celcourante->p.y);
        i++;
        printf("\n");
    }
}

void SupprimeCellule(int pl, cellule *liste) {
    int compteur = 0;
    cellule *Celcourante;
    Celcourante = liste;
    while (Celcourante != NULL && pl != compteur) {
        Celcourante = Celcourante->next;
        compteur++;
    }
    Celcourante->back->next = Celcourante->next;
    if (Celcourante->next != NULL) {
        Celcourante->next->back = Celcourante->back;
    }
}

