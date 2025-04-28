#include <stdio.h>
#define INF 9999
#define MAX 20

void prims(int graph[MAX][MAX], int n) {
    int selected[MAX] = {0};
    int edges = 0, totalCost = 0;

    selected[0] = 1; // Start from vertex 0 (A)
    printf("\nPrim's Algorithm Traversal:\n");

    while (edges < n - 1) {
        int min = INF;
        int x = -1, y = -1;

        printf("\n%d:\n", edges + 1);
        printf("current selected vertices: ");
        for (int i = 0; i < n; i++)
            if (selected[i]) printf("%c ", i + 'A');
        printf("\n");

        // Find the minimum edge from selected to unselected vertex
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x != -1 && y != -1) {
            printf("selected edge: %c - %c --> weight: %d\n", x + 'A', y + 'A', graph[x][y]);
            totalCost += graph[x][y];
            selected[y] = 1;
            edges++;
        }
    }

    printf("\nMST made\n");
    printf("total weight of MST: %d\n", totalCost);
}

int main() {
    int n, graph[MAX][MAX];

    printf("enter number of vertices: ");
    scanf("%d", &n);

    printf("input adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }

    prims(graph, n);

    return 0;
}
