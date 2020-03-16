#include <time.h>
#include <iostream>
#include <iomanip>

#include "Array.h"
#include "Random.h"
#include "SparseMatrix.h"
#include "CompressedRowStorage.h"

using namespace std;

int main()
{
	int rows, columns;
	int nonzeros;

	double *y;

	double **sparse_matrix;

	srand((unsigned int)time(NULL));

	cout.setf(ios_base::fixed);

	cout << "Podaj rozmiar macierzy rzadkiej: ";
	cin >> rows >> columns;

	cout << "Podaj ilosc niezerowych elementow w wierszu macierzy: ";
	cin >> nonzeros;

	if (nonzeros >= columns)
	{
		cout << endl
			 << "Ilosc niezerowych elementow w wierszu macierzy "
			 << "nie moze byc wieksza od liczby jej kolumn lub rowna "
			 << "liczbie jej kolumn.";

		return -1;
	}

	if (nonzeros <= 0)
	{
		cout << endl
			 << "Ilosc niezerowych elementow w wierszu "
			 << "macierzy nie moze byc mniejsza od zera lub rowna zeru.";

		return -10;
	}

	sparse_matrix = generate_sparse_matrix(
		generate_matrix(rows, columns),
		rows,
		columns,
		nonzeros);

	print_matrix(sparse_matrix, rows, columns);

	auto [val, col_ind, row_ptr] = generate_CRS_format(
		sparse_matrix,
		rows,
		columns,
		nonzeros);

	delete_matrix(sparse_matrix, rows);

	print_array(val, "val", rows, nonzeros);
	print_array(col_ind, "col_ind", rows, nonzeros);
	print_array(row_ptr, "row_ptr", rows + 1);

	double *x = new double[rows];

	cout << endl
		 << "Podaj wektor, przez ktory nalezy pomnozyc macierz rzadka: ";

	for (int i = 0; i < rows; i++)
		cin >> x[i];

	print_array(x, "x", rows);

	y = multiply_sparse_matrix_in_CRS_format(
		x,
		val,
		row_ptr,
		col_ind,
		rows);

	print_array(y, "y", rows);

	return 0;
}