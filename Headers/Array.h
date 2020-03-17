#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <iostream>

#include "Random.h"

using namespace std;

bool arrays_are_equal(double * array_first, double * array_second, int n);
double *generate_random_array(int);

template <typename T>
void print_array(T *array, string label, int n, int k = 1)
{
    cout << endl
         << label << ": ";

    for (int i = 0; i < k * n; i++)
        cout << array[i] << (i != (k * n) - 1 ? ", " : "");

    cout << endl;
}

#endif