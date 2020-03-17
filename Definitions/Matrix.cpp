#include "Matrix.h"

using namespace std;

bool matrices_are_equal(double ** matrix_first, double ** matrix_second, int n)
{
    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix_first[i][j] != matrix_second[i][j])
                return false;
		}
	}

    return true;
}

int generate_random_column_index(double *matrix_row, int n)
{
	int proper_index = generate_random(0, n - 1);

	if (matrix_row[proper_index] == 0.0)
		return proper_index;
	else
		return generate_random_column_index(matrix_row, n);
}

double **generate_matrix(int n)
{
	double **matrix = new double *[n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[n];

		for (int j = 0; j < n; j++)
		{
			if (i == j)
				matrix[i][j] = generate_random(1.0, 2.0);
			else
				matrix[i][j] = 0.0;
		}
	}

	return matrix;
}

double **generate_zeros_matrix(int n)
{
	double **matrix = new double *[n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[n];

		for (int j = 0; j < n; j++)
			matrix[i][j] = 0.0;
	}

	return matrix;
}

void print_matrix(double **matrix, int n)
{
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << "\t";

		cout << endl;
	}
}

void delete_matrix(double **matrix, int n)
{
	for (int i = 0; i < n; i++)
		delete[] matrix[i];

	delete[] matrix;
}