#include <stdio.h>
#include <math.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int bruteForceKnapsack(int weight[], int value[], int n, int capacity) {
    int maxVal = 0;

    int totalCombinations = pow(2, n);

    for (int i = 0; i < totalCombinations; i++) {
        int totalWeight = 0, totalValue = 0;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {  // check if j-th item is included
                totalWeight += weight[j];
                totalValue += value[j];
            }
        }

        if (totalWeight <= capacity) {
            maxVal = max(maxVal, totalValue);
        }
    }

    return maxVal;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], value[n];

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &weight[i], &value[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    int maxValue = bruteForceKnapsack(weight, value, n, capacity);
    printf("Maximum value in knapsack = %d\n", maxValue);

    return 0;
}
