#include <stdio.h>
#include <stdlib.h>
#include "random_local.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <semilla> <cantidad>\n", argv[0]);
        exit(1);
    }

    long semilla = atol(argv[1]);
    int cantidad = atoi(argv[2]);

    inicializa_random(semilla);

    for (int i = 0; i < cantidad; i++) {
        printf("Random #%d: %ld\n", i + 1, obtiene_siguiente_random());
    }

    return 0;
}
