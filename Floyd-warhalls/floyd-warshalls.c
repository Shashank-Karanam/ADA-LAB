#include <stdio.h>
#define INF 99999
#define V 100  // Maximum number of vertices

void floydWarshall(int graph[V][V], int n) {
    int dist[V][V];

    // Step 1: Initialize distance matrix with the input graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Step 2: Run Floyd-Warshall: check if path i->k->j is shorter than i->j
    for (int k = 0; k < n; k++) {          // Pick all vertices as intermediate
        for (int i = 0; i < n; i++) {      // From each vertex i
            for (int j = 0; j < n; j++) {  // To each vertex j
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Step 3: Print the final shortest distance matrix
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V], n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 if no edge, 0 for diagonal):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (i != j && graph[i][j] == 0)  // No edge but not same node
                graph[i][j] = INF;
        }
    }

    floydWarshall(graph, n);
    return 0;
}
