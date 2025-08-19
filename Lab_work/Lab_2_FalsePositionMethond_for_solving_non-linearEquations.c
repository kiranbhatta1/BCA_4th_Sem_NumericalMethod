#include <stdio.h>
#include <math.h>

// Define the function
#define f(x) ((x) * exp(x) - cos(x))

int main() {
    float x1, x2, x3, Te;
    int i = 0;

    // User input
    printf("Enter x1 = ");
    scanf("%f", &x1);
    printf("Enter x2 = ");
    scanf("%f", &x2);
    printf("Enter tolerance error, Te = ");
    scanf("%f", &Te);

    // Check if root is bracketed
    if (f(x1) * f(x2) >= 0) {
        printf("Invalid initial guesses. f(x1) and f(x2) must have opposite signs.\n");
        return 1;
    }

    // Header
    printf("-------------------------------------------------------------------------------\n");
    printf("i\t x1\t\t x2\t\t x3\t\t f(x1)\t\t f(x2)\t\t f(x3)\n");
    printf("-------------------------------------------------------------------------------\n");

    do {
        x3 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        printf("%d\t%f\t%f\t%f\t%f\t%f\t%f\n", i, x1, x2, x3, f(x1), f(x2), f(x3));

        if (f(x1) * f(x3) < 0)
            x2 = x3;
        else
            x1 = x3;

        i++;
    } while (fabs(f(x3)) > Te);

    // Output result
    printf("\nRoot is x = %f\n", x3);
    printf("f(x) = %f\n", f(x3));

    return 0;
}
