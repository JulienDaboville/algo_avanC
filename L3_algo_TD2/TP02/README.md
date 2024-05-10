# TP n°2 : Connexion et chemins
## Table of Contents
1. [General Info](#general-info)
2. [Technologies](#technologies)
3. [Installation](#installation)




### General Info
***
Ce programme permet d'obtenir le plus court chemin depuis un sommet de référence d'un graphe manuellement ou pour des graphes générés automatiquement. Si le choix est automatiquement le programme calculera leur complexité.


Les fonctions utilisés sont :
-void plusCourtChemin(int **adjacence, int ordre, int s, int *lm, int *pred)


-file* NouvelFile(int valeur)  // Crée une nouvelle cellule (élément de la file) avec la valeur spécifiée.
-enum boolean EstVideFile(file *liste)  // Vérifie si la file est vide.
-void InsererFile(int pl, file *cel, file *liste)  // Insère une nouvelle cellule à la position spécifiée dans la liste.
-void Afficher(file *liste) // Affiche les valeurs de toutes les cellules dans la liste.
-int SupprimeFile(int pl, file *liste) // Supprime une cellule à la position spécifiée dans la liste et retourne sa valeur.


-void genereGraphe(int **adjacente, int taille, double probabilité) // Génère un graphe aléatoire avec la probabilité spécifiée.
-Graph* chargeGraphe() // Charge un graphe à partir de l'entrée utilisateur.




void mesureTemps(int taille,FILE *fic) //mesure le la complexite temporelle en fonction de la taille










## Technologies
***
A list of technologies used within the project:


- [Eclipse IDE for C/C++ Developers - 2023-06](https://www.eclipse.org/downloads/packages/release/2023-06/r/eclipse-ide-cc-developers)
-IDLE pour python 
https://www.python.org/downloads/release/python-3130a1/




## Installation
***


Installer Eclipse via le lien en fonction de votre système d'exploitation
        


Une fois l'IDE installé :
        -Cliquer sur l'application Eclipse
        -Ouvrir un workspace au choix
        -Cliquer sur File (en haut tout à gauche).
        -Cliquer sur Open Projects from File System
        -Cliquer sur Archive, puis selectionner le fichier .zip
        -Cliquer sur Finish


Une fois IDLE installé :  
        -Cliquer sur l'application IDLE
-Cliquer sur File
-Cliquer sur "Open" pour ouvrir le fichier        
-Pour exécuter votre code Python, cliquez sur "Run" dans la barre de menu, puis sélectionnez "Run Module" ou appuyez sur la touche F5. Cela exécutera votre code Python et affichera les résultats dans la console IDLE
