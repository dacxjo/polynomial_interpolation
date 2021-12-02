#include "funs_interp.h"
#include <math.h>

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
            if(fabs(deno) < tol){
                return -1;
            }
            f[i] = num / deno;
        }
    }
    return 0;
}