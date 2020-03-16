#ifndef MATRIX_FORMAT_H
#define MATRIX_FORMAT_H

#include <iostream>

using namespace std;

double *multiply_sparse_matrix_in_CRS_format(double *, double *, int *, int *, int);
tuple<double *, int *, int *> generate_CRS_format(double **, int, int, int);

#endif