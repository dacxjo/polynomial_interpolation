
#include <strings.h>
#include "stdio.h"
#include "stdlib.h"
#include "funs_interp.h"

int main() {
    double *x, *y, a, b, eval, peval;
    int n, result, i, pnum = 1000;
    FILE *file, *fout;

    printf("-----Interpolacio Polinomial-----\n");
    printf("Ingressi el grau del polinomi:\n");
    scanf("%d", &n);

    n += 1;

    x = (double *) malloc((sizeof(double) * n));
    y = (double *) malloc((sizeof(double) * n));

    if (x == NULL || y == NULL) {
        printf("No memory");
        exit(EXIT_FAILURE);
    }

    file = fopen("taula.in", "r");

    if (file == NULL) {
        printf("No es troba l'arxiu");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        fscanf(file, "%le\t%le", &x[i], &y[i]);
    }

    printf("Ingressi els extrems del interval:\n");
    printf("Extrem A: ");
    scanf("%le", &a);
    printf("Extrem B: ");
    scanf("%le", &b);
    result = difdiv(x, y, n - 1);
    fout = fopen("p3taula.out", "w");
    if (result == 0) {
        for (i = 0; i < pnum; i++) {
            peval = a + (i * ((b - a) / pnum));
            printf("Evaluacio #%d en %24.16e\n", i + 1, peval);
            eval = horner(peval, x, y, n - 1);
            printf("%24.16e\n", eval);
            fprintf(fout, "%24.16e\t %24.16e\n", peval, eval);
        }
        print_poli(y, x, n - 1);
    }
    free(x);
    free(y);
    fclose(file);
    fclose(fout);
    return 0;
}

