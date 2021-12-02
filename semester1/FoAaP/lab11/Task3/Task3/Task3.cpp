#include <iostream>
#include "Arrays.h"
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	char* n = new char[255];
	char* m = new char[255];


	cout << "Укажите размерность массива n x m" << endl;
	cout << "Введите количество массивов n: ";
	cin >> n;
	cout << "Введите количество их элементов m: ";
	cin >> m;

	double k = atof(n);
	double z = atof(m);

	if (n == to_string((int)atof(n)) && m == to_string((int)atof(m)) && k > 0 && z > 0 && k - int(k) == 0 && z - int(z) == 0) {
		long double** arrayPtr = new long double* [k];
		for (int i = 0; i < k; i++) {
			arrayPtr[i] = new long double[z];
		}

		initializeArray(arrayPtr, k, z);

		displayArray(arrayPtr, k, z);

		cout << "Исходное произведение: " << countProduct(arrayPtr, k, z) << "\n" << endl;

		deleteArray(arrayPtr, k, z);

	}
	else {
		cout << "Некорректный ввод\n" << endl;
	}


	cout << "--------------------------------------------------" << endl;

	char* b = new char[255];

	cout << "Укажите размерность массива z x z" << endl;
	cout << "Введите z: ";
	cin >> b;
	
	double r = atof(b);


	if (b == to_string((int)atof(b)) && r > 0 && r - int(r) == 0) {
		long double** arrayPtr = new long double* [r];
		for (int i = 0; i < r; i++) {
			arrayPtr[i] = new long double[r];
		}

		initializeArray_r(arrayPtr, r);
		cout << "Исходный массив: \n" << endl;
		displayArray(arrayPtr, r, r);
		shiftArray(arrayPtr, r);
		cout << "Массив со сдвигом: \n" << endl;
		displayArray(arrayPtr, r, r);

	}
	else {
		cout << "Некорректный ввод!!!" << endl;
	}

	system("pause");
	return 0;
}
