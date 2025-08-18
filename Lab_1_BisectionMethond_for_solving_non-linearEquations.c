#include <stdio.h>
#include <math.h>

#define f(x) ((x)*(x)*(x) - 4*(x) - 9)

int main() {
    float a, b, c, Te;
    int i = 1;

  
    printf("Enter the initial guesses (a and b): ");
    scanf("%f %f", &a, &b);

    printf("Enter the allowed error (tolerance): ");
    scanf("%f", &Te);

    printf("...................................................................................\n");
    printf("i\t     a\t\t     b\t\t     c\t\t   f(a)\t\t   f(b)\t\t   f(c)\n");
    printf("...................................................................................\n");


    do {
        c = (a + b) / 2.0;  
        printf("%d\t%f\t%f\t%f\t%f\t%f\t%f\n", i, a, b, c, f(a), f(b), f(c));


        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        i++;
    } while (fabs(f(c)) > Te); 


    printf("...................................................................................\n");
    printf("Approximate root = %f\n", c);
    printf("f(c) = %f (should be close to 0)\n", f(c));

    return 0;
}
