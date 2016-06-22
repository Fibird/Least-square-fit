#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 2     // Approximation times, and it can be changed
#define L -5.0
#define R 5.0
#define h 0.1

// Weight fuction
double omega(double x)
{
    return 1 / sqrt(x * x - 1);
}

// Use Chebyshev polynomial as family of orthogonal function
double Cheby(int n, double x)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return x;
    }
    else
    {
        return (2 * x * Cheby(n - 1, x) - Cheby(n - 2, x));
    }
}

int main()
{
    double P;       // Values of orthogonal function
    double denominator = 0.0;       // Must be initialized!
    double numerator = 0.0;         // Must be initialized!
    double *a;       // Coefficients of function P
    double S = 0.0;     // Fitted values
    FILE* fp = fopen("result.txt", "w+");

    int i = 0, j = 0;
    int m = 0;          // Number of data
    double temp;  // temporary variable

    double *x, *y;      // Values of x & values of y

    a = (double*) malloc(N * sizeof(double));
    printf("Please enter the number of data: ");
    scanf("%d", &m);

    // Allocates memory to array x and array y
    x = (double*) malloc(m * sizeof(double));
    y = (double*) malloc(m * sizeof(double));

    printf("Please enter values of x:\n");
    // Inputs the data given
    for (i = 0; i < m; i++)
    {
        scanf("%lf", &x[i]);
    }
    printf("Please enter values of y:\n");
    for (i = 0; i < m; i++)
    {
        scanf("%lf", &y[i]);
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < m; j++)
        {
            P = Cheby(i, x[j]);
            denominator += omega(x[j]) * y[j] * P;
            numerator += omega(x[j]) * P * P;
        }
        a[i] = numerator / denominator;
    }

    for (temp = L; temp <= R; temp += h)
    {
        for (j = 0; j < N; j++)
        {
            S += a[j] * Cheby(j, temp);
        }
        fprintf(fp, "%lf\t%lf\n", temp, S);
    }

    // Close file stream and free memory
    fclose(fp);
    free(x);
    free(y);
    free(a);

    return 0;
}
