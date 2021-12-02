#include <iostream>
#include <iomanip>
#include <string>
#include <typeinfo>
using namespace std;


void initializeArray(long double** arrayPtr, size_t n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arrayPtr[i][j] = 10 + rand() % 90;
		}
	}
}

void displayArray(long double** arrayPtr, size_t n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(10) << arrayPtr[i][j];
		}
		cout << "\n" << endl;
	}
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

int main() {
	setlocale(LC_ALL, "Russian");

	char* n = new char[255];

	cout << "Введите размерность массива n x n" << endl;
	cout << "Введите n: ";
	cin >> n;

	double k = atof(n);

	if (n == to_string((int)atof(n)) && k > 0 && k - int(k) == 0) {
		long double** arrayPtr = new long double* [k];
		for (int i = 0; i < k; i++) {
			arrayPtr[i] = new long double[k];
		}

		initializeArray(arrayPtr, k);
		cout << "Исходный массив: \n" << endl;
		displayArray(arrayPtr, k);
		shiftArray(arrayPtr, k);
		cout << "Массив со сдвигом: \n" << endl;
		displayArray(arrayPtr, k);

	}
	else {
		cout << "Некорректный ввод!!!" << endl;
	}
	

	system("pause");
	return 0;
}