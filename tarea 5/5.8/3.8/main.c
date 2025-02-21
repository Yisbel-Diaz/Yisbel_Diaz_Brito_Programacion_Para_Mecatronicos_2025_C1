#include <stdio.h>
#include <math.h>

#define TAM 100

/* Primos. E programa almacena en un arreglo unidimensional los primeros 100 numeros primos. */

void Imprime(int Primos[], int T);              /* Prototipos de de funciones */
void Primo(int, int *);

void main(void)
{
    int P[TAM] = {1, 2};
    int FLA, J = 2, PRI = 3;
    while (J < TAM )
    {
        FLA = 1;
        Primo(PRI, &FLA);                   /* se llama a la funcion que determina si PRI es primo */
        if (FLA)                              /* Si FLA es 1, entonces PRI es primo */
        {
            P[J] = PRI;
            J++;
        }
        PRI += 2;
    }
    Imprime(P, TAM);

    return 0;
}

void Primo(int A, int *B)
/* Esta funcion determina si A es primo, cuto caso el valor de *B no se altera */
{
    int DI = 3;
    while (*B && (DI < (A / 2)))
    {
        if ((A % DI) == 0)
            *B = 0;
        DI += 2;
    }
}

void Imprime(int Primos[], int T)
/* Esta funcion imprime el arreglo unidimensional de numeros primos. */
{
    int I;
    for (I=0; I<T; I++)
        printf("\Primos[%d]: %d", I, Primos[I]);
}
