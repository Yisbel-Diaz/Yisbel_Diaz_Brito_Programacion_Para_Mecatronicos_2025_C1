#include <stdio.h>
#define RESTA 2
#define SUMA 1
//declaraciones de fuciones
void EntradaNumeros(float *n1, float *n2);
float suma(float n1, float n2);
int main()
{
    // *operador de indireccion
    // &operador de direccion
    int *ptr;
    //ambito de variable
    float numero1 = 0.0;
    float numero2 = 0.0;
    float result = 0.0;
    int menu = 0;


    ptr = &menu;

    *ptr = 127;
    printf("\nValor apuntado por ptr &i",*ptr);
    printf("\nValor de menu:%i",menu);

    printf("\nDireccion de numero1:%p",&numero1);
    printf("\nDireccion de numero2:%p",&numero2);
    printf("\nDireccion de result: %p",&result);

    do
    {
        printf("\n0-Salir\n1-Suma\n2-Resta\n");
        scanf("%i",&menu);

        //verifica si es suma
        if(menu == SUMA)
        {
            EntradaNumeros(&numero1,&numero2);
            result = suma(numero1, numero2);
            printf("\nLa suma de %f mas %f es: %f",numero1,numero2,result);
        }

        {
        printf("\nIngrea numero1:");
        scanf("%f", &numero1);
        printf("\nIngrea numero2:");
        scanf("%f", &numero2);
        result = numero1 + numero2;
        printf("\nLa suma de %f mas %f es: %f",numero1,numero2,result);
        }
         //verifica si es resta
         if(menu == RESTA)
         {
        printf("\nIngrea numero1:");
        scanf("%f", &numero1);
        printf("\nIngrea numero2:");
        scanf("%f", &numero2);
        result = numero1 - numero2;
        printf("\nLa resta de %f menos %f es: %f",numero1,numero2,result);

         }
    }
    while(menu != 0);

    printf("\Fin de programa");
    return 0;
}
//vamos a pasar por referencia
void EntradaNumeros(float *n1,float *n2);

{
    printf("\nIngrea numero1:");
    scanf("%f", n1);
    printf("\nIngrea numero2:");
    scanf("%f", n2);
}

//vamos a pasar parametros por valor
float suma(float n1, float n2)
{
    float result = 0.0;
    result = n1 + n2;
    return result;
}
