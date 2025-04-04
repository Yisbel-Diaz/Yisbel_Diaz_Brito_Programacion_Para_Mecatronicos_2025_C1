/* PROGRAMA DE LOTERIA */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/* COnstantes de configuracion*/
#define MAX_NOMBRE 50    /* longuitud maxima para nombres */
#define MAX_NUMEROS 100  /* Rango de numeros (0-99)*/
#define NUM_PREMIOS 3    /* CAntidad de premios (ORO, PLATA, BRONCE)*/


/* Tipo enumerado para los premios*/
typedef enum { ORO, PLATA, BRONCE } TipoPremio;
/* Estructura para almacenar informacion de clientes. */

typedef struct
{
    int id;
    char nombre[MAX_NOMBRE];
    int numero;
}

cliente;

/* Estructura para estadisticas de numeros premiados*/
typedef struct
{
    int numero;
    int frecuencia;
    int premio[NUM_PREMIOS]; /* Indices: 0=ORO, 1=Plata, 2=BRONCE */
}
NumeroStats;

/* Variables Globales =======*/

cliente*clientes = NULL;       /* Array dinamico de clientes */
int numClientes = 0;           /* contador actual de clientes */
int capacidadClientes = 0;     /* capacidad actual del array */

int numerosPremiados[NUM_PREMIOS] = {-1, -1, -1}; /* Ultimos premiados*/
const char *nombresPremios[NUM_PREMIOS] = {"ORO", "PLATA", "BRONCE"};

NumeroStats *stats = NULL;      /* Array dinamico de estadisticas */
int numStats = 0;               /* Contador actual de stats */
int capacidadStats = 0;         /* Capacidad actual del array */

/* Prototipos de funciones ===== */

void limpiarBuffer();           /* Limpador del buffer de entrada */

/* Valida que un numero este en el rango permitido */
bool validarNumero(int numero);

/* Verifica si un numero no esta repetido en los premios*/
bool esNumeroUnico(int numero, int excluirPos);

/* Registra un nuevo cliente en el sistema */
void agregarCliente();

/* Guarda los numeros premiados en archivo con marca de tiempo*/
void guardarPremiosEnDisco();

/* Actualiza las estadisticas con los ultimos numeros premiados */
void actualizarEstadisticas();

/* Genera un numero aleatorio unico para un premio */

void generarNumeroPremiado(int pos);

/* Realiza el sorteo de numeros premiados */
void tirarNumeros();

/* muestra los clientes ganadores del ultimo sorteo */
void mostrarGanadores();

/* Funcion de comparacion para qsort*/
int compararStats(const void *a, const void *b);

/* muestra estadisticas de todos los numeros sorteados */
void mostrarNumerosSalidos();

/* Carga datos historicos desde archivo al iniciar el programa */
void cargarDatos();

/* Libera toda la memoria dinamica asignada */
void liberarMemoria();

/* MUestra el menu principar y gestiona la interaccion */
void mostrarMenu();

/* Implementacion de funciones ========== */

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

bool validarNumero(int numero)
{
    return numero >= 0 && numero < MAX_NUMEROS;
}

bool esNumeroUnico(int numero, int excluiirPos)
{
    for (int i = 0; i < NUM_PREMIOS; i++)
    {
        if (i != excluiirPos && numerosPremiados[i] == numero)
        {
            return false;
        }
    }
    return true;
}

