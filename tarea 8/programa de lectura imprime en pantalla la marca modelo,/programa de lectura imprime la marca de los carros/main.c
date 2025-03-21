#include <stdio.h>
#include <stdlib.h>
#define ARCHIVO "vehiculos.txt"

void ingresarVehiculo();
void mostrarVehiculos();

int main()
{
    int opcion;
    do
    {
        printf("\n1. Ingresar Vehiculo\n");
        printf("2. mostrar Vehiculo\n");
        printf("3. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);
        getchar();

        if (opcion == 1)
        {
            ingresarVehiculo();
        }
        else if (opcion == 2)
        {
            mostrarVehiculos();
        }
        else if (opcion != 3)
        {
            printf("opcion invalida.\n");
        }
    }
    while (opcion != 3);

    printf("Salida del programa...\n");
    return 0;
}

void ingresarVehiculo()
{
    FILE *archivo = fopen(ARCHIVO, "a");
    if (archivo == NULL)
    {
        printf("Eror al abrir el archivo.\n");
        return;
    }

    char marca[50], modelo[50];
    float consumo;

    printf("Ingrese marca: ");
    scanf("%s", marca);
    printf("Ingrese modelo: ");
    scanf("%s", modelo);
    printf("Ingrese consumo (galones por km): ");
    scanf("%s", &consumo);

    fprintf(archivo, "%s %s %.2f\n", marca, modelo, consumo);
    fclose(archivo);

    printf("vehiculo guardado.\n");
}

void mostrarVehiculos()
{
    FILE *archivo = fopen(ARCHIVO, "r");
    if (archivo == NULL)
    {
        printf("No hay datos guardados.\n");
        return;
    }

    float precio_galon;
    printf("Ingrese el precio del combustible por galon: ");
    scanf("%f", &precio_galon);

    char marca[50], modelo[50];
    float consumo;

    printf("\n---Lista de Vehiculos---\n");
    while (fscanf(archivo, "%s %s %f", marca, modelo, &consumo) == 3)
    {
        float costo_total = consumo * precio_galon;
        printf("Marca: %s\n", marca);
        printf("Modelo: %s\n", modelo);
        printf("Consumo: %.2f galones/km\n", consumo);
        printf("costo por galon: %.2f\n", precio_galon);
        printf("Costo total por km: %.2f\n\n", costo_total);
    }

    fclose(archivo);
}
