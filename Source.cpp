#include <time.h>
#include <iostream>
#include <iomanip>

#include "Random.h"
#include "Matrix.h"
#include "Utils.h"

using namespace std;

int main()
{
	int i, j;
	int rows, columns;
	int nonzeros;
	
	double** rare_matrix;

	srand((unsigned int)time(NULL));

	cout.setf(ios_base::fixed);

	cout << "Podaj rozmiar macierzy rzadkiej: ";
	cin >> rows >> columns;

	cout << "Podaj ilosc niezerowych elementow w wierszu macierzy: ";
	cin >> nonzeros;

	if (nonzeros >= columns)
	{
		cout << endl << "Ilosc niezerowych elementow w wierszu macierzy "
			<< "nie moze byc wieksza od liczby jej kolumn lub rowna "
			<< "liczbie jej kolumn.";

		return -1;
	}

	if (nonzeros <= 0)
	{
		cout << endl << "Ilosc niezerowych elementow w wierszu "
			<< "macierzy nie moze byc mniejsza od zera lub rowna zeru.";

		return -10;
	}

	rare_matrix = generate_rare_matrix(
		generate_matrix(rows, columns),
		rows,
		columns,
		nonzeros
	);

	print_matrix(rare_matrix, rows, columns);

	delete_matrix(rare_matrix, rows);

	pause_console();

	return 0;
}