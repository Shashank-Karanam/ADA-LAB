#include <stdio.h>

void sortItems(int n, float weight[], float value[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            float r1 = value[i] / weight[i];
            float r2 = value[j] / weight[j];
            if (r1 < r2) {
                // Swap value
                float temp = value[i];
                value[i] = value[j];
                value[j] = temp;

                // Swap weight
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }
}

float fractionalKnapsack(int n, float weight[], float value[], float capacity) {
    sortItems(n, weight, value);

    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= weight[i]) {
            totalValue += value[i];
            capacity -= weight[i];
        } else {
            totalValue += value[i] * (capacity / weight[i]);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n;
    float capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    float weight[100], value[100];

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%f %f", &weight[i], &value[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);

    float maxValue = fractionalKnapsack(n, weight, value, capacity);
    printf("Maximum value in knapsack = %.2f\n", maxValue);

    return 0;
}