void agregarCliente()
{
    /* Redimensionar array si esta lleno */
    if(numClientes >= capacidadClientes)
    {
        capacidadClientes = capacidadClientes == 0 ? 1 : capacidadClientes *2;
        clientes = realloc(clientes, capacidadClientes * sizeof(clientes));
        if (clientes == NULL)
        {
            printf("Error critico: Fallo de memoria\n");
            exit(EXIT_FAILURE);
        }
    }

    cliente nuevoCliente;
    nuevoCliente.id = numClientes + 1;

    /* Solicitar Nombre */
    printf("\nIngrese nombre del cliente: ");
    fgets(nuevoCliente.nombre, MAX_NOMBRE, stdin);
    nuevoCliente.nombre[strcspn(nuevoCliente.nombre, "\n")] = '\0';

    /* Validar numero */
    do
    {
        printf("Ingrese numero (0-%d): ", MAX_NUMEROS-1);
        scanf("%d", &nuevoCliente.numero);
        limpiarBuffer();

        if(!validarNumero(nuevoCliente.numero))
        {
            printf("Error: Debe ser entre 0 y %d\n", MAX_NUMEROS-1);
        }
    }
    while (!validarNumero(nuevoCliente.numero));

    /* Agregar cliente */
    clientes[numClientes++] = nuevoCliente;
    printf("cliente %d (%s) registrado con el numero %d\n", nuevoCliente.id, nuevoCliente.nombre, nuevoCliente.numero);
}

void guardarPremiosEnDisco()
{
    FILE *archivo = fopen("premios.txt", "a");
    if (archivo == NULL)

{
    printf("Error: no se pudo abrir el archivo\n");
    return;
}

/* obtener fecha/hora actual */
time_t ahora = time(NULL);
struct tm *tiempo = localtime(&ahora);

/* Formatear y escribir linea */
fprintf(archivo, "[%02d/%02d/%04d %02d:%02d] ORO: %d, PLATA: %d, BRONCE: %d\n",
        tiempo->tm_mday, tiempo->tm_mon + 1, tiempo->tm_year + 1900, tiempo->tm_hour, tiempo->tm_min,
        numerosPremiados[ORO], numerosPremiados[PLATA], numerosPremiados[BRONCE]);

        fclose(archivo);
}

void actualizarEstadisticas()
{
    for (int i = 0; i < NUM_PREMIOS; i++)
    {
        int numero = numerosPremiados[i];
        bool encontrado = false;

        /* Buscar numero en estadisticas existentes*/
        for (int j = 0; j < numStats; j++)
        {
            if (stats[j].numero == numero)
            {
                stats[j].frecuencia++;
                stats[j].premio[i]++;
                encontrado = true;
                break;
            }
        }

        /* si no existe, agrega nueva entrada */
        if (!encontrado)
        {
            if (numStats >= capacidadStats)
            {
                capacidadStats = capacidadStats == 0 ? 1 : capacidadStats *2;
                stats = realloc(stats, capacidadStats * sizeof(NumeroStats));
                if (stats == NULL)
                {
                    printf("Error critico: Fallo de memoria\n");
                    exit(EXIT_FAILURE);
                }
            }

            /* Inicializar nueva estadisticas */
            stats[numStats].numero = numero;
            stats[numStats].frecuencia = 1;
            memset(stats[numStats].premio, 0, sizeof(stats[numStats].premio));
            stats[numStats].premio[i] = 1;
            numStats++;
        }
    }
}

void generarNumeroPremiado(int pos)
{
    int numero;
    do
    {
        numero = rand() % MAX_NUMEROS;
    }
    while (!esNumeroUnico(numero, pos));

    numerosPremiados[pos] = numero;
}

void tirarNumeros()
{
    /* Generar numeros unicos para cada premio*/
    for (int i = 0; i < NUM_PREMIOS; i++)
    {
        generarNumeroPremiado(i);
    }

    /* mostrara resulados*/
    printf("\n========== RESULTADO DEL SORTEO ==========\n");
    for (int i = 0; i < NUM_PREMIOS; i++)
    {
        printf("%s: %d\n", nombresPremios[i], numerosPremiados[i]);
    }

    guardarPremiosEnDisco();
    actualizarEstadisticas();
}

