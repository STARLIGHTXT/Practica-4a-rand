#include "rand.h"

void rand_prog_1(char *host, long a, int b) {
    CLIENT *clnt;
    void *result_1;
    long inicializa_random_1_arg;
    double *result_2;
    char *obtiene_siguiente_random_1_arg;

#ifndef DEBUG
    clnt = clnt_create(host, RAND_PROG, RAND_VERS, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror(host);
        exit(1);
    }
#endif

    printf("Uso: %ld como semilla y %d iteraciones\n", a, b);
    inicializa_random_1_arg = a;
    result_1 = inicializa_random_1(&inicializa_random_1_arg, clnt);
    if (result_1 == (void *)NULL) {
        clnt_perror(clnt, "call failed");
    }

    for (int i = 0; i < b; i++) {
        result_2 = obtiene_siguiente_random_1((void *)NULL, clnt);
        if (result_2 == (double *)NULL) {
            clnt_perror(clnt, "call failed");
        }
        printf("rnd : %.0f\n", *result_2);
    }

#ifndef DEBUG
    clnt_destroy(clnt);
#endif
}

int main(int argc, char *argv[]) {
    char *host;
    int a, b;

    if (argc != 4) {
        printf("usage: %s server_host num1 num2\n", argv[0]);
        exit(1);
    }

    host = argv[1];

    if ((a = (long)atol(argv[2])) == 0 && *argv[2] != '0') {
        fprintf(stderr, "invalid value: %s\n", argv[2]);
        exit(1);
    }

    if ((b = atoi(argv[3])) == 0 && *argv[3] != '0') {
        fprintf(stderr, "invalid value: %s\n", argv[3]);
        exit(1);
    }

    rand_prog_1(host, (long)a, b);
    exit(0);
}
