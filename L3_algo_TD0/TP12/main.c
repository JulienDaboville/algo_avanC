// Nom du fichier : main.c
// Auteur : Julien d'Aboville

#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

int main() {
    // Création de quelques nœuds
    noeud *n1 = nouvNoeud('B');
    noeud *n2 = nouvNoeud('A');
    noeud *n3 = nouvNoeud('O');
    noeud *n4 = nouvNoeud('R');
    noeud *n5 = nouvNoeud('V');

    // Insertion des nœuds dans l'arbre
    insererFG(n2, n1, 1);
    insererFD(n3, n1, 1);
    insererFG(n4, n1, 1);
    insererFD(n5, n1, 4);

    // Affichage des parcours
    printf("PARCOURS PREFIXE :\n");
    parcoursPrefixe(n1);

    printf("PARCOURS SUFFIXE :\n");
    parcoursSuffixe(n1);

    printf("PARCOURS INFIXE :\n");
    parcoursInfixe(n1);

    return 0;
}
