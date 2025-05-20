#include <stdio.h>

#define MAX 100

int parent[MAX];

// Recursive Find with path compression
int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);  // Path compression
    return parent[i];
}

// Union by setting the parent (basic union)
void unionSet(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
    }
}

int main() {
    int n, e;
    int u[MAX], v[MAX], w[MAX];
    int i, j, pos, temp;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter each edge as: u v weight\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    for (i = 0; i < n; i++) {
        parent[i] = i;  // Initially, each node is its own parent
    }

    // Sort edges by weight using selection sort
    for (i = 0; i < e - 1; i++) {
        pos = i;
        for (j = i + 1; j < e; j++) {
            if (w[j] < w[pos])
                pos = j;
        }
        // Swap edges
        temp = w[i]; w[i] = w[pos]; w[pos] = temp;
        temp = u[i]; u[i] = u[pos]; u[pos] = temp;
        temp = v[i]; v[i] = v[pos]; v[pos] = temp;
    }

    int totalCost = 0;
    printf("\nEdges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        int a = find(u[i]);
        int b = find(v[i]);

        if (a != b) {
            printf("%d -- %d == %d\n", u[i], v[i], w[i]);
            totalCost += w[i];
            unionSet(a, b);
        }
    }

    printf("Total cost of MST: %d\n", totalCost);
    return 0;
}
