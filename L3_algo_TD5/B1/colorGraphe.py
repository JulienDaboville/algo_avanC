
import networkx as nx
import matplotlib.pyplot as plt

import time
import random




class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adjMatrix = [[0] * vertices for _ in range(vertices)]

    def add_edge(self, u, v):
        self.adjMatrix[u][v] = 1
        self.adjMatrix[v][u] = 1

    def is_safe(self, v, color, c):
        for i in range(self.vertices):
            if self.adjMatrix[v][i] == 1 and color[i] == c:
                return False
        return True

    def graph_coloring_util(self, m, color, v):
        if v == self.vertices:
            return True

        for c in range(1, m+1):
            if self.is_safe(v, color, c):
                color[v] = c
                if self.graph_coloring_util(m, color, v+1):
                    return True
                color[v] = 0

    def graph_coloring(self, m):
        color = [0] * self.vertices
        if not self.graph_coloring_util(m, color, 0):
            return False

        print("Graph can be colored using {} colors:".format(m))
        for i in range(self.vertices):
            print("Vertex {}: Color {}".format(i, color[i]))

        return True













def generate_random_graph(num_vertices, probability):
    G = nx.Graph()
    for i in range(num_vertices):
        for j in range(i + 1, num_vertices):
            if random.random() < probability:
                G.add_edge(i, j)
    return G

# Liste des tailles de graphes que vous voulez tester
graph_sizes = [10, 100, 1000]

# Probabilité d'avoir une arête entre deux sommets
edge_probability = 0.2

fig, axes = plt.subplots(1, len(graph_sizes), figsize=(15, 5))

for i, num_vertices in enumerate(graph_sizes):
    G = generate_random_graph(num_vertices, edge_probability)
    
    start_time = time.time()
    
    g = Graph(num_vertices)
    for edge in G.edges():
        g.add_edge(edge[0], edge[1])

    m = 70  # Number of colors
    g.graph_coloring(m)

    end_time = time.time()
    execution_time = end_time - start_time

    print(f"Taille du graphe : {num_vertices}, Temps d'exécution : {execution_time} secondes")

    # Visualisation du graphe
    pos = nx.spring_layout(G)
    nx.draw(G, pos, with_labels=True, node_color='lightblue', edge_color='gray', ax=axes[i])
    axes[i].set_title(f"Graph {num_vertices} vertices")

plt.show()







"""

g = Graph(5)

g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(1, 3)
g.add_edge(2, 3)
g.add_edge(3, 4)

m = 3  # Number of colors
g.graph_coloring(m)





# Create an empty graph
G = nx.Graph()

# Add vertices (nodes) to the graph
G.add_nodes_from([1, 2, 3, 4, 5])

# Add edges to the graph
G.add_edges_from([(1, 2), (2, 3), (3, 4), (4, 5), (5, 1)])

# Draw the graph
nx.draw(G, with_labels=True, node_color='lightblue', edge_color='gray')

# Show the graph
plt.show()
"""



