#include <stdio.h>

/* Cuenta caracteres. */

int cuenta(char);

void main(void)
{
    int res;
    char car;
    printf("\nIngrese e caracter que se va a buscar en el archivo: ");
    car = getchar();
    res = cuenta(car);
    if (res != -1)
        printf("\n\nEl caracter %c se encuentra en el archivo %d veces", car, res);
    else
        printf("No se puede abrir el archivo");
}

int cuenta(char car)
{
    int res, con = 0;
    char p;
    FILE *ar;
    if ((ar = fopen("arc.txt", "r")) != NULL)

    {
        while (!feof(ar))
        {
            p = getc(ar);
            if (p == car)
                con++;
        }
        fclose(ar);
        res = con;
    }
    else
        res = -1;
    return (res);
}
