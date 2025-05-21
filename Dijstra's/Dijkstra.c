#include <stdio.h>
#include <limits.h>

#define V 100  // Maximum number of vertices
#define INF 99999

// Function to find the vertex with minimum distance value
int minDistance(int dist[], int visited[], int n) {
    int min = INF, min_index;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src, int n) {
    int dist[V];      // dist[i] holds shortest distance from src to i
    int visited[V];   // visited[i] is true if vertex i is included in shortest path

    // Step 1: Initialize all distances as INF and visited[] as false
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;  // Distance of source to itself is 0

    // Step 2: Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        // Update dist[v] if u is closer and path through u is shorter
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Step 3: Print the final distances
    printf("Vertex \t Distance from Source %d\n", src);
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int graph[V][V], n, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge, 0 for diagonal):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (i != j && graph[i][j] == 0) {
                graph[i][j] = INF;
            }
        }
    }

    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(graph, src, n);

    return 0;
}
