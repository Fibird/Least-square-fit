#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Weight fuction
double omega(double x)
{
    return x;
}

int main()
{
    double P = 1.0;
    double alpha = 0.0;
    double beta = 0.0;
    double a = 0.0;       // Coefficients of x

    int i = 0, j = 0;
    int n = 0;          // Number of iterations
    double t1 = 0.0, t2 = 0.0, t3 = 0.0;  //temporary variable
    double prev_P = 0.0;

    double *x, *y;      // Values of x & values of y

    printf("Please enter the number of data: ");
    scanf("%d", &n);

    // Allocates memory to array x and array y
    x = (double*) malloc(n * sizeof(double));
    y = (double*) malloc(n * sizeof(double));

    printf("Please enter values of x:\n");
    // Inputs the data given
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
    }
    printf("Please enter values of y:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &y[i]);
    }

    prev_P = P;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            t1 += omega(x[j]) * x[j] * P * P;
            t2 += omega(x[j]) * P * P;
        }
        alpha = t1 / t2;
        if (i != 0)
        {
            for (j = 0; j < n; j++)
            {
                t3 += omega(x[j]) * prev_P * prev_P;
            }
            beta = t2 / t3;
        }
        prev_P = P;
        // Computes the value of P,
        // and P is a orthogonal family of function
        P = (x[i] - alpha) * P - beta * prev_P;
        for (j = 0; j < n; j++)
        {
            t1 += omega(x[j]) * P * P;
            t2 += omega(x[j]) * y[j] * P;
        }
        // Computes the coefficients
        a = t2 / t1;
        printf("%lf ", a);
    }

    return 0;
}
