
#include <strings.h>
#include "stdio.h"
#include "stdlib.h"
#include "funs_interp.h"

int main() {
    double *x, *y, a, b, pdistance, eval, peval;
    int n, result, i, j, pnum = 1000;
    FILE *file,*fout;

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

    file = fopen("../taula.in", "r");

    if (file == NULL) {
        printf("No es troba l'arxiu");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        fscanf(file, "%lf\t%lf", &x[i], &y[i]);
    }

    printf("Ingressi els extrems del interval:\n");
    printf("Extrem A: ");
    scanf("%le", &a);
    printf("Extrem B: ");
    scanf("%le", &b);

    result = difdiv(x, y, n);

    if (result == 0) {
        printf("Polinomi:\n");
        for (i = 0; i < n; i++) {
            if (i == 0) {
                printf("P(x) = %lf", y[i]);
            } else {
                if (y[i] > 0) {
                    printf("+");
                }
                printf("%lf", y[i]);
                for (j = 0; j < i; j++) {
                    printf("(x-%lf)", x[j]);
                }
            }
        }
        printf("\n");
    }

    pdistance = (b - a) / (pnum - 1);
    printf("Rao de cambi: %.24lf\n",pdistance);

    fout = fopen("../p3taula.out","w");
    printf("Evaluacio #%d en %.24lf\n", 1, a);
    eval = horner(a, x, y, n - 1);
    printf("%.24lf\n", eval);
    peval = a;
    fprintf(fout,"%24.16e\t %24.16e\n",peval,eval);
    for (i = 1; i < pnum ; i++) {
        peval += pdistance;
        printf("Evaluacio #%d en %.24lf\n", i+1, peval);
        eval = horner(peval, x, y, n - 1);
        printf("%.24lf\n",eval );
        fprintf(fout,"%24.16e\t %24.16e\n",peval,eval);
    }
    free(x);
    free(y);
    fclose(file);
    fclose(fout);
    return 0;
}
