#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 2
#define L 0.0
#define R 60.0
#define h 1
//0 5 10 15 20 25 30 35 40 45 50 55
//0 1.27 2.16 2.86 3.44 3.87 4.15 4.37 4.51 4.58 4.62 4.64
// Weight fuction
double omega(double x)
{
    return 1.0;
}

// Use Legendre polynomial as family of orthogonal function
double legendre(int n, double x)
{
    if(n == 0)
    {
        return 1;
    }
    else if(n == 1)
    {
        return x;
    }
    else
    {
        return ((2 * n) * x * legendre(n - 1, x) - (n - 1) * legendre(n-2, x)) / n;
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
    //double t1 = 0.0, t2 = 0.0, t3 = 0.0;  //temporary variable
    //double prev_P = 0.0;

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
        denominator = 0.0;  // Must be clear 0
        numerator = 0.0;    // Must be clear 0
        for (j = 0; j < m; j++)
        {
            P = legendre(i, x[j]);
            numerator += omega(x[j]) * y[j] * P;
            denominator += omega(x[j]) * P * P;
        }
        a[i] = numerator / denominator;
        printf("%lf ", a[i]);
    }

    for (temp = L; temp <= R; temp += h)
    {
        S = 0.0;        // Must be clear 0
        for (j = 0; j < N; j++)
        {
            S += a[j] * legendre(j, temp);
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
