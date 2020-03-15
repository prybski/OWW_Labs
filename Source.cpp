#include <time.h>
#include <iostream>
#include <iomanip>


#include "Random.h"
#include "Matrix.h"
#include "Utils.h"

using namespace std;

const int VAL_MIN = 1;

int main()
{
	int rows, columns;
	int nonzeros;

	int *col_ind, *row_ptr;

	double *val;

	double **rare_matrix;

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

	rare_matrix = generate_rare_matrix(
		generate_matrix(rows, columns),
		rows,
		columns,
		nonzeros);

	print_matrix(rare_matrix, rows, columns);

	// =====================================================================
	val = new double[nonzeros * rows];

	col_ind = new int[nonzeros * rows];
	row_ptr = new int[rows];

	int val_idx = 0;
	int col_ind_idx = 0;
	int row_ptr_idx = 0;

	int val_counter = VAL_MIN;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (rare_matrix[i][j] != 0.0)
			{
				if (val_counter == VAL_MIN) row_ptr[row_ptr_idx++] = val_idx;

				val[val_idx++] = rare_matrix[i][j];
				col_ind[col_ind_idx++] = j;

				val_counter++;
			}
		}

		val_counter = VAL_MIN;
	}

	cout << endl;

	cout << "val: ";

	for (int i = 0; i < nonzeros * rows; i++)
	{
		cout << val[i] << (i != (nonzeros * rows) - 1 ? ", " : "");
	}

	cout << endl;

	cout << "col_ind: ";

	for (int i = 0; i < nonzeros * rows; i++)
	{
		cout << col_ind[i] << (i != (nonzeros * rows) - 1 ? ", " : "");
	}

	cout << endl;

	cout << "row_ptr: ";

	for (int i = 0; i < rows; i++)
	{
		cout << row_ptr[i] << (i != rows - 1 ? ", " : "");
	}
	// =====================================================================

	delete_matrix(rare_matrix, rows);

	pause_console();

	return 0;
}