#include "SparseMatrix.h"

using namespace std;

const int NONZEROS_MIN = 1;

double *multiply_sparse_matrix(double **sparse_matrix, double *x, int n)
{
    double *y = new double[n];

    for (int i = 0; i < n; i++)
    {
        y[i] = 0.0;

        for (int j = 0; j < n; j++)
            y[i] += sparse_matrix[i][j] * x[j];
    }

    return y;
}

double **generate_sparse_matrix(double **matrix, int n, int k)
{
	int counter = NONZEROS_MIN;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (counter == k)
				continue;

			matrix[i][generate_random_column_index(matrix[i], n)] = generate_random(0.0, 1.0);

			counter++;
		}

		counter = NONZEROS_MIN;
	}

	return matrix;
}