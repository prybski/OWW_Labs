#include <time.h>
#include <iostream>
#include <iomanip>

#include "Random.h"
#include "Matrix.h"

using namespace std;

const int RANDOM_NUMBERS_COUNT = 20;
const int NONZEROS_MIN = 1;

int main()
{
	int i, j;
	int min_scalar, max_scalar, scalar;
	double min_real, max_real, real;

	int rows, columns;
	int nonzeros_max;
	int nonzeros_counter = NONZEROS_MIN;
	double** matrix;

	srand((unsigned int)time(NULL));

	cout.setf(ios_base::fixed);

	cout << "Podaj dwie liczby rzeczywiste: ";
	cin >> min_real >> max_real;

	cout << endl << "Losowe liczby rzeczywiste z zakresu: " << min_real
		<< " - " << max_real << endl;

	for (i = 0; i < RANDOM_NUMBERS_COUNT; i++)
	{
		real = generate_random(min_real, max_real);

		cout << real << " ";

#ifdef DEBUG
		if (real < a || real > b)
		{
			cout << "Blad generacji: " << real << endl;

			exit(0);
		}
#endif
	}

	cout << endl << endl << "Podaj dwie liczby calkowite: ";
	cin >> min_scalar >> max_scalar;

	cout << endl << "Losowe liczby calkowite z zakresu: " << min_scalar
		<< " - " << max_scalar << endl;

	for (i = 0; i < RANDOM_NUMBERS_COUNT; i++)
	{
		scalar = generate_random(min_scalar, max_scalar);

		cout << scalar << " ";

#ifdef DEBUG
		if (scalar < j || scalar > k)
		{
			cout << "Blad generacji: " << scalar << endl;

			exit(0);
		}
#endif
	}

	cout << endl << endl << "Podaj rozmiar macierzy rzadkiej: ";
	cin >> rows >> columns;

	cout << "Podaj ilosc niezerowych elementow w wierszu macierzy: ";
	cin >> nonzeros_max;

	if (nonzeros_max >= columns)
	{
		cout << endl << "Ilosc niezerowych elementow w wierszu macierzy "
			<< "nie moze byc wieksza od liczby jej kolumn lub rowna "
			<< "liczbie jej kolumn.";

		return -1;
	}

	if (nonzeros_max <= 0)
	{
		cout << endl << "Ilosc niezerowych elementow w wierszu "
			<< "macierzy nie moze mniejsza od zera lub rowna zeru.";

		return -10;
	}

	matrix = generate_matrix(rows, columns);

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			if (nonzeros_counter == nonzeros_max) continue;

			matrix[i][generate_random_column_index(matrix[i], columns)]
				= generate_random((double)0, (double)1);

			nonzeros_counter++;
		}

		nonzeros_counter = NONZEROS_MIN;
	}

	print_matrix(matrix, rows, columns);

	delete_matrix(matrix, rows);

	return 0;
}