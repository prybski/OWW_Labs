#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

#include "Random.h"

int generate_random_column_index(double*, int);
double** generate_matrix(int, int);
double** generate_sparse_matrix(double**, int, int, int);
void print_matrix(double**, int, int);
void delete_matrix(double**, int);

#endif
