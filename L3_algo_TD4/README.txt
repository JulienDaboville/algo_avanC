# TP n°4 :Arbre Couvrant
## Table of Contents
1. [General Info](#general-info)
2. [Technologies](#technologies)
3. [Installation](#installation)




### General Info
***
Le 1er programme permet d’obtenir l’arbre couvrant de poids minimum d’un graphe  valué non orienté depuis un sommet de référence aléatoire avec l’algo de Pim


Les fonctions utilisés sont : 




-Graph* chargeGraphe()  // Crée un graphe et charge la matrice d'adjacence depuis l'entrée utilisateur.
-t_arete* prim(float **adjacencePoids, int ordre) // Fonction qui retourne l’arbre couvrant de poids minimum d’un graphe valué et non orienté depuis un sommet de référence aléatoire
-void creerArete (t_arete **arbre,int sommet1,int sommet2,int indice) //creer une arete avec sommet1 et sommet2 a la position indice du tableau d’arete




Le 2eme programme permet d’obtenir l’arbre couvrant de poids minimum d’un graphe valué non orienté depuis un sommet de référence avec l’algo de Kruskal


-t_arete* kruskal(t_arete* graphe, int ordre, int s, int n) // Fonction qui retourne l’arbre couvrant de poids minimum d’un graphe valué et non orienté // depuis un sommet de référence
-int comparaison(const void* a, const void* b) compare le poids des aretes a et b




## Technologies
***
A list of technologies used within the project:


* [Eclipse IDE for C/C++ Developers - 2023-06](https://www.eclipse.org/downloads/packages/release/2023-06/r/eclipse-ide-cc-developers)


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