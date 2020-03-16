#include "CompressedRowStorage.h"

using namespace std;

const int VAL_MIN = 1;

double *multiply_sparse_matrix_in_CRS_format(double *x, double *val, int *row_ptr, int *col_ind, int n)
{
    double *y = new double[n];

    for (int i = 0; i < n; i++)
    {
        y[i] = 0.0;

        for (int j = row_ptr[i]; j < row_ptr[i + 1]; j++)
        {
            y[i] += val[j] * x[col_ind[j]];
        }
    }

    return y;
}

tuple<double *, int *, int *> generate_CRS_format(double **sparse_matrix, int n, int m, int k)
{
    int val_idx = 0;
    int col_ind_idx = 0;
    int row_ptr_idx = 0;

    int val_counter = VAL_MIN;

    int *col_ind = new int[k * n];
    int *row_ptr = new int[n + 1];

    double *val = new double[k * n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (sparse_matrix[i][j] != 0.0)
            {
                if (val_counter == VAL_MIN)
                    row_ptr[row_ptr_idx++] = val_idx;

                val[val_idx++] = sparse_matrix[i][j];
                col_ind[col_ind_idx++] = j;

                val_counter++;
            }
        }

        val_counter = VAL_MIN;
    }

    row_ptr[n] = k * n;

    return {val, col_ind, row_ptr};
}

void print_row_ptr(int *row_ptr, string label, int n)
{
    cout << endl
         << label << ": ";

    for (int i = 0; i < n; i++)
    {
        cout << row_ptr[i] << (i != n - 1 ? ", " : "");
    }

    cout << endl;
}