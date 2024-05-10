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

void marquerVoisins(int** adjacence, int ordre, int s);

int appartient(int y, int *li, int ordre);

void marquerTousLesVoisins(int** adjacence, int ordre, int s);

#endif

