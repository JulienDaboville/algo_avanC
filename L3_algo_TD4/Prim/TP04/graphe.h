// Nom du fichier : graphe.h
// Auteur : Julien d'Aboville

#ifndef __GRAPHE__H__
#define __GRAPHE__H__

static int ordre_marquage = 0;
static int indeF = 0;

typedef struct Graph {
    int V;
    int E;
    float **adj;
} Graph;

Graph* chargeGraphe();
void genereGraphe(float **adjacente, int taille, double probabilite);

#endif
