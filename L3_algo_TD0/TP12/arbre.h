// Nom du fichier : arbre.h
// Auteur : Julien d'Aboville



#ifndef __ARBRE__H__
#define __ARBRE__H__



static int num_creation=0;


typedef struct noeud{
	int num_noeud;
	char carac;
	struct noeud *filsG;
	struct noeud *filsD;

}noeud;


noeud* nouvNoeud(char carac);
noeud* rechercheNoeud(noeud *n, int num_noeud);
void insererFG(noeud *n,noeud *arbre,int num_noeud);
void insererFD(noeud *n,noeud *arbre,int num_noeud);
void parcoursPrefixe(noeud *arbre);
void parcoursSuffixe(noeud *arbre);
void parcoursInfixe(noeud *arbre);

#endif
