// tests/test_agregar.c
#include "../src/agenda.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
    Agenda a;
    iniciar_agenda(&a);
    Contacto contacto1 = {"Ana", "Perez", 11, ENERO, "5555555555", CASA};    
    agregar_contacto(&a, contacto1);    
    assert(a.num_contactos == 1);
    assert(strcmp(a.contactos[0].nombre, "Ana") == 0);
    printf("Prueba agregar_contacto: OK\n");
    return 0;
}