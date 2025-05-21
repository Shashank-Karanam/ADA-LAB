#include <stdio.h>

#define N 3

int costMatrix[N][N] = {
    {9, 2, 7},
    {6, 4, 3},
    {5, 8, 1}
};

int minCost = 9999;
int bestPerm[N];

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void calculateCost(int perm[]) {
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += costMatrix[i][perm[i]];
    }
    if (total < minCost) {
        minCost = total;
        for (int i = 0; i < N; i++)
            bestPerm[i] = perm[i];
    }
}

void generatePermutations(int perm[], int l, int r) {
    if (l == r) {
        calculateCost(perm);
    } else {
        for (int i = l; i <= r; i++) {
            swap(&perm[l], &perm[i]);
            generatePermutations(perm, l + 1, r);
            swap(&perm[l], &perm[i]);
        }
    }
}

int main() {
    int perm[N] = {0, 1, 2};

    generatePermutations(perm, 0, N - 1);

    printf("Minimum cost: %d\n", minCost);
    printf("Best assignment:\n");
    for (int i = 0; i < N; i++) {
        printf("Person %d -> Job %d (Cost: %d)\n", i + 1, bestPerm[i] + 1, costMatrix[i][bestPerm[i]]);
    }

    return 0;
}
