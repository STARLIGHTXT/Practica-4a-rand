#include "rand.h"

void *inicializa_random_1_svc(long *argp, struct svc_req *rqstp) {
    static char *result;
    printf("Se llamo a inicializa_random_1_svc\n");
    srandom(*argp);
    return (void *)&result;
}

double *obtiene_siguiente_random_1_svc(void *argp, struct svc_req *rqstp) {
    static double result;
    result = random();
    printf("Se llamo a obtiene_siguiente_random_1_svc, numero generado: %.0f\n", result);
    return &result;
}
