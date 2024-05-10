// Nom du fichier : file.h
// Auteur : Julien d'Aboville


#ifndef __FILE__H__
#define __FILE__H__

enum boolean{
	FALSE=0,
	TRUE=1
}boolean;


static int indeF=0;

typedef struct file {
	int valeur;
	struct file *back;
	struct file *next;
} file;


file* NouvelFile(int valeur);

enum boolean EstVideFile(file *liste) ;
void InsererFile(int pl, file *cel, file *liste);
void Afficher(file *liste);
int SupprimeFile(int pl, file *liste);

#endif
