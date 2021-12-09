#ifndef POLYNOMIAL_INTERPOLATION_FUNS_INTERP_H
#define POLYNOMIAL_INTERPOLATION_FUNS_INTERP_H

double horner(double z, double *x, double *c, int n );

int difdiv(double *x, double *f, int n);

void genVectNul(int n, double *V);

#endif

