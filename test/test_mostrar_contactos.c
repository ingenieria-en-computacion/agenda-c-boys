#include "../src/agenda.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
    Agenda a;
    iniciar_agenda(&a);
    Contacto contacto1 = {"Ana", "Perez", 11, ENERO, "5555555555", CASA};
    Contacto contacto2 = {"Helena", "Rodriguez", 12, SEPTIEMBRE, "5555555556", MOVIL};
    agregar_contacto(&a, contacto1);
    agregar_contacto(&a, contacto2);

    // Redirigir stdout a un archivo temporal
    FILE *temp = freopen("data/test_imprimir.txt", "w", stdout);
    imprimir_agenda(a);
    fclose(temp);

    FILE *f = fopen("data/test_imprimir.txt", "r");
    char buffer[256];
    fgets(buffer, sizeof(buffer), f);
    fclose(f);

    assert(strstr(buffer, "Ana") != NULL);
    printf("✅ test_imprimir: OK\n");
    return 0;
}
