#include "calc.h"

int *suma_1(int *a, int *b, CLIENT *clnt) {
    static int result;
    result = *a + *b;
    return &result;
}

int *resta_1(int *a, int *b, CLIENT *clnt) {
    static int result;
    result = *a - *b;
    return &result;
}

int *multiplica_1(int *a, int *b, CLIENT *clnt) {
    static int result;
    result = (*a) * (*b);
    return &result;
}

int *divide_1(int *a, int *b, CLIENT *clnt) {
    static int result;
    if (*b == 0) {
        result = 0;
    } else {
        result = (*a) / (*b);
    }
    return &result;
}
