#include "../src/agenda.h"
#include <assert.h>
#include <stdio.h>

int main() {
    Agenda a;
    iniciar_agenda(&a);
    Contacto contacto1 = {"Ana", "Perez", 11, ENERO, "5555555555", CASA};
    Contacto contacto2 = {"Helena", "Rodriguez", 12, SEPTIEMBRE, "5555555556", MOVIL};
    agregar_contacto(&a, contacto1);
    agregar_contacto(&a, contacto2);

    guardar_contactos("data/test_guardar.txt", a);

    FILE *f = fopen("data/test_guardar.txt", "r");
    assert(f != NULL);

    char linea[256];
    int count = 0;
    while (fgets(linea, 256, f)) count++;
    fclose(f);

    assert(count == 2);
    printf("✅ test_guardar: OK\n");
    return 0;
}
