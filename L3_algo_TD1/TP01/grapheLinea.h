// Nom du fichier : grapheLinea.h
// Auteur : Julien d'Aboville

#ifndef __GRAPHELINEA__H__
#define __GRAPHELINEA__H__

typedef struct Graphl {
    int V;
    int E;
    int *adj;
} Graphl;

Graphl* chargeGrapheLinearise();

void marquerTousLesVoisinsLinearise(int* adjacence, int ordre, int s);

#endif
