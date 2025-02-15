#include <stdio.h>
#include <math.h>

#define SUMA 1
#define RESTA 2
#define DIVISION 3
#define MULTIPLICACION 4
#define POTENCIACUADRADA 5
#define RAIZCUADRADA 6
#define SALIR 0
#define ERR_OK 0
#define ERR_DbyZ 1

//Declaraciones de fuciones

void EntradaNumeros(float *n1, float *n2);
void EntradaNumerosUnicos(float *n);
int suma(float n1, float n2, float *pResult);
int resta(float n1, float n2, float *pResult);
int dividir(float n1, float n2, float *pResult);
int multiplicacion(float n1, float n2, float *pResult);
int raizCuadrada(float n, float *pResult);
int potenciaCuadrada(float n, float *pResult);

 //variable global
 float gResult = 0.0;

int main()
{
    // *operador de indireccion
    // &operador de direccion
    //ambito de variable
    float numero1 = 0.0;
    float numero2 = 0.0;
    float result = 0.0;
    int menu = 0;
    int err = 0;

    do
    {
        printf("\n---------CALCULADORA-------------\n");
        printf("\n0-Salir\n1-Suma\n2-Resta\n3-Dividir\n4-Multiplicacion\n5-Potencia al cuadrado\n6-Raiz Cuadrada\n");
        printf("\nSeleccione una opcion: ");
        scanf("%d",&menu);

        switch (menu)
        {
        //verifica si es suma

        case SUMA:
            //parametros por referencia
            EntradaNumeros(&numero1,&numero2);
            //parametros por valor
            err = suma(numero1, numero2,&result);
            printf("\nLa suma de %f + %f es: %f\n", numero1,numero2, result);
         break;

        //verifica si es resta
            case RESTA:
            EntradaNumeros(&numero1,&numero2);
            err = resta(numero1, numero2,&result);
            printf("\nLa resta de %f - %f es: %f\n",numero1,numero2,result);
        break;

        case DIVISION:
            EntradaNumeros(&numero1,&numero2);
            err = dividir(numero1,numero2,&result);
            if(err == ERR_DbyZ)
            {
                printf("\nError: Division por 0 no permitida\n");
            }
            else
            {
                printf("\nLa division de %f / %f es: %f",numero1,numero2,result);
            }
            break;

            case MULTIPLICACION:
            EntradaNumeros(&numero1,&numero2);
            err = multiplicacion(numero1,numero2,&result);
            printf("\nLa multiplicacion de %f * %f es: %f",numero1,numero2,result);
            break;

          case POTENCIACUADRADA:
          EntradaNumerosUnicos(&numero1);
            err = potenciaCuadrada(numero1, &result);
            if(err == ERR_OK)
            {
            printf("\nLa potencia al cuadrado de %f es: %f\n",numero1,result);
            }
            else
                {
                printf("\nError: No se puede calcular la potencia de un numero negativo\n");
                }
            break;

        case RAIZCUADRADA:
        EntradaNumerosUnicos(&numero1);
        err = raizCuadrada(numero1, &result);
        if (err == ERR_OK )
        {
            printf("\nLa raiz cuadrada de %f es %f\n", numero1, result);
        }
        else
        {
            printf("\nError: No se puede calcular la raiz de un numero negativo\n");
        }
        break;

          case SALIR:
        printf("\nFin de programa");
        break;

        default:
        printf("\nOpcion no valida");
        break;

          }
          }

    while(menu != SALIR);
    return 0;
}

//vamos a pasar por referencia
void EntradaNumeros(float *n1, float *n2)
{
    printf("\nIngrese numero1: ");
    scanf("%f", n1);
    printf("\nIngrese numero2: ");
    scanf("%f", n2);
}

void EntradaNumerosUnicos(float *n)
{
    printf("\nIngrese un numero: ");
    scanf("%f", n);
}

//vamos a pasar parametros por valor
int suma(float n1, float n2, float *pResult)
{
   *pResult = n1 + n2;
   return ERR_OK;
}

int resta(float n1, float n2, float *pResult)
{
    *pResult = n1 - n2;
    return ERR_OK;
}

int dividir(float n1, float n2, float *pResult)
{
    if(n2 == 0.0)
    {
        return ERR_DbyZ;
    }
    *pResult = n1 / n2;
    return ERR_OK;
}

int multiplicacion(float n1, float n2, float *pResult)
{
   *pResult = n1 * n2;
   return ERR_OK;
}

int raizCuadrada(float n, float *pResult)
{
    if (n < 0)
    {
        return ERR_DbyZ;
    }
    *pResult = sqrt(n);
    return ERR_OK;
}

int potenciaCuadrada(float n, float *pResult)
{
    *pResult = n * n;
    return ERR_OK;
}

