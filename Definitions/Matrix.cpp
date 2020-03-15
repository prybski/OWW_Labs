#include "Matrix.h"

using namespace std;

const int NONZEROS_MIN = 1;

int generate_random_column_index(double* matrix_row, int m)
{
	int proper_index = generate_random(0, m - 1);

	if (matrix_row[proper_index] == 0.0) return proper_index;
	else return generate_random_column_index(matrix_row, m);
}

double** generate_matrix(int n, int m)
{
	double** matrix = new double* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[m];

		for (int j = 0; j < m; j++)
		{
			if (i == j) matrix[i][j] = generate_random(1.0, 2.0);
			else matrix[i][j] = 0.0;
		}
	}

	return matrix;
}

double** generate_sparse_matrix(double** matrix, int n, int m, int k)
{
	int counter = NONZEROS_MIN;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (counter == k) continue;

			matrix[i][generate_random_column_index(matrix[i], m)]
				= generate_random(0.0, 1.0);

			counter++;
		}

		counter = NONZEROS_MIN;
	}

	return matrix;
}

void print_matrix(double** matrix, int n, int m)
{
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cout << matrix[i][j] << "\t";

		cout << endl;
	}
}

void delete_matrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++) delete[] matrix[i];

	delete[] matrix;
}