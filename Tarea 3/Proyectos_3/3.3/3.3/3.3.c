#include <stdio.h>

/* Suma pagos.
El programa, al recibir como datos un conjunto de pagos realizados en el ultimo mes, obtiene la suma de los mismos.

PAG y SPA: variables de tipo real. */

void main(void)
{
    float PAG, SPA;
    SPA = 0;
    printf("Ingrese el primer pago:\t");
    scanf("%f", &PAG);
    while (PAG !=0)
        /* Observa que la condicion es verdadera mientras el pago es diferente de cero. */
    {
        SPA = SPA + PAG;
        printf("Ingrese el siguiente pago (0 para terminar):\t ");
        scanf("%f", &PAG);
        /* Observa que la posicion que modifica la condicion e una lectura. */
    }
    printf("nEl total de pagos del mes es: %.2f", SPA);

    return 0;
}

