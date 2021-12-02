#include "Arrays.h"
#include <iostream>
#include <iomanip>

using namespace std;

void enterNumber(long double& n) {
	while (!(cin >> n) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

void initializeArray(long double** arrayPtr, size_t n, size_t m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "Введите элемент " << i << " , " << j << " : ";
			enterNumber(arrayPtr[i][j]);
		}
	}
}

void initializeArray_r(long double** arrayPtr, size_t n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arrayPtr[i][j] = 10 + rand() % 90;
		}
	}
}

void displayArray(long double** arrayPtr, size_t n, size_t m) {
	cout << "\nДвумерный массив: \n" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(10) << arrayPtr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void deleteArray(long double** arrayPtr, size_t n, size_t m) {
	for (int i = 0; i < n; i++) {
		delete[]arrayPtr[i];
	}
	delete[]arrayPtr;
}

bool checkZeroes(long double** arrayPtr, double n, double m, int i) {
	for (int j = 0; j < m; j++) {
		if (arrayPtr[i][j] == 0) {
			cout << "В строке " << i + 1 << " находятся нули" << endl;
			return false;
		}

	}
	return true;
}

long double countProduct(long double** arrayPtr, size_t n, size_t m) {
	long double product = 1;

	for (int i = 0; i < n; i++) {
		if (checkZeroes(arrayPtr, n, m, i)) {
			for (int j = 0; j < m; j++) {
				product *= arrayPtr[i][j];
			}
		}
	}
	return product;
}

void shiftArray(long double** arrayPtr, size_t n) {
	for (int k = 0; k < n - 1; k++) {
		long double temp = arrayPtr[k][k];

		int i = k;
		int j = k;

		while (j < n - 1 - k) {
			arrayPtr[i][j] = arrayPtr[i][j + 1];
			j++;
		}
		while (i < n - 1 - k) {
			arrayPtr[i][j] = arrayPtr[i + 1][j];
			i++;
		}
		while (j > 0 + k) {
			arrayPtr[i][j] = arrayPtr[i][j - 1];
			j--;
		}
		while (i > 1 + k) {
			arrayPtr[i][j] = arrayPtr[i - 1][j];
			i--;
		}
		if (2 * k + 1 < n) {
			arrayPtr[k + 1][k] = temp;
		}
	}
}