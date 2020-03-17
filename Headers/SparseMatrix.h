#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <iostream>

#include "Random.h"
#include "Matrix.h"

double *multiply_sparse_matrix(double **, double *, int);
double **generate_sparse_matrix(double **, int, int);

#endif