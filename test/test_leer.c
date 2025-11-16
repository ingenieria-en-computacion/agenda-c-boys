#include "../src/agenda.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
    // Preparamos un archivo con datos conocidos
    FILE *f = fopen("data/test_leer.txt", "w");
    fprintf(f, "Ana 1111\nBeatriz 2222\n");
    fclose(f);

    Agenda a;
    iniciar_agenda(&a);
    cargar_contactos("data/test_leer.txt", &a);

    assert(a.num_contactos == 2);
    assert(strcmp(a.contactos[0].nombre, "Ana") == 0);
    assert(strcmp(a.contactos[1].telefono, "5555555555") == 0);

    printf("✅ test_leer: OK\n");
    return 0;
}
