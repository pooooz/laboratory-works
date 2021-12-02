#include "Arrays.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	char* array_size = new char[255];
	cout << "Введите размер массива: ";
	cin >> array_size;

	double k = atof(array_size);

	if (array_size == to_string((int)atof(array_size)) && k >= 1 && k - int(k) == 0) {

		long double* Array = new long double[k];

		initializeArray(Array, k);

		cout << "\nИсходный массив: ";
		displayArray(Array, k);

		insSort_ascending(Array, k);
		insSort_descending(Array, k);

		cout << "Отсортированный по возрастанию массив: ";
		displayArray(Array, k);

		cout << "Отсортированный по убванию массив: ";
		displayArray(Array, k);

		deleteArray(Array);


	}
	else {
		cout << "Некорректный ввод" << endl;
	}


	cout << "\n --------------------------------------------------------------" << endl;

	char* array_size_2 = new char[255];
	cout << "Введите размер массива: ";
	cin >> array_size_2;
	cout << endl;
	double c = atof(array_size_2);

	if (array_size_2 == to_string((int)atof(array_size_2)) && atof(array_size_2) >= 1 && atof(array_size_2) - int(atof(array_size_2)) == 0) {

		long double* Array2 = new long double[c];

		initializeArray(Array2, c);

		cout << "\nИсходный массив: ";
		displayArray(Array2, c);

		insSort_ascending(Array2, c);
		cout << "\nОтсортированный массив: ";
		displayArray(Array2, c);


		long double key;
		cout << "Введите искомый элемент: ";
		cin >> key;
		cout << endl;

		if (checkEntry(Array2, k, key)) {
			cout << "Искомый элемент в упорядоченном массиве имеет индекс: " << binarySearch(Array2, k, key) << endl;
			cout << "Или является " << binarySearch(Array2, k, key) + 1 << " элементом упорядоченного массива\n" << endl;
		}
		else {
			cout << "Массив не содержит указанный элемент\n" << endl;
		}
		delete[]Array2;
	}
	else {
		cout << "Некорректный ввод!!!" << endl;
	}
	system("pause");
	return 0;
}
