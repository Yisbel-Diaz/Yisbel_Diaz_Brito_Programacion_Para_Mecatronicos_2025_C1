#include <stdio.h>


int main(char *cad, int opcion)
{
    for(int i = 0; cad[i] != '\0'; i++)
    {
        if(opcion == 1 && cad[i] >= 'a' && cad[i] <= 'z') cad[i] -= 32;
        else if
            (opcion == 2 && cad[i] >= 'A' && cad[i] <= 'Z') cad[i] += 32;
        else if
            (opcion == 3) cad[i] ^= 32;
    }
    int main()
    {
        char cad[100];
        int opcion;

        printf("Ingrese texto: ");
        fgets(cad, sizeof(cad), stdin);

        printf("1.MATUSCULAS 2.minusculas 3.Alternar\nOpcion:");
        scanf("%d", &opcion);

        conversion(cad, opcion);
        printf("Texto final: %s\n", cad);


        printf("Gracias por usar mi programa.\n");
        return 0;

    }
}


