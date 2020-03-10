#include <time.h>
#include <iostream>
#include <iomanip>

#include "Random.h"
#include "Matrix.h"
#include "Utils.h"

using namespace std;

const int RANDOM_NUMBERS_COUNT = 20;
const int NONZEROS_MIN = 1;

void generate_range_of_random_real_numbers()
{
	double min_real, max_real, real;

	cout << "Podaj dwie liczby rzeczywiste: ";
	cin >> min_real >> max_real

	cout << endl << "Losowe liczby rzeczywiste z zakresu: " << min_real
		<< " - " << max_real << endl;

	for (int i = 0; i < RANDOM_NUMBERS_COUNT; i++)
	{
		real = generate_random(min_real, max_real);

		cout << real << " ";

#ifdef DEBUG
		if (real < min_real || real > max_real)
		{
			cout << "Blad generacji: " << real << endl;

			exit(0);
		}
#endif
	}
}

void generate_range_of_random_integer_numbers()
{
	int min_integer, max_integer, integer;

	cout << endl << endl << "Podaj dwie liczby calkowite: ";
	cin >> min_integer >> max_integer;

	cout << endl << "Losowe liczby calkowite z zakresu: " << min_integer
		<< " - " << max_integer << endl;

	for (int i = 0; i < RANDOM_NUMBERS_COUNT; i++)
	{
		integer = generate_random(min_integer, max_integer);

		cout << integer << " ";

#ifdef DEBUG
		if (integer < min_integer || integer > max_integer)
		{
			cout << "Blad generacji: " << integer << endl;

			exit(0);
		}
#endif
	}
}

int main()
{
	int i, j;
	int rows, columns;
	int nonzeros_max;
	int nonzeros_counter = NONZEROS_MIN;
	
	double** matrix;

	srand((unsigned int)time(NULL));

	cout.setf(ios_base::fixed);

	// generate_range_of_random_real_numbers();

	// generate_range_of_random_integer_numbers();

	cout << "Podaj rozmiar macierzy rzadkiej: ";
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
			<< "macierzy nie moze byc mniejsza od zera lub rowna zeru.";

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

	pause_console();

	return 0;
}