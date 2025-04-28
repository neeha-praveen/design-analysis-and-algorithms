#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX 100

int getIndex(char vertices[], int V, char label) {
    for (int i = 0; i < V; i++)
        if (vertices[i] == label)
            return i;
    return -1;
}

int minDistance(int dist[], int visited[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

void printSolution(int dist[], int V, char vertices[]) {
    printf("\nVertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%c\t%d\n", vertices[i], dist[i]);
}

void dijkstra(int graph[MAX][MAX], int V, int src, char vertices[]) {
    int dist[MAX], visited[MAX];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, V, vertices);
}

int main() {
    int V;
    char vertices[MAX];
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter vertex labels (e.g., A B C ...):\n");
    for (int i = 0; i < V; i++)
        scanf(" %c", &vertices[i]);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    char src_label;
    printf("Enter source vertex label: ");
    scanf(" %c", &src_label);

    int src = getIndex(vertices, V, src_label);
    if (src == -1) {
        printf("Invalid source vertex label.\n");
        return 1;
    }

    dijkstra(graph, V, src, vertices);

    return 0;
}
