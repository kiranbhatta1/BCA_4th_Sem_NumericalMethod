#include <stdio.h>
#include <math.h>
double f(double x) {
    return (x * sin(x) + cos(x));
}

int main() {
    double a, b, E, c;
    int maxIter = 1000, iter = 0;

    printf("Enter initial interval (a, b): ");
    scanf("%lf %lf", &a, &b);

    printf("Enter error tolerance (E): ");
    scanf("%lf", &E);
    if (f(a) * f(b) > 0) {
        printf("Invalid interval. Root may not exist between (a, b).\n");
        return 0;
    }
    do {
        c = (a + b) / 2.0;

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        iter++;
        if (iter > maxIter) {
            printf("Method did not converge.\n");
            return 0;
        }

    } while (fabs(f(c)) > E);

    printf("Root = %.6f (after %d iterations)\n", c, iter);
    return 0;
}
