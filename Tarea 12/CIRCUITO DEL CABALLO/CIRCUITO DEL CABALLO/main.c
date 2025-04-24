#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int x = 1; //El caballo nicia en la casilla superior
int y = 1; //Izquierda
const int TAMANO = 5; //cambiar esta variable para resolver el problema del recorrido del caballo en un tablero de N * N
int contador = 1; // Esta variable lleva la cuenta de las casillas recorridas
int ciclos = 0; //Esta variable cuenta los ciclos que se intentan antes de terminar que ya no haya lugares a los cuales ir
int intentos_fallidos = 0; // esta variabe cuenta cuantos ciclos se intentan antes de obtener el que pidio el usuario

//prototipo de funcio imprime
void imprime(int a[TAMANO + 1][TAMANO + 1]);
int main()
{
    //abre main
    srand(time(NULL));
    int Arreglo[TAMANO + 1][TAMANO + 1];

    Arreglo[y][x] = 1;
    int dado1;
    int dado2;
    int casillas_requeridas = 0;

    do
    {
        //Abre while
        printf("\nCantas casillas quiere que recorra por lo menos?");
        printf("\n(Un numeri positivo menor o igual que %d):", TAMANO*TAMANO);
        scanf("%d", &casillas_requeridas);
}

while ((TAMANO*TAMANO < casillas_requeridas) || (0 > casillas_requeridas));

while (contador < casillas_requeridas)
{
    //Abre while
    intentos_fallidos++; //Se incrementa cada que inicia un intento de completar las casillas pedidas por el usuario
    contador = 1; //Dado que ya se ha colocado al caballo en (y,x), se inicia el contador en 1
    int ciclos = 0; //se inicia con 0 ciclos o lanzamientos de dados infructuosos
    //cada vez que se aborta un intento han de limpiarse las casillas, con el siguinete par de ciclos se establecen a 0 nuevamente.
    int s;
    int t;
    for (s = 0; s <= TAMANO; s++)
    {
        for(t = 0; t <= TAMANO; t++)
            Arreglo[s][t] = 0;
    }

    //se ha de colocar el caballo en la esquina superior izquierda cada vez desde luego se puede poner en cualquier parte
    x = 1;
    y = 1;
    Arreglo[y][x] = 1;

    while (100 != ciclos)
    {
        ciclos++;
        dado1 = 1 + rand() % TAMANO;
        dado2 = 1 + rand() % TAMANO;

        if(2 == fabs(x - dado1))
        {
            if(1 == fabs(y - dado2))
                if(0 == Arreglo[dado1][dado2])
            {
                Arreglo[dado1][dado2] = ++contador;
                x = dado1;
                y = dado2;
                ciclos = 0;
            }
        }

        if(fabs(fabs(x) - fabs(dado1))==1)
        {
            if(fabs(fabs(y)-fabs(dado2))==2)
                if(0 == Arreglo[dado1][dado2])
            {
                Arreglo[dado1][dado2] = ++contador;
                x = dado1;
                y = dado2;
                ciclos = 0;
            }
        }
    }

}

printf("\nLISTO!\n");
printf("\nSe recorrieron %d casillas\n", contador);
printf("\nSe intentaron %d circuitos antes de obtener", intentos_fallidos);
printf("el requerido.\n");

imprime(Arreglo);

}

void imprime(int matriz[TAMANO + 1][TAMANO + 1])

{
    int i;
    int j;
    printf("\n\nEste es el tablero:\n\n");
    for (i = 1; i <= TAMANO; i++)
    {
        for(j = 1; j <= TAMANO; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n\n\n");
    }

    printf("\n\n\n");

}
