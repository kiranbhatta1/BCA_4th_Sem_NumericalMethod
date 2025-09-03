#include <stdio.h>

int main() {
    int n, i;
    float x[100], y[100];
    float sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;
    float a, b;

    printf("Enter the number of data points (n): ");
    scanf("%d", &n);

    printf("Enter values of x:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i + 1);
        scanf("%f", &x[i]);
    }

    printf("Enter values of y:\n");
    for (i = 0; i < n; i++) {
        printf("y[%d] = ", i + 1);
        scanf("%f", &y[i]);
    }

    for (i = 0; i < n; i++) {
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumx2 += x[i] * x[i];
    }

    a = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    b = (sumy - a * sumx) / n;

    printf("\nEquation of best fit line: y = %.2fx + %.2f\n", a, b);

    return 0;
}
