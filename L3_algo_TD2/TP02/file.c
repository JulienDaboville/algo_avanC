// Nom du fichier : file.c
// Auteur : Julien d'Aboville
#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

file* NouvelFile(int valeur) {
	file *c = malloc(sizeof(file));
	if (c == NULL) {
		printf("Problème de mémoire");
		return NULL;
	}
	c->valeur = valeur;
	c->back = NULL;
	c->next = NULL;
	return c;
}

enum boolean EstVideFile(file *liste) {
	file *Celcourante = liste;
	if (Celcourante->next == NULL) {
		return TRUE;
	} else {
		return FALSE;
	}
}

void InsererFile(int pl, file *cel, file *liste) {
	file *Celcourante;
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
	indeF++;
}

void Afficher(file *liste) {
	file *Celcourante;
	int i = 0;
	Celcourante = liste;
	while (Celcourante->next != NULL) {
		Celcourante = Celcourante->next;
		printf("Place n°%d === %d \n", i + 1, Celcourante->valeur);
		i++;
		printf("\n");
	}
}

int SupprimeFile(int pl, file *liste) {
	int compteur = 0;
	int ret = 0;
	file *Celcourante;
	Celcourante = liste;
	while (Celcourante != NULL && pl != compteur) {
		Celcourante = Celcourante->next;
		compteur++;
	}
	ret = Celcourante->valeur;
	Celcourante->back->next = Celcourante->next;
	if (Celcourante->next != NULL) {
		Celcourante->next->back = Celcourante->back;
	}
	indeF--;
	return ret;
}
