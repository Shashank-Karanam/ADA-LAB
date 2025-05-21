#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];  // Adjacency matrix
int visited[MAX];   // Visited array
int stack[MAX];     // Stack to store result
int top = -1;       // Stack top pointer

void topologicalSort(int v, int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            topologicalSort(i, n);
        }
    }

    stack[++top] = v;  // Push current node after visiting all its neighbors
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (from to):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;  // Directed edge from u to v
    }

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Call DFS for unvisited vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            topologicalSort(i, n);
    }

    printf("Topological Order:\n");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
