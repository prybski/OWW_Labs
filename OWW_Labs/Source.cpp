#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;

const int RANDOM_NUMBERS_COUNT = 20;
const int NONZEROS_MIN = 1;

double random_double(double min, double max)
{
	return (max - min) * ((double)rand() / (double)RAND_MAX) + min;
}

int random_int(int min, int max)
{
	return rand() % ((max - min) + 1) + min;
}

double** generate_matrix(int n, int m)
{
	double** matrix = new double* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[m];

		for (int j = 0; j < m; j++)
		{
			if (i == j) matrix[i][j] = random_double((double)1, (double)2);
			else matrix[i][j] = (double)0;
		}
	}

	return matrix;
}

void print_matrix(double** matrix, int n, int m)
{
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cout << matrix[i][j] << "\t\t";

		cout << endl << endl;
	}
}

void delete_matrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++) delete[] matrix[i];

	delete[] matrix;
}

int generate_random_column_index(double* matrix_row, int m)
{
	int proper_index = random_int(0, m - 1);

	if (matrix_row[proper_index] == (double)0) return proper_index;
	else return generate_random_column_index(matrix_row, m);
}

int main()
{
	int i, j;
	double min_real, max_real, real;
	int min_scalar, max_scalar, scalar;

	int rows, columns;
	double** matrix;
	int nonzeros_max, nonzeros_counter = NONZEROS_MIN;

	srand((unsigned int)time(NULL));

	cout << "Podaj dwie liczby rzeczywiste: ";
	cin >> min_real >> max_real;

	cout << endl << "Losowe liczby rzeczywiste z zakresu: " << fixed
		<< setprecision(4) << min_real << " - " << max_real << endl;

	for (i = 0; i < RANDOM_NUMBERS_COUNT; i++)
	{
		real = random_double(min_real, max_real);

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
		scalar = random_int(min_scalar, max_scalar);

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
				= random_double((double)0, (double)1);

			nonzeros_counter++;
		}

		nonzeros_counter = NONZEROS_MIN;
	}

	print_matrix(matrix, rows, columns);

	delete_matrix(matrix, rows);

	return 0;
}