#include <iostream>
#include <string>
using namespace std;

void initializeArray(long double* arrayPtr, double array_size) {
	for (int i = 0; i < array_size; i++) {
		cout << "������� " << i + 1 << " ������� �������: ";
		cin >> arrayPtr[i];
	}
}

void displayArray(long double* arrayPtr, double array_size) {
	cout << "[";
	for (int i = 0; i < array_size; i++) {
		cout << arrayPtr[i] << " ";
	}
	cout << "]\n" << endl;
}

void insSort(long double* arrayPtr, double array_size) {
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

int main() {
	setlocale(LC_ALL, "Russian");

	char* array_size = new char[255];
	cout << "������� ������ �������: ";
	cin >> array_size;
	cout << endl;

	double k = atof(array_size);


	if (array_size == to_string((int)atof(array_size)) && k >= 1 && k - int(k) == 0) {

		long double* Array = new long double[k];

		initializeArray(Array, k);

		cout << "\n�������� ������: ";
		displayArray(Array, k);

		insSort(Array, k);

		cout << "\n��������������� ������: ";
		displayArray(Array, k);


		long double key;
		cout << "������� ������� �������: ";
		cin >> key;
		cout << endl;

		if (checkEntry(Array, k, key)) {
			cout << "������� ������� � ������������� ������� ����� ������: " << binarySearch(Array, k, key) << endl;
			cout << "��� �������� " << binarySearch(Array, k, key) + 1 << " ��������� �������������� �������\n" << endl;
		}
		else {
			cout << "������ �� �������� ��������� �������\n" << endl;
		}
		delete[]Array;
	}
	else {
		cout << "������������ ����!!!" << endl;
	}
	system("pause");
	return 0;
}