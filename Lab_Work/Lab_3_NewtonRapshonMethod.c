#include <stdio.h>
#include <math.h>

// Function: f(x) = x * log10(x) - 12
#define f(x) ((x) * log10(x) - 12)

// Derivative: f'(x) = log10(x) + 1 / ln(x)
#define g(x) (log10(x) + 1.0 / log(x))

int main() {
    float x0, x1, error;
    int i = 0;

    // Input initial guess
    printf("Enter initial guess (x0): ");
    scanf("%f", &x0);

    // Check that x0 is positive
    if (x0 <= 0) {
        printf("Initial guess must be positive.\n");
        return 1;
    }

    // Input tolerance error
    printf("Enter tolerance (error): ");
    scanf("%f", &error);

    printf("\n----------------------------------------------\n");
    printf("i\t   x0\t\t   x1\t\t   f(x1)\n");
    printf("----------------------------------------------\n");

    // Loop until f(x1) is smaller than the error
    do {
        x1 = x0 - f(x0) / g(x0);  // Newton-Raphson formula
        printf("%d\t%f\t%f\t%f\n", i, x0, x1, f(x1));

        x0 = x1;  // Update x0 for next iteration
        i++;
    } while (fabs(f(x1)) > error);  // Check if close enough to root

    printf("----------------------------------------------\n");
    printf("Root found: %f\n", x1);
    printf("f(x1): %f\n", f(x1));

    return 0;
}
