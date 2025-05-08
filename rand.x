/* rand.x */

program RAND_PROG {
    version RAND_VERS {
        char *inicializa_random_1(long) = 1;
        double *obtiene_siguiente_random_1(void) = 2;
    } = 1;
} = 0x31230000;