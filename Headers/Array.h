#ifndef ARRAY_H
#define ARRAY_H

#include <string>

using namespace std;

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