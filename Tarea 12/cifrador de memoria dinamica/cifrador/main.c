#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_INICIAL 100

/* CIfrador*/

int main() //32-126
{
    char *frase;
    int key, i, salto = 0;
    int capacidad = TAM_INICIAL;

    frase = (char *)malloc(capacidad * sizeof(char));
    if (frase == NULL)
    {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    while (1)
    {
        system("cls");
        printf("Ingresa la frase a cifrar: ");

        if(fgets(frase, capacidad, stdin) == NULL)
        {
          printf("Error al leer la frase.\n");
          break;

        }

        frase[strcspn(frase, "\n")] = 0;

         do
        {
            printf("Ingresa la clave (1-10): ");
            scanf("%d", &key);
            while (getchar() != '\n');
        }
        while (key < 1 || key > 10);

        printf("\n\n-------------------------------\nFrase Cifrada:\n");

        for (i = 0; i < strlen(frase); i++, salto = 0)
        {
            if (frase[i] > 126 - key)
            {
                salto = 95;
            }
            printf("%c", frase[i] + key - salto);
        }

        printf("\n\n");
        system("pause");
    }

    free(frase);
    return 0;
}



