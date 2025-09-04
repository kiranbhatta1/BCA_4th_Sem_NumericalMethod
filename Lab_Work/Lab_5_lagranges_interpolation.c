#include <stdio.h>

int main() {
    float X[99], Y[99], x0, y0 = 0, term;
    int i, j, n;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x and y:\n");
    for (i = 0; i < n; i++) {
        printf("X[%d] = ", i);
        scanf("%f", &X[i]);
        printf("Y[%d] = ", i);
        scanf("%f", &Y[i]);
    }

    printf("Enter x0 = ");
    scanf("%f", &x0);

    for (i = 0; i < n; i++) {
        term = Y[i];
        for (j = 0; j < n; j++) {
            if (j != i) {
                term = term * (x0 - X[j]) / (X[i] - X[j]);
            }
        }
        y0 += term;
    }

    printf("Interpolated value at x = %.3f is %.3f\n", x0, y0);

    return 0;
}
