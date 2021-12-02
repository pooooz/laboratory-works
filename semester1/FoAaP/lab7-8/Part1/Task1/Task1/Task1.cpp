#include <iostream>
#include <string>
using namespace std;

void initializeArray(long double* arrayPtr, long double* arrayPtr_copy, double array_size) {
	for (int i = 0; i < array_size; i++) {
		cout << "Введите " << i + 1 << " элемент массива: ";
		cin >> arrayPtr[i];
		arrayPtr_copy[i] = arrayPtr[i];
	}
}

void displayArray(long double* arrayPtr, double array_size) {
	cout << "[ ";
	for (int i = 0; i < array_size; i++) {
		cout << arrayPtr[i] << " ";
	}
	cout << "]\n" << endl;
}

void deleteArray(long double* arrayPtr) {
	delete[]arrayPtr;
}

void insSort_ascending(long double* arrayPtr, double array_size) {
	long double temp;
	int index_of_previous;
	for (int i = 1; i < array_size; i++) {
		temp = arrayPtr[i];
		index_of_previous = i - 1;
		while (index_of_previous >= 0 && arrayPtr[index_of_previous] > temp) {
			arrayPtr[index_of_previous + 1] = arrayPtr[index_of_previous];
			arrayPtr[index_of_previous] = temp;
			index_of_previous--;
		}
	}
}

void insSort_descending(long double* arrayPtr, double array_size) {
	long double temp;
	int index_of_previous;
	for (int i = 1; i < array_size; i++) {
		temp = arrayPtr[i];
		index_of_previous = i - 1;
		while (index_of_previous >= 0 && arrayPtr[index_of_previous] < temp) {
			arrayPtr[index_of_previous + 1] = arrayPtr[index_of_previous];
			arrayPtr[index_of_previous] = temp;
			index_of_previous--;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	char* array_size = new char[255];
	cout << "Введите размер массива: ";
	cin >> array_size;

	double k = atof(array_size);

	if (array_size == to_string((int)atof(array_size)) && k >= 1 && k - int(k) == 0) {

		long double* Array = new long double[k];
		long double* Array_copy = new long double[k];

		initializeArray(Array, Array_copy, k);

		cout << "\nИсходный массив: ";
		displayArray(Array, k);

		insSort_ascending(Array, k);
		insSort_descending(Array_copy, k);

		cout << "Отсортированный по возрастанию массив: ";
		displayArray(Array, k);

		cout << "Отсортированный по убванию массив: ";
		displayArray(Array_copy, k);

		deleteArray(Array);
		deleteArray(Array_copy);


	}
	else {
		cout << "Некорректный ввод" << endl;
	}


	system("pause");
	return 0;
}