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
	int n;
	int nonzeros;

	double *x, *y_CRS, *y_STANDARD;

	double **sparse_matrix, **sparse_matrix_from_CRS;

	srand((unsigned int)time(NULL));

	cout.setf(ios_base::fixed);

	cout << "Podaj rozmiar macierzy rzadkiej: ";
	cin >> n;

	cout << "Podaj ilosc niezerowych elementow w wierszu macierzy: ";
	cin >> nonzeros;

	if (nonzeros >= n)
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
		generate_matrix(n),
		n,
		nonzeros);

	auto [val, col_ind, row_ptr] = to_CRS_format(
		sparse_matrix,
		n,
		nonzeros);

	sparse_matrix_from_CRS = from_CRS_format(val, col_ind, row_ptr, n);

	if (matrices_are_equal(sparse_matrix, sparse_matrix_from_CRS, n))
	{
		cout << endl
			 << "Macierz rzadka zapisana w formacie 'CRS' zgadza sie "
			 << "z macierza w formacie standardowym."
			 << endl;

		if (n <= 10)
		{
			print_array(val, "val", n, nonzeros);
			print_array(col_ind, "col_ind", n, nonzeros);
			print_array(row_ptr, "row_ptr", n + 1);
		}

		x = generate_random_array(n);

		y_CRS = multiply_sparse_matrix_CRS(
			x,
			val,
			col_ind,
			row_ptr,
			n);

		y_STANDARD = multiply_sparse_matrix(sparse_matrix_from_CRS, x, n);

		if (n <= 10000)
		{
			print_array(y_CRS, "y (macierz rzadka w formacie CRS)", n);
			print_array(y_STANDARD, "y (macierz rzadka w formacie standardowym)", n);
		}

		cout << endl
			 << "Czy wyniki mnozenia macierzy rzadkiej przez wektor "
			 << "sa takie same dla formatu CRS i standardowego? "
			 << (arrays_are_equal(y_CRS, y_STANDARD, n) ? "true" : "false");
	}
	else
	{
		cout << endl
			 << "Macierz rzadka zapisana w formacie 'CRS' nie zgadza sie "
			 << "z macierza w formacie standardowym."
			 << endl;
	}

	delete_matrix(sparse_matrix, n);

	delete[] val;
	delete[] col_ind;
	delete[] row_ptr;

	delete[] x;

	delete_matrix(sparse_matrix_from_CRS, n);

	delete[] y_CRS;
	delete[] y_STANDARD;

	return 0;
}