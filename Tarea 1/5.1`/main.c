#include <stdio.h>

/* Cuent-numeros.
El programa, al recibir como datos unidimensional de tipo entero y un numero ntero, determina cuantas veces se encunra el numero en el arreglo. */

void main(void)
{
    int I, NUM, CUE = 0;
    int ARRE[100];                        /*Declaracion del arreglo. */
    for (I=0; I<100; I++)
    {
        printf("Ingrese el elemento %d del arreglo: ", I+1);
        scanf("%d", &ARRE[I]);             /* Lectura -asignaicon- del arreglo. */
    }
    printf("\n\Ingrese el numero que se ba a buscra en el arreglo: ");
    scanf("%d", &NUM);
    for (I=0; I<100; I++)
        if (ARRE[I] == NUM)               /* Comparacion del numero con los elementos del arreglo */

        CUE++;
    printf("\n\nEl %d se encuenra %d veces en el arreglo", NUM, CUE);
}
