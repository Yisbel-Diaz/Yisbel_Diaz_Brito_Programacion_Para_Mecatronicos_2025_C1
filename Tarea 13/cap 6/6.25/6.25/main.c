#include <stdio.h>
#include <stdbool.h>

int R[][2] = {
    {1, 1}, {2, 2}, {3, 3},
    {1, 2}, {2, 1},
    {2, 3}, {3, 2}
};
int n = 7; //numeros pares

//Elementos del conjunto A
int A[] = {1, 2, 3};
int m = 3; //numero de elementos

bool contienePar(int x, int y)
{
    for (int i = 0; i < n; i++)
    {
        if (R[i][0] == x && R[i][1] == y)
            return true;
    }
    return false;
}

int main()
{
    bool reflexiva = true;
    bool irreflexiva = true;
    bool simetrica = true;
    bool asimetrica = true;
    bool antisimetrica = true;
    bool transitiva = true;

    //reflexiva e irreflexiva
    for (int i = 0; i < m; i++)
    {
        if (!contienePar(A[i], A[i]))
            reflexiva = false;
        else
            irreflexiva = false;
    }

    //simetrica, asimetrica, antisimetrica
    for (int i = 0; i < n; i++)
    {
        int a = R[i][0];
        int b = R[i][1];
        if (a != b && contienePar(b, a))
        {
            antisimetrica = false;
            asimetrica = false;
        }
        if (!contienePar(b, a))
            simetrica = false;
        if (contienePar(b, a))
            asimetrica = false;
    }

    //transitiva
    for (int i = 0; i < n; i++)
    {
        int a = R[i][0];
        int b = R[i][1];
        for (int j = 0; j < n; j++)
        {
            if (R[j][0] == b)
            {
                int c = R[j][1];
                if (!contienePar(a, c))
                {
                    transitiva = false;
                    goto finTransitiva;
                }
            }
        }
    }
    finTransitiva:

        //Resultados
        printf("Propedades de la relacion:\n");
        printf("Reflexiva: %s\n", reflexiva ? "Si" : "No");
        printf("Irreflexiva: %s\n", irreflexiva ? "Si" : "No");
        printf("Asimetrica: %s\n", asimetrica ? "Si" : "No");
        printf("Antisimetrica: %s\n", antisimetrica ? "Si" : "No");
        printf("Transitiva: %s\n", transitiva ? "Si" : "No");

        return 0;
}
