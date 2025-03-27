#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "c:\\Users\\Yisbel\\oneDrive\\Documentos\\Tareas\\Tarea 10\\Tarea 10\\telefono.bin"

typedef struct
{
    int id;
    char marca[50];
    char modelo[50];
    float precio;
}
telefono;

void agregarTelefonos(telefono **telefonos, int *cantidad)
{
    int nuevaCantidad;
    printf("Ingrese la cantidad de telefonos: ");
    scanf("%d", &nuevaCantidad);
    fflush(stdin);

    if (*telefonos == NULL)
    {
        *telefonos = (telefono *)malloc(nuevaCantidad * sizeof(telefono));
    }
    else
    {
        *telefonos = (telefono *)realloc(*telefonos, (*cantidad + nuevaCantidad) * sizeof(telefono));
    }

    if (*telefonos == NULL)
    {
        printf("Error de asignacion de memoria.\n");
        exit(1);
    }

    for (int i = *cantidad; i < (*cantidad + nuevaCantidad); i++)
    {
        printf("ID: ");
        scanf("%d", &((*telefonos)[i].id));
        fflush(stdin);

        printf("Marca: ");
        scanf("%49s", (*telefonos)[i].marca);
        fflush(stdin);

        printf("Modelo: ");
        scanf("%49s", (*telefonos)[i].modelo);
        fflush(stdin);

        printf("Precio (Usar punto decimal): ");
        scanf("%f", &((*telefonos)[i].precio));
        fflush(stdin);

        printf("---Telefono %d ingresado correctamente---\n", i + 1);
        }
*cantidad += nuevaCantidad;
printf("\nSe han agregado %d telefonos. Total de telefonos en memoria: %d\n", nuevaCantidad, *cantidad);
}

void guardarEnDisco(telefono *telefonos, int cantidad)
{
    FILE *archivo = fopen(FILE_NAME, "wb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }
    fwrite(telefonos, sizeof(telefono), cantidad, archivo);
    fclose(archivo);
    printf("\nSe han guardado %d telefonos en el archivo '%s'.\n", cantidad, FILE_NAME);
}

void leerDeDisco()
{
    FILE *archivo = fopen(FILE_NAME, "rb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }
    telefono tel;
    int contador = 0;

    printf("\n---Listado de telefonos en disco---\n");
    while (fread(&tel, sizeof(telefono), 1, archivo))
    {
    contador++;
    printf("\nTelefono %d:\n", contador);
    printf("ID: %d\n", tel.id);
    printf("Marca: %s\n", tel.marca);
    printf("modelo: %s\n", tel.modelo);
    printf("Precio: %.2f\n", tel.precio);
    }

    if (contador == 0)
    {
        printf("No hay telefonos almacenados en disco.\n");
    }
    else
    {
        printf("\nTotal de telefonos en disco: %d\n", contador);
    }
    fclose(archivo);
}

void listarTelefonos(telefono *telefonos, int cantidad)
{
    printf("\n---Listado de telefonos en memoria---\n");
    if (cantidad == 0)
    {
        printf("No hay telefonos en memoria.\n");
        return;
    }

    for (int i = 0; i < cantidad; i++)
    {
    printf("\nTelefono %d:\n", i + 1);
    printf("ID: %d\n", telefonos[i].id);
    printf("Marca: %s:\n", telefonos[i].marca);
    printf("modelo: %s:\n", telefonos[i].modelo);
    printf("Precio: %.2f:\n", telefonos[i].precio);
    }
    /*for (int i = 0; i < cantidad; i++)*/
    printf("\nTotal de telefonos en memoria: %d\n", cantidad);
}

int main()
{
    telefono *telefonos = NULL;
    int cantidad = 0, opcion;

    do
    {
        printf("\n===Menu Principal===\n");
        printf("1. Agregar telefonos\n");
        printf("2. Guardar en disco\n");
        printf("3. Leer de disco\n");
        printf("4. Listar telefonos en memoria\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion)
        {
        case 1:
            agregarTelefonos(&telefonos, &cantidad);
            break;
        case 2:
            if (cantidad > 0) guardarEnDisco(telefonos, cantidad);
            else printf("No hay telefonos para guardar.\n");
            break;
        case 3:
            leerDeDisco();
            break;
        case 4:
            if (cantidad > 0) listarTelefonos(telefonos, cantidad);
            else printf("No hay telefonos en memoria.\n");
            break;
        case 5:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion invalida.\n");
        }
    }while (opcion != 5);

    free(telefonos);
    return 0;
}
