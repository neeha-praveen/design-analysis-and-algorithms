#include <stdio.h>

#define MAX 20
#define INF 9999

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to find the root of a vertex
int find(int parent[], int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}

// Function to do union of two subsets
void unionSet(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}

void kruskal(int graph[MAX][MAX], int n) {
    struct Edge edges[MAX * MAX];
    int parent[MAX], edgeCount = 0, totalCost = 0;

    // Convert adjacency matrix to edge list
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Avoid duplicates
            if (graph[i][j] != INF) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

    // Sort edges by weight (bubble sort)
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize parent
    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("\nKruskal's Algorithm Traversal:\n");

    int edgesAdded = 0;
    for (int i = 0; i < edgeCount && edgesAdded < n - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        printf("Considering edge: %c - %c (Weight: %d)\n", u + 'A', v + 'A', edges[i].weight);

        int uRoot = find(parent, u);
        int vRoot = find(parent, v);

        if (uRoot != vRoot) {
            printf("Added to MST\n");
            unionSet(parent, uRoot, vRoot);
            totalCost += edges[i].weight;
            edgesAdded++;
        } else {
            printf("Discarded (would form a cycle)\n");
        }
    }

    printf("\nMinimum Spanning Tree constructed.\n");
    printf("Total weight of MST: %d\n", totalCost);
}

int main() {
    int graph[MAX][MAX], n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (i != j && graph[i][j] == 0)
                graph[i][j] = INF;
        }

    kruskal(graph, n);

    return 0;
}
