#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define M 1000
#define INT_MAX 999

//Ejecutado con 8 hilos

int main(void)
{
    int A[M];
    int i;
    int result= INT_MAX;

    //Preguntar a Arturo pq al paralelizar este bucle tarda más que si lo dejas sin paralelizar

    for (i = 0; i < M; i++)
    {
        A[i] = i;
    }

        /* M ́ınimo de valores en un array */
#pragma omp parallel for shared(A) reduction(min : result)
    for (i = 0; i < 1000; i++)
    {
        if (A[i] < result)
            result = A[i];
    }
    printf("Suma %d\n", result);
    return 0;
}