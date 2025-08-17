#include <stdio.h>
#include <conio.h>
#include <math.h>

// Define the function
double f(double x) {
    return (x * sin(x) + cos(x));  
    // your function was written with *x sin(x) -> syntax error
}

void main() {
    double a, b, E, c;

    printf("Enter initial interval (a, b): ");
    scanf("%lf %lf", &a, &b);

    printf("Enter error tolerance (E): ");
    scanf("%lf", &E);

    if (f(a) * f(b) > 0) {
        printf("Invalid interval. Root may not exist between (a, b).\n");
        return;  
    }

    do {
        c = (a + b) / 2.0;

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

    } while (fabs(f(c)) > E);

    printf("Root = %.6f\n", c); 
    getch();
}