void mostrarGanadores()
{
    if(numerosPremiados[ORO] == -1)
    {
        printf("\Informacion: No se ha relaizado ningun sorteo\n");
        return;
    }

    printf("\n=== LISTA DE GANADORES ===\n");
    printf("Numeros premiados: ORO=%d, PLATA=%d, BRONCE=%d\n",
           numerosPremiados[ORO], numerosPremiados[PLATA], numerosPremiados[BRONCE]);

           bool hayGanadores = false;

           /* Buscar coincidencias en clientes registrados */
           for (int i = 0; i < numClientes; i++)
           {
               TipoPremio premio;
               bool ganador = false;

               if (clientes[i].numero == numerosPremiados[ORO])
               {
                   premio = ORO;
                   ganador = true;
               }
               else if (clientes[i].numero == numerosPremiados[PLATA])
               {
                   premio = PLATA;
                   ganador = true;
               }
               else if (clientes[i].numero == numerosPremiados[BRONCE])
               {
                   premio = BRONCE;
                   ganador = true;
               }

               if (ganador)
               {
                   hayGanadores = true;
                   printf("GANADOR: %s (ID:%d) - Premio %s con el numero %d\n",
                          clientes[i].nombre, clientes[i].id, nombresPremios[premio], clientes[i].numero);
               }
           }

           if (!hayGanadores)
           {
               printf("No se registraron ganadores en este sorteo\n");
           }
}

int compararStats(const void *a, const void *b)
{
    const NumeroStats *statA = a;
    const NumeroStats *statB = b;
    return statB->frecuencia - statA->frecuencia;
}

void mostrarNumerosSalidos()
{
    if (numStats == 0)
    {
        printf("\nInformacion: no hay datos estadisticos disponibles\n");
        return;
    }

    /* Ordenar por frecuencia (mayor a menor) */
    qsort(stats, numStats, sizeof(NumeroStats), compararStats);

    /* Mostrar tabla formateada */
    printf("\n=== ESTADISTICAS HISTORICAS ===\n");
    printf("%-6s | %-10s | %-3s | %-5s | %-6s\n",
           "Numero", "Frecuencia", "ORO", "PLATA", "BRONCE");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < numStats; i++)
    {
    printf("%-6d | %-10d | %-3d | %-5d | %-6d\n",
           stats[i].numero, stats[i].frecuencia,
           stats[i].premio[ORO], stats[i].premio[PLATA], stats[i].premio[BRONCE]);
    }
}

void cargarDatos()
{
    FILE *archivo = fopen("premios.txt", "r");
    if (archivo == NULL)
        return;

    char linea[100];
    int oro, plata, bronce;

    /* procesar cada linea del archivo */
    while (fgets(linea, sizeof(linea), archivo))
    {
        if (sscanf(linea, "ORO: %d, PLATA: %d, BRONCE: %d", &oro, &plata, &bronce) == 3)
        {
            numerosPremiados[ORO] = oro;
            numerosPremiados[PLATA] = plata;
            numerosPremiados[BRONCE] = bronce;
            actualizarEstadisticas();
        }
    }

    fclose(archivo);
}

void liberarMemoria()
{
     free(clientes);
     free(stats);
}

void mostrarMenu()
{
    int opcion;
    do
    {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Registrar nuevo cliente\n");
        printf("2. Mostrar estadisticas\n");
        printf("3. Realizar sorteo\n");
        printf("4. Mostrar ganadores\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1)
        {
            printf("Error: Entrada invalida\n");
            limpiarBuffer();
            continue;
        }
        limpiarBuffer();

        switch (opcion)
        {
            case 1: agregarCliente();
            break;
            case 2: mostrarNumerosSalidos();
            break;
            case 3: tirarNumeros();
            break;
            case 4: mostrarGanadores();
            break;
            case 5: printf("Saliendo del sistema...\n");
            break;
            default: printf("Error: opcion no valida\n");
        }
    }
    while (opcion != 5);
}

int main()
{
    srand(time(NULL));    /* Inicializar generador aleatorio*/
    cargarDatos();        /* Cargar historial previo */
    mostrarMenu();        /* Ejecutar interfaz */
    liberarMemoria();     /* Limpiar recursos */
    return EXIT_SUCCESS;
}
