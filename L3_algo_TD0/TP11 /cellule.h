// Nom du fichier : cellule.h
// Auteur : Julien d'Aboville


#ifndef __CELLULE__H__
#define __CELLULE__H__
typedef struct point{
	int x,y;

}point;



typedef struct cellule{
	point p;
	struct cellule *back;
	struct cellule *next;
}cellule;

cellule *NouvelCel(point p);
void InsererCellule(int pl,cellule *cel,cellule *liste);
void Afficher(cellule *liste);
void SupprimeCellule(int pl,cellule *liste);


#endif
