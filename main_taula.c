
#include "stdio.h"
#include "stdlib.h"
#include "funs_interp.h"

int main() {

    double *x, *y;
    int n = 4, i, result;
    FILE *file;

    x = (double *) malloc((sizeof(double) * n));
    y = (double *) malloc((sizeof(double) * n));

    if (x == NULL || y == NULL) {
        printf("No memory");
        exit(EXIT_FAILURE);
    }


    x[0] = 4.8;
    x[1] = 3.2;
    x[2] = 2.7;
    x[3] = 1.0;


    y[0] = 38.3;
    y[1] = 22.0;
    y[2] = 17.8;
    y[3] = 14.2;

    result = difdiv(x, y, n);

    if (result == 0) {
        for (i = 0; i < n; i++) {
            printf("%lf\n", y[i]);
        }
    }
    printf("Evauluacion \n");
    for (i = 0; i < n; i++) {
        printf("%lf\n", horner(x[i], x, y, n));
    }


    /* x[0] = 3.2;
     x[1] = 2.7;
     x[2] = 1.0;

     c[0] = 22.0;
     c[1] = 8.4;
     c[2] = 2.85;*/


    return 0;
}