#include <stdio.h>

int twoStacks(int maxSum, int a[], int n, int b[], int m) {
    int sum = 0, count = 0, temp = 0, i = 0, j = 0;

    while (i < n && sum + a[i] <= maxSum) { 
        sum += a[i++];
    }
    count = i;

    while (j < m && i >= 0) { 
        sum += b[j++];
        while (sum > maxSum && i > 0) {
            sum -= a[--i];
        }
        if (sum <= maxSum && i + j > count) {
            count = i + j;
        }
    }
    return count;
}

int main() {
    int g;
    printf("Masukkan bilangan dibawah ini \n");
    scanf("%d", &g);
    while (g--) {
        int n, m, maxSum;
        scanf("%d%d%d", &n, &m, &maxSum);
        int a[n], b[m];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        printf("%d\n", twoStacks(maxSum, a, n, b, m));
    }
    return 0;
}
