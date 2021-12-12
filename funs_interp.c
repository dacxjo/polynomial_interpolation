#include "funs_interp.h"
#include <math.h>
#include "stdio.h"

double horner(double z, double *x, double *c, int n) {
    int i;
    double p;
    p = c[n];
    for (i = n - 1; i >= 0; i--) {
        p = p * (z - x[i]) + c[i];
    }
    return p;
}

int difdiv(double *x, double *f, int n) {
    double tol = 10e-12, num, deno;
    int i, k;
    for (k = 1; k <= n; k++) {
        for (i = n; i >= k; i--) {
            num = (f[i] - f[i - 1]);
            deno = (x[i] - x[i - k]);
            if (fabs(deno) < tol) {
                return -1;
            }
            f[i] = num / deno;
        }
    }
    return 0;
}

double fun_log(double z) {
    return log(z);
}

double fun_runge(double z) {
    return 1 / (1 + (25 * z * z));
}

void print_poli(double *y, double *x, int n) {
    int i, j;
    printf("Polinomi:\n");
    for (i = 0; i < n + 1; i++) {
        if (i == 0) {
            printf("P(%d) = %e", n, y[i]);
        } else {
            if (y[i] > 0.0) {
                printf("+");
            }
            printf("%e", y[i]);
            for (j = 0; j < i; j++) {
                if (x[j] < 0) {
                    printf("(x-(%e))", x[j]);
                } else {
                    printf("(x-%e)", x[j]);
                }

            }
        }
    }
    printf("\n");
}

void reverseArr(double *arr, int n) {
    int i;
    double temp;
    for (i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

void genVectNul(int n, double *V) {
    int i;
    for (i = 0; i < n; i++) {
        V[i] = 0.0;
    }
}
