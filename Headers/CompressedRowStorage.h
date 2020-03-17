#ifndef MATRIX_FORMAT_H
#define MATRIX_FORMAT_H

#include <iostream>

using namespace std;

double *multiply_sparse_matrix_CRS(double *, double *, int *, int *, int);
double **from_CRS_format(double *, int *, int *, int);
tuple<double *, int *, int *> to_CRS_format(double **, int, int);

#endif