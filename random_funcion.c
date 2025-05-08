#include <stdlib.h>
#include "random_local.h"

void inicializa_random(long semilla) {
    srand(semilla);
}

long obtiene_siguiente_random(void) {
    return rand();
}
