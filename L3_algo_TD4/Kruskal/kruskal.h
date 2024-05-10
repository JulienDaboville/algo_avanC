// Nom du fichier : kruskal.h
// Auteur : Julien d'Aboville

#ifndef __KRUSKAL_H__
#define __KRUSKAL_H__


typedef struct {
    int x, y, poids;
} t_arete;


int comparaison(const void* a, const void* b);
t_arete* kruskal(t_arete* graphe, int ordre, int s, int n);

#endif
