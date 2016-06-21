#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double P = 1;
    double alpha = 0.0;
    double beta = 0.0;
    double a = 0.0;       // Coefficients of x

    int i = 0;
    int n = 0;      // Number of iterations

    double *x, *y;      // Values of x & values of y

    printf("Please enter the number of coefficient: ");
    scanf("%d", &n);

    // Allocates memory to array x and array y
    x = (double*) malloc(n * sizeof(double));
    y = (double*) malloc(n * sizeof(double));

    printf("Please enter values of x:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
    }
    printf("Please enter values of y:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &y[i]);
    }

    double omega = 0.0;     // Weight function

    for (i = 0; i < n; i++)
    {
        printf("%lf", x[i]);
    }

    return 0;
}
