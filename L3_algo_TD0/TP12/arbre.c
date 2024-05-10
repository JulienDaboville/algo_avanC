// Nom du fichier : arbre.c
// Auteur : Julien d'Aboville



#include <stdlib.h>
#include "arbre.h"
#include <stdio.h>

noeud* nouvNoeud(char carac) {
	noeud *n = malloc(sizeof(noeud));

	if (n == NULL) {
		printf("Problème d'allocation de mémoire");
	}

	n->filsG = NULL;
	n->filsD = NULL;
	n->carac = carac;

	num_creation++;
	n->num_noeud = num_creation;

	return n;
}

noeud* rechercheNoeud(noeud *n, int num_noeud) {
	noeud *tmpNoeud;

	if (n == NULL) {
		return NULL;
	}

	if (n->num_noeud == num_noeud) {
		return n;
	}

	tmpNoeud = rechercheNoeud(n->filsG, num_noeud);
	if (tmpNoeud != NULL) {
		return tmpNoeud;
	}

	return rechercheNoeud(n->filsD, num_noeud);
}

void insererFG(noeud *n, noeud *arbre, int num_noeud) {
	noeud *tmpNoeud = rechercheNoeud(arbre, num_noeud);

	if (tmpNoeud->filsG == NULL) {
		tmpNoeud->filsG = n;
	} else {
		n->filsG = tmpNoeud->filsG;
		tmpNoeud->filsG = n;
	}
}

void insererFD(noeud *n, noeud *arbre, int num_noeud) {
	noeud *tmpNoeud = rechercheNoeud(arbre, num_noeud);

	if (tmpNoeud->filsD == NULL) {
		tmpNoeud->filsD = n;
	} else {
		n->filsD = tmpNoeud->filsD;
		tmpNoeud->filsD = n;
	}
}

void parcoursPrefixe(noeud *arbre) {
	printf("Caractère : %c \n", arbre->carac);

	if (arbre->filsG != NULL) {
		parcoursPrefixe(arbre->filsG);
	}

	if (arbre->filsD != NULL) {
		parcoursPrefixe(arbre->filsD);
	}

	return;
}

void parcoursSuffixe(noeud *arbre) {
	if (arbre->filsG != NULL) {
		parcoursSuffixe(arbre->filsG);
	}

	if (arbre->filsD != NULL) {
		parcoursSuffixe(arbre->filsD);
	}

	printf("Caractère : %c \n", arbre->carac);
	return;
}

void parcoursInfixe(noeud *arbre) {
	if (arbre->filsG != NULL) {
		parcoursInfixe(arbre->filsG);
	}

	printf("Caractère : %c \n", arbre->carac);

	if (arbre->filsD != NULL) {
		parcoursInfixe(arbre->filsD);
	}

	return;
}

