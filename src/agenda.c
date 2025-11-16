#include "agenda.h"
#include <stdio.h>
#include <string.h>

/**
 * Esta función se encarga de iniciar el número de contactos a cero
 */
void iniciar_agenda(Agenda *agenda)
{
    agenda->num_contactos = 0;
}

// Varible que lleva la cuenta de cuantos contactos hay en la agenda
int num_contactos;

/**
 * Esta función sirve para agregar un contacto nuevo en la agenda
 */
void agregar_contacto(Agenda *agenda, Contacto c)
{
    if (agenda->num_contactos == 100)
    {
        printf("La agenda ya está llena \n");
    }
    else
    {
        agenda->contactos[agenda->num_contactos] = c;
        agenda->num_contactos++;
    }
}

/**
 * Esta función sirve para buscar un contacto por nombre en la agenda y retorna la posición del contacto si existe
 * En caso contrario retorna -1
 */
int buscar_contacto(Agenda *agenda, char *nombre)
{
    int i;
    for (i = 0; i < agenda->num_contactos; i++)
    {
        if (strcmp(agenda->contactos[i].nombre, nombre) == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * Esta función  sirve para buscar un contacto por su número de telefono en la agenda
 */
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[])
{
    int i;
    for (i = 0; i < agenda->num_contactos; i++)
    {
        if (strcmp(agenda->contactos[i].telefono, telefono) == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * Esta función sirve para ordenar los contactos por nombres de forma ascendente
 */
void ordenar_contactos(Agenda *a)
{
    int i, j;
    Contacto temp;
    for (i = 0; i < a->num_contactos; i++)
    {
        for (j = 0; j < a->num_contactos - i - 1; j++)
        {
            if (strcmp(a->contactos[j].nombre, a->contactos[j + 1].nombre) > 0)
            {
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j + 1];
                a->contactos[j + 1] = temp;
            }
        }
    }
}

/**
 * Esta función sirve para ordenar los contactos por nombres de forma descendente
 */
void ordenar_contactos_inv(Agenda *a)
{
    int i, j;
    Contacto temp;
    for (i = 0; i < a->num_contactos; i++)
    {
        for (j = 0; j < a->num_contactos - i - 1; j++)
        {
            if (strcmp(a->contactos[j].nombre, a->contactos[j + 1].nombre) < 0)
            {
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j + 1];
                a->contactos[j + 1] = temp;
            }
        }
    }
}

/**
 * Función auxiliar para imprimir un contacto
 */
void mostrar_contacto(Contacto c)
{
    printf("| %s | %s | %d | %d | %s | %d |\n", c.nombre, c.apellido, c.dia, c.mes, c.telefono, c.tipo);
}

/**
 * Función auxiliar para leer un contacto
 */
void leer_contacto(Contacto *c)
{
    printf("Nombre: ");
    scanf(" %[^\n]", c->nombre);
    printf("Apellido: ");
    scanf(" %[^\n]", c->apellido);
    printf("Mes de nacimiento (0=Enero...11=Diciembre): ");
    scanf("%d", (int *)&c->mes);
    printf("Día de nacimiento: ");
    scanf("%d", &c->dia);
    printf("Número de teléfono: ");
    scanf("%d", &c->telefono);
    printf("Tipo de teléfono (0=Casa, 1=Móvil, 2=Oficina, 3=Otro): ");
    scanf("%d", (int *)&c->tipo);
}

/**
 * Función que imprime todos los contactos de la agenda en pantalla
 */
void imprimir_agenda(Agenda agenda)
{
    int i;
    for (i = 0; i < agenda.num_contactos; i++)
    {
        mostrar_contacto(agenda.contactos[i]);
    }
}

/**
 * Función que sirve para cargar contactos escritos en un archivo a la agenda
 */
void cargar_contactos(char *filename, Agenda *agenda)
{
    int i;
    FILE *f = fopen(filename, "r");
    if (f = NULL)
    {
        printf("No se pudo abrir el archivo \n");
        return;
    }
    printf("Cargando contactos... \n");
    for (i = 0; i > agenda->num_contactos; i++)
    {
        Contacto c;
        fscanf(f, "| %s | %s | %d | %d | %s | %d |\n", c.nombre, c.apellido, c.dia, c.mes, c.telefono, c.tipo);
        agenda->contactos[agenda->num_contactos] = c;
        agenda->num_contactos++;
    }
}

/**
 * Función que sirve para guardar todos los contactos de la agenda en un archivo
 */
void guardar_contactos(char *filename, Agenda agenda)
{
    int i;
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("Error al guardar los contactos\n");
        return;
    }
    printf("Cargando contactos... \n");
    for (i = 0; i < agenda.num_contactos; i++)
    {
        Contacto c = agenda.contactos[i];
        fprintf(f, "| %s | %s | %d | %d | %s | %d |\n", c.nombre, c.apellido, c.dia, c.mes, c.telefono, c.tipo);
    }
    fclose(f);
    printf("Contactos guardados \n");
}