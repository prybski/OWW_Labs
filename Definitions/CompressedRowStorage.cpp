#include "CompressedRowStorage.h"
#include "SparseMatrix.h"

using namespace std;

const int VAL_MIN = 1;

double *multiply_sparse_matrix_CRS(double *x, double *val, int *col_ind, int *row_ptr, int n)
{
    double *y = new double[n];

    for (int i = 0; i < n; i++)
    {
        y[i] = 0.0;

        for (int j = row_ptr[i]; j < row_ptr[i + 1]; j++)
            y[i] += val[j] * x[col_ind[j]];
    }

    return y;
}

double **from_CRS_format(double *val, int *col_ind, int *row_ptr, int n)
{
    double **matrix = generate_zeros_matrix(n);

	for (int i = 0; i < n; i++)
    {
        for (int j = row_ptr[i]; j < row_ptr[i + 1]; j++)
            matrix[i][col_ind[j]] = val[j];
    }

    return matrix;
}

tuple<double *, int *, int *> to_CRS_format(double **sparse_matrix, int n, int k)
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
        for (int j = 0; j < n; j++)
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