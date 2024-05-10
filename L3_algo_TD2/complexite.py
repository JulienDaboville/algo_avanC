
import pandas as pd

import matplotlib.pyplot as plt


data=pd.read_csv('TP02/donnees_complexite.csv')


taille_graphe=data['Taille du graphe']
temps_calcul=data['Temps de calcul']


plt.plot(taille_graphe, temps_calcul, marker='o', linestyle='-')
plt.xlabel('Taille du graphe')
plt.ylabel('Temps de calcul')
plt.title('Courbe de complexité en fonction de la taille du graphe')
plt.grid(True)


plt.show()
           

