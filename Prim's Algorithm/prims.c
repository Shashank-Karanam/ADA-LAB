#include <stdio.h>
#define INF 9999
#define V 100  // Maximum number of vertices

void prims(int graph[V][V], int n) {
    int selected[V] = {0};  // 0 = not selected, 1 = selected
    int no_edge = 0;
    int x, y;
    int total_weight = 0;

    selected[0] = 1;

    printf("Edge : Weight\n");

    while (no_edge < n - 1) {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, graph[x][y]);
        total_weight += graph[x][y];
        selected[y] = 1;
        no_edge++;
    }

    printf("Total weight of MST: %d\n", total_weight);
}

int main() {
    int n = 5; // Number of vertices
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prims(graph, n);

    return 0;
}
