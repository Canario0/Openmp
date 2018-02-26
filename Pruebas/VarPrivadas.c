#include<stdio.h>
#include<omp.h>

int main (void){
    int i, a =10;
    #if 0
    /* desactiva el compartir variables de serie y pone i a privado*/

    #pragma omp parallel for default(none) private(a)
    for ( i=0; i<5 ; i++){
        a = a + 1;
        printf( "Thread %d, valor %d \n", omp_get_thread_num(), a);
    }//Fin región paralela
    #endif


    #if 0
    /* Ejemplo firstprivate y las private*/

    #pragma omp parallel for default(none) firstprivate( a ) lastprivate( a )
    for ( i=0; i<5 ; i++){
        a = a + 1;
        printf( "Thread %d, valor %d \n", omp_get_thread_num(), a);
    }//Fin región paralela

    #endif

    //Ejemplo propio

     #pragma omp parallel for default(none) reduction(+:a)
    for ( i=0; i<5 ; i++){
        a = a + 1;
        printf( "Thread %d, valor %d \n", omp_get_thread_num(), a);
    }//Fin región paralela
    printf("Valor final: %d\n", a);
}