#ifndef MATRIX_FORMAT_H
#define MATRIX_FORMAT_H

#include <iostream>
#include <string>

using namespace std;

tuple<double *, int *, int *> generate_CRS_format(double **, int, int, int);

template <typename T>
void print_array(T * array, string label, int n, int k = 1)
{
    cout << endl << label << ": ";

    for (int i = 0; i < k * n; i++)
    {
        cout << array[i] << (i != (k * n) - 1 ? ", " : "");
    }

    cout << endl;
}

#endif
