#include <stdio.h>
#include <stdlib.h>

int datos();
void fibboRec(int restante, long long int anterior, long long int actual);

int main()
{
    int num = datos();

    if (num <= 0)
    {
        printf("Por favor, ingrese un numero positivo.\n");
        return 0;

    }

    if(num == 1)
    {
        printf("0");
    }
    else
    {
        printf("0 1 ");
        fibboRec(num - 2, 0, 1);
    }

    return 0;
}

int datos()
{
    int num;
    printf("Introduce cuantos numeros de Fibonacci quieres mostrar: ");
    scanf("%d", &num);
    return num;
}
void fibboRec(int restante, long long int anterior, long long int actual)
{
    if(restante == 0)
        return;

    long long int siguiente = anterior + actual;
    printf("%lld ", siguiente);
    fibboRec(restante - 1, actual, siguiente);
}
