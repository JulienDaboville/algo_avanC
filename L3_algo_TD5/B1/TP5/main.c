#include <stdio.h>
#define MAX_VERTICES 100

struct Graph {
	int vertices;
	int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

void addEdge(struct Graph *graph, int u, int v) {
	graph->adjMatrix[u][v] = 1;
	graph->adjMatrix[v][u] = 1;
}

void welshPowell(struct Graph *graph) {
	int degree[MAX_VERTICES] = { 0 };
	int i, j, current_color;

	// Calculate the degree of chaque sommet
	for (i = 0; i < graph->vertices; i++) {
		for (j = 0; j < graph->vertices; j++) {
			if (graph->adjMatrix[i][j] == 1)
				degree[i]++;
		}
	}

	int sorted_vertices[MAX_VERTICES];

	// Initialize vertices in sorted order of degrees
	for (i = 0; i < graph->vertices; i++)
		sorted_vertices[i] = i;

	// Sort vertices in decreasing order of degree using bubble sort
	for (i = 0; i < graph->vertices; i++) {
		for (j = i + 1; j < graph->vertices; j++) {
			if (degree[sorted_vertices[i]] < degree[sorted_vertices[j]]) {
				int temp = sorted_vertices[i];
				sorted_vertices[i] = sorted_vertices[j];
				sorted_vertices[j] = temp;
			}
		}
	} //valide ex:[3,1,2,0,4] listes decroissante des sommets en fonction de leur degree
/*	for (int i = 0; i < graph->vertices; i++) {
		printf("%d \t", sorted_vertices[i]);

	}
	printf("\n");*/

	int color[MAX_VERTICES];//corrige de l'initialisation du tableau color
	for (int i = 0; i < graph->vertices; i++) {
		color[i] = -1;
	}



	current_color = 0;

/*	for (int i = 0; i < graph->vertices; i++) {
		for (j = 0; j < graph->vertices; j++) {
			printf("(%d,%d)=(%d)\n",i,j,graph->adjMatrix[i][j]);

		}
	}

	for (int i = 0; i < graph->vertices; i++) {
		printf("%d : %d \t", i, color[i]);

	}
	printf("\n");*/

	for (i = 0; i < graph->vertices; i++) {
		int vertex = sorted_vertices[i]; //2
		//printf("sommet vertex :%d \n", vertex);
		if (color[vertex] == -1) { // si le sommet n'a pas encore ete colore
			color[vertex]=current_color;

			for (j = 0; j < graph->vertices; j++) {
				//printf(" sommet j:%d \n", j);
				if (graph->adjMatrix[vertex][j] == 0 && color[j] == -1 ) {
					//printf("(i,j)=(%d,%d)\n", i, j);
					//printf("apres: sommet %d \n", vertex);
					color[j] = current_color;

					break;
				}
			}
			current_color++;


		}
	}

	int num_colors = current_color;

	printf("Graph colored using %d colors:\n", num_colors);
	for (i = 0; i < graph->vertices; i++) {
		printf("Vertex %d: Color %d\n", i, color[i]);
	}
}

int main() {
	struct Graph graph;
	graph.vertices = 5;

// Add edges
	addEdge(&graph, 0, 1);
	addEdge(&graph, 0, 2);
	addEdge(&graph, 1, 2);
	addEdge(&graph, 1, 3);
	addEdge(&graph, 2, 3);
	addEdge(&graph, 3, 4);

	welshPowell(&graph);

	return 0;
}
