#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

//Ejecutado con 8 hilos

int main(void)
{
    int i, id, suma = 0;

#pragma omp parallel private(id) reduction(+ \
                                           : suma)
    {
        id = omp_get_thread_num();
#pragma omp for
        for (i = 0; i < 5; i++)
            suma = suma + 1;
        printf("Thread %d, suma %d\n", id, suma);
#pragma omp for
        for (i = 0; i < 5; i++)
            suma = suma + 1;
        printf("Thread %d, suma %d\n", id, suma);
    }
    printf("Valor final suma %d\n", suma);
    return 0;
}