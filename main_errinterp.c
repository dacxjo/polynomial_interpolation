#include "funs_interp.h"
#include <stdio.h>
#include "stdlib.h"
#include <math.h>

int main() {
    int i, n, opt, result, pnum = 1000;
    double a, b, peval, eval, *x, *y, err_maxim;
    char nom_arxiu[250];
    FILE *fout;
    printf("----Error d'interpolacio----\n");
    printf(" Tria la funcio a utilizar |\n");
    printf("[1]. Funcio ln(x)          |\n");
    printf("[2]. Funcio de Runge       |\n");
    printf("[3]. Sortir                |\n");
    printf("----------------------------\n");

    scanf("%d", &opt);

    switch (opt) {
        case 1:
            printf("Ingressi el grau del polinomi:\n");
            scanf("%d", &n);
            printf("Ingressi els extrems del interval:\n");
            printf("Extrem A: ");
            scanf("%le", &a);
            printf("Extrem B: ");
            scanf("%le", &b);
            printf("Ingressi el nom del fitxer de sortida:\n");
            scanf("%s", nom_arxiu);

            n += 1;

            x = (double *) malloc((sizeof(double) * n));
            y = (double *) malloc((sizeof(double) * n));

            if (x == NULL || y == NULL) {
                printf("No memory");
                exit(EXIT_FAILURE);
            }

            for (i = 0; i < n; i++) {
                peval = a + i * ((b - a) / n);
                x[i] = peval;
                y[i] = fun_log(peval);
            }

            reverseArr(x, n);
            reverseArr(y, n);

            result = difdiv(x, y, n - 1);
            for (i = 0;i  < n; i++) {
                printf("%24.16e\n",x[i]);
            }
            if (result == 0) {
                fout = fopen(nom_arxiu, "w");
                err_maxim = 0.0;
                for (i = 0; i < pnum; i++) {
                    peval = a + (i * ((b - a) / pnum));
                    printf("Evaluacio #%d en %24.16e\n", i + 1, peval);
                    eval = horner(peval, x, y, n);
                    printf("%24.16e\n", eval);
                    fprintf(fout, "%24.16e\t %24.16e\t %24.16e\n", peval, fun_log(peval), eval);
                    if (fabs(fun_log(peval) - eval) > err_maxim) {
                        err_maxim = fabs(fun_log(peval) - eval);
                    }
                }
                fprintf(fout, "# %24.16e\n", err_maxim);
                print_poli(y, x, n - 1);
                fclose(fout);
            }
            free(x);
            free(y);
            break;
        case 2:
            printf("Ingressi el grau del polinomi:\n");
            scanf("%d", &n);
            printf("Ingressi els extrems del interval:\n");
            printf("Extrem A: ");
            scanf("%le", &a);
            printf("Extrem B: ");
            scanf("%le", &b);
            printf("Ingressi el nom del fitxer de sortida:\n");
            scanf("%s", nom_arxiu);

            n += 1;

            x = (double *) malloc((sizeof(double) * n));
            y = (double *) malloc((sizeof(double) * n));

            genVectNul(n,x);
            genVectNul(n,y);

            if (x == NULL || y == NULL) {
                printf("No memory");
                exit(EXIT_FAILURE);
            }

            for (i = 0; i < n; i++) {
                peval = ((double) (2 * i) / (n - 1)) - 1;
                x[i] = peval;
                y[i] = fun_runge(peval);
            }

            reverseArr(x, n);
            reverseArr(y, n);

            result = difdiv(x, y, n - 1);

            if (result == 0) {
                fout = fopen(nom_arxiu, "w");
                err_maxim = 0.0;
                for (i = 0; i < pnum; i++) {
                    peval = a + (i * ((b - a) / pnum));
                    printf("Evaluacio #%d en %24.16e\n", i + 1, peval);
                    eval = horner(peval, x, y, n);
                    printf("%24.16e\n", eval);
                    fprintf(fout, "%24.16e\t %24.16e\t %24.16e\n", peval, fun_runge(peval), eval);
                    if (fabs(fun_runge(peval) - eval) > err_maxim) {
                        err_maxim = fabs(fun_runge(peval) - eval);
                    }
                }
                fprintf(fout, "# %24.16e\n", err_maxim);
                print_poli(y, x, n - 1);
                fclose(fout);
            }
            free(x);
            free(y);
            break;
        default:
            exit(EXIT_SUCCESS);
    }

    return 0;
}
