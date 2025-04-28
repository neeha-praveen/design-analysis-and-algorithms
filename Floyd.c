#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 99999  // Internal representation of infinity

void printSolution(int **dist, int V) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int **graph, int V) {
    int **dist = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        dist[i] = (int *)malloc(V * sizeof(int));

    // Initialize the solution matrix same as input graph matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Floyd-Warshall Algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist, V);

    // Free allocated memory
    for (int i = 0; i < V; i++)
        free(dist[i]);
    free(dist);
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Allocate memory for the graph
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        graph[i] = (int *)malloc(V * sizeof(int));

    printf("Enter the adjacency matrix (enter 'INF' for infinity):\n");

    char input[10];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%s", input);
            if (strcmp(input, "INF") == 0)
                graph[i][j] = INF;
            else
                graph[i][j] = atoi(input);
        }
    }

    floydWarshall(graph, V);

    // Free allocated memory
    for (int i = 0; i < V; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
