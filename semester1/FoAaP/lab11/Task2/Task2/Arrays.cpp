#include "Arrays.h"
#include <iostream>

using namespace std;

void enterNumber(long double& n) {
	while (!(cin >> n) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

void initializeArray(long double* arrayPtr, double array_size) {
	for (int i = 0; i < array_size; i++) {
		cout << "Введите " << i + 1 << " элемент массива: ";
		enterNumber(arrayPtr[i]);
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

bool checkEntry(long double* arrayPtr, double array_size, long double entry) {
	bool is_entry = false;
	for (int i = 0; i < array_size; i++) {
		if (arrayPtr[i] == entry) {
			is_entry = true;
		}
	}
	return is_entry;
}

int binarySearch(long double* Array, double array_size, double key) {
	int left = 0;
	int right = array_size - 1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (key < Array[mid]) {
			right = mid - 1;
		}
		else if (key > Array[mid]) {
			left = mid + 1;
		}
		else {
			return mid;
		}

	}
}