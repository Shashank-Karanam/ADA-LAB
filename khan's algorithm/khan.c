#include <stdio.h>
#define MAX 100

int main() {
    int n, e, adj[MAX][MAX], in_degree[MAX] = {0};
    int queue[MAX], front = 0, rear = -1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // Input edges and build adjacency matrix
    printf("Enter edges (from to):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        in_degree[v]++;
    }

    // Enqueue vertices with in-degree 0
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0)
            queue[++rear] = i;
    }

    int count = 0;
    printf("Topological Sort Order:\n");
    while (front <= rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                in_degree[i]--;
                if (in_degree[i] == 0)
                    queue[++rear] = i;
            }
        }
    }

    if (count != n)
        printf("\nCycle detected! Topological sort not possible.\n");

    return 0;
}
