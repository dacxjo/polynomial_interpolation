#ifndef POLYNOMIAL_INTERPOLATION_FUNS_INTERP_H
#define POLYNOMIAL_INTERPOLATION_FUNS_INTERP_H

double horner(double z, double *x, double *c, int n );

int difdiv(double *x, double *f, int n);

double fun_log(double z);

double fun_runge(double z);

void print_poli(double *y,double *x,int n);

void reverse_arr(double *arr, int n);

void genVectNul(int n, double *V);

#endif

