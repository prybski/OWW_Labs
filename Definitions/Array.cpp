#include "Array.h"

bool arrays_are_equal(double *array_first, double *array_second, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (array_first[i] != array_second[i])
            return false;
    }

    return true;
}

double *generate_random_array(int n)
{
    double *x = new double[n];

    for (int i = 0; i < n; i++)
        x[i] = generate_random(0, 100);

    return x;
}