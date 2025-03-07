#include <stdio.h>
#include <string.h>

/* Bienes raices.
El programa maneja informacion sobre las propiedades que tiene una empresa de bienes raices de la ciudad de Lima, Peru, tanto para venta como para renta*/

typedef struct
{
    char zona[20];
    char calle[20];
    char colo[20];
}ubicacion;

typedef struct
{
    char clave[5];
    float scu;
    float ste;
    char car[50];
    ubicacion ubi;

    float precio;
    char dispo;
}propiedades;

void lectura(propiedades, int);
void F1(propiedades *, int);
void F2(propiedades *, int);

void main(void)
{
    propiedades PROPIE[100];
    int TAM;
    do
    {
        printf("Ingrese el numero de propiedades:");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);
    lectura(PROPIE, TAM);
    F1(PROPIE, TAM);
    F2(PROPIE, TAM);
}

void lectura(propiedades A[], int T)
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("\n\tIngrese datos de la propiedad %d", I+1);
        printf("\nClave ");

    }
}
