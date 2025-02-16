#include <stdio.h>

/* Funciones y parametros/ */

int a, b, c, d;                       /* Variables globales. */

void function1(int, int *, int *);    /* Prototipos de funciones. */
int function2(int *, int);

void main(void)
{
    int a;
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    printf("\n%d %d %d", a, b, c, d);
    a = function2 (&a, c);
    printf("\n%d %d %d", a, b, c, d);
}

void function1(int r, int *b, int *c)
{
    int d;
    a = *c;
    d = a + 3 + *b;
    if (r)
    {
        *b = *b + 2;
        *c = *c + 3;
        printf("\n%d %d %d %d", a, *b, *c, d);
    }
    else
    {
        *b = *b + 2;
        *c = *c + 3;
        printf("\n%d %d %d %d", a, *b, *c, d);
    }
}
    int function2(int *d, int c)
    {
        int b;
        a = 1;
        b = 7;
        function1(-1, d, &b);
        /* Observa que el parametro d que enviamos a funtion1 es por referencia es equivalente escribir &*d a escribir solamente d. */

        printf("\n%d %d %d %d", a, b, c, *d);
        c += 3;
        (*d) += 2;
        printf("\n%d %d %d %d", a, b, c, *d);
        return (c);
    }

