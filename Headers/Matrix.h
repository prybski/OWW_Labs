#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

#include "Random.h"

bool matrices_are_equal(double **, double **, int);
int generate_random_column_index(double *, int);
double **generate_matrix(int);
double **generate_zeros_matrix(int);
void print_matrix(double **, int);
void delete_matrix(double **, int);

#endif