#include <stdio.h>
#define LEFT -1
#define RIGHT 1

int getMobile(int a[], int dir[], int n) {
    int mobile = 0, index = -1;
    for (int i = 0; i < n; i++) {
        if (dir[i] == LEFT && i > 0 && a[i] > a[i - 1] && a[i] > mobile) {
            mobile = a[i];
            index = i;
        }
        if (dir[i] == RIGHT && i < n - 1 && a[i] > a[i + 1] && a[i] > mobile) {
            mobile = a[i];
            index = i;
        }
    }
    return index;
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void johnsonTrotter(int n) {
    int a[n], dir[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    print(a, n);

    for (int count = 1; count < tgamma(n + 1); count++) {
        int m = getMobile(a, dir, n);
        if (m == -1) break;

        int swapWith = (dir[m] == LEFT) ? m - 1 : m + 1;
        swap(&a[m], &a[swapWith]);
        swap(&dir[m], &dir[swapWith]);
        m = swapWith;

        for (int i = 0; i < n; i++)
            if (a[i] > a[m])
                dir[i] = -dir[i];

        print(a, n);
    }
}

int main() {
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}
