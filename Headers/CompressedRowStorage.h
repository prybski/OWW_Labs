#ifndef MATRIX_FORMAT_H
#define MATRIX_FORMAT_H

#include <iostream>
#include <string>

using namespace std;

double *multiply_sparse_matrix_in_CRS_format(double *, double *, int *, int *, int);
tuple<double *, int *, int *> generate_CRS_format(double **, int, int, int);
void print_row_ptr(int *, string, int);

template <typename T>
void print_array(T *array, string label, int n, int k = 1)
{
    cout << endl
         << label << ": ";

    for (int i = 0; i < k * n; i++)
    {
        cout << array[i] << (i != (k * n) - 1 ? ", " : "");
    }

    cout << endl;
}

#endif
