// Nom du fichier : graphe.h
// Auteur : Julien d'Aboville

#ifndef __GRAPHE__H__
#define __GRAPHE__H__

typedef struct Graph {
    int V;
    int E;
    int **adj;
} Graph;

Graph* chargeGraphe();

void genereGraphe(int **adjacente, int taille, double probabilité);

#endif
