#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SEED 6834723
#define DIMN 9999
//Prototipo
double infNorm(double[DIMN][DIMN], int);

int main(void)
{
    int i ,j;
    double A[DIMN][DIMN];

    srand48(SEED);

    for (i = 0; i < DIMN; i++)
        for (j = 0; j < DIMN; j++)
        {
            A[i][j] = drand48();
        }

    printf("Sol: %lf\n", infNorm(A, 1024));

    return 0;
}

double infNorm(double A[DIMN][DIMN], int n)
{
    //Existe una mejor solución ??
    int i, j;
    double s, norm = 0;
    #pragma omp parallel shared(A), private(j, s)
    for (i = 0; i < n; i++)
    {
        s = 0;
        for (j = 0; j < n; j++)
            s += fabs(A[i][j]);
        if (s > norm)
            //Restringe el uso de este código a un único hilo a la vez
            #pragma omp critical
            if (s > norm)
                norm = s;
    }
    return norm;
}