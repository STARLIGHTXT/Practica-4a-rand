#include "calc.h"
#include <stdio.h>
#include <stdlib.h>

void main_client(CLIENT *clnt, int op, int a, int b) {
    int *result;

    switch(op) {
        case 1:
            result = suma_1(&a, &b, clnt);
            printf("Suma: %d + %d = %d\n", a, b, *result);
            break;
        case 2:
            result = resta_1(&a, &b, clnt);
            printf("Resta: %d - %d = %d\n", a, b, *result);
            break;
        case 3:
            result = multiplica_1(&a, &b, clnt);
            printf("Multiplicación: %d * %d = %d\n", a, b, *result);
            break;
        case 4:
            if (b == 0) {
                printf("Error: División por cero\n");
                break;
            }
            result = divide_1(&a, &b, clnt);
            printf("División: %d / %d = %d\n", a, b, *result);
            break;
        default:
            printf("Operación inválida\n");
    }
}

int main(int argc, char *argv[]) {
    CLIENT *clnt;
    char *host;

    if (argc != 5) {
        fprintf(stderr, "Uso: %s <host> <op> <a> <b>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    int op = atoi(argv[2]);
    int a = atoi(argv[3]);
    int b = atoi(argv[4]);

    clnt = clnt_create(host, CALC_PROG, CALC_VERS, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror(host);
        exit(1);
    }

    main_client(clnt, op, a, b);
    clnt_destroy(clnt);
    return 0;
}
