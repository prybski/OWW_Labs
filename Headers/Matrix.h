#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

#include "Random.h"

double** generate_matrix(int, int);
void print_matrix(double**, int, int);
void delete_matrix(double**, int);
int generate_random_column_index(double*, int);

#endif