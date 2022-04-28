#include <iostream> 
#include <algorithm>
#include <chrono>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;

void selection_sort(int* arr, int length) {
	unsigned long int comparisons_number = 0;
	unsigned long int exchanges_number = 0;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (int startIndex = 0; startIndex < length - 1; ++startIndex) {
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex) {
			comparisons_number++;
			if (arr[currentIndex] < arr[smallestIndex]) {
				smallestIndex = currentIndex;
			}
		}
		exchanges_number += 3;
		swap(arr[startIndex], arr[smallestIndex]);
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Время выполнения: " << duration << " (миллисекунды)" << endl;
	cout << "Количество сравнений: " << comparisons_number << endl;
	cout << "Количество обменов: " << exchanges_number << endl;
}

void insertion_sort(int* arr, int length) {
	unsigned long int comparisons_number = 0;
	unsigned long int exchanges_number = 0;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (int i = 1; i < length; i++) {
		comparisons_number++;
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
			exchanges_number += 3;
			swap(arr[j - 1], arr[j]);
		}
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Время выполнения: " << duration << " (миллисекунды)" << endl;
	cout << "Количество сравнений: " << comparisons_number << endl;
	cout << "Количество обменов: " << exchanges_number << endl;
}

void bubble_sort(int* arr, int length) {
	unsigned long int comparisons_number = 0;
	unsigned long int exchanges_number = 0;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - 1; j++) { // Без оптимизации (j < length - i - 1)
			comparisons_number++;
			if (arr[j] > arr[j + 1]) {
				exchanges_number += 3;
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	
	auto duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << "Время выполнения: " << duration << " (миллисекунды)" << endl;
	cout << "Количество сравнений: " << comparisons_number << endl;
	cout << "Количество обменов: " << exchanges_number << endl;
}

void counting_sort(int* arr, int length, int max_number) {
	unsigned long int comparisons_number = 0;
	unsigned long int exchanges_number = 0;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	int* c = new int[max_number + 1];

	for (int i = 0; i < max_number + 1; i++) {
		c[i] = 0;
	}
	for (int i = 0; i < length; i++) {
		c[arr[i]] = c[arr[i]] + 1;
	}
	int i = 0;
	for (int j = 0; j < max_number + 1; j++) {
		exchanges_number++;
		while (c[j] != 0) {
			comparisons_number++;
			arr[i] = j;
			exchanges_number++;
			c[j]--;
			i++;
		}
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	auto duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Время выполнения: " << duration << " (наносекунды)" << endl;
	cout << "Количество сравнений: " << comparisons_number << endl;
	cout << "Количество обменов: " << exchanges_number << endl;
}

int main() {
	// https://neerc.ifmo.ru/wiki/index.php?title=%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B8
	setlocale(LC_ALL, "Russian");

	string string_numbers_amount;

	cout << "Введите количество чисел (1000, 10000, 100000): ";
	cin >> string_numbers_amount;

	int int_numbers_amount;
	int_numbers_amount = stoi(string_numbers_amount);

	int *array = new int[int_numbers_amount];

	try {
		if (int_numbers_amount != 1000 && int_numbers_amount != 10000 && int_numbers_amount != 100000) {
			throw invalid_argument("Некорректное значение количества чисел! Нужно выбрать из предложенных: 1000, 10000, 100000");
		}
		int max_number;

		cout << "\n***** Сортировка выбором *****" << endl << '\n';
		cout << "Сортировка выбором для неотсортированных элементов: " << endl;
		ifstream fin(string_numbers_amount + "_unsorted.txt");
		if (fin.is_open()) {
			for (int i = 0; i < int_numbers_amount; i++) {
				fin >> array[i];
			}
			fin.close();
		}
		selection_sort(array, int_numbers_amount);
		cout << '\n';

		max_number = array[int_numbers_amount - 1];

		cout << "Сортировка выбором для упорядоченных по возрастанию элементов: " << endl;
		fin.open(string_numbers_amount + "_ascending.txt");
		if (fin.is_open()) {
			for (int i = 0; i < int_numbers_amount; i++) {
				fin >> array[i];
			}
			fin.close();
		}
		selection_sort(array, int_numbers_amount);
		cout << '\n';

		cout << "Сортировка выбором для упорядоченных по убыванию элементов: " << endl;
		fin.open(string_numbers_amount + "_descending.txt");
		if (fin.is_open()) {
			for (int i = 0; i < int_numbers_amount; i++) {
				fin >> array[i];
			}
			fin.close();
		}
		selection_sort(array, int_numbers_amount);
		cout << '\n';


		cout << "\n***** Сортировка вставками *****" << endl << '\n';
		cout << "Сортировка вставками для неотсортированных элементов: " << endl;
		fin.open(string_numbers_amount + "_unsorted.txt");
		if (fin.is_open()) {
			for (int i = 0; i < int_numbers_amount; i++) {
				fin >> array[i];
			}
			fin.close();
		}
		insertion_sort(array, int_numbers_amount);
		cout << '\n';

		cout << "Сортировка вставками для упорядоченных по возрастанию элементов: " << endl;
		fin.open(string_numbers_amount + "_ascending.txt");
		if (fin.is_open()) {
			for (int i = 0; i < int_numbers_amount; i++) {
				fin >> array[i];
			}
			fin.close();
		}
		insertion_sort(array, int_numbers_amount);
		cout << '\n';

		cout << "Сортировка вставками для упорядоченных по убыванию элементов: " << endl;
		fin.open(string_numbers_amount + "_descending.txt");
		if (fin.is_open()) {
			for (int i = 0; i < int_numbers_amount; i++) {
				fin >> array[i];
			}
			fin.close();
		}
		insertion_sort(array, int_numbers_amount);
		cout << '\n';


		cout << "\n***** Сортировка пузырьком *****" << endl << '\n';
		cout << "Сортировка пузырьком для неотсортированных элементов: " << endl;
		fin.open(string_numbers_amount + "_unsorted.txt");
		if (fin.is_open()) {
			for (int i = 0; i < int_numbers_amount; i++) {
				fin >> array[i];
			}
			fin.close();
		}
		bubble_sort(array, int_numbers_amount);
		cout << '\n';

		cout << "Сортировка пузырьком для упорядоченных по возрастанию элементов: " << endl;
		fin.open(string_numbers_amount + "_ascending.txt");
		if (fin.is_open()) {
			for (int i = 0; i < int_numbers_amount; i++) {
				fin >> array[i];
			}
			fin.close();
		}
		bubble_sort(array, int_numbers_amount);
		cout << '\n';

		cout << "Сортировка пузырьком для упорядоченных по убыванию элементов: " << endl;
		fin.open(string_numbers_amount + "_descending.txt");
		if (fin.is_open()) {
			for (int i = 0; i < int_numbers_amount; i++) {
				fin >> array[i];
			}
			fin.close();
		}
		bubble_sort(array, int_numbers_amount);
		cout << '\n';


		cout << "\n***** Сортировка подсчет распределения *****" << endl << '\n';
		cout << "Сортировка подсчет распределения для неотсортированных элементов: " << endl;
		fin.open(string_numbers_amount + "_unsorted.txt");
		if (fin.is_open()) {
			for (int i = 0; i < int_numbers_amount; i++) {
				fin >> array[i];
			}
			fin.close();
		}
		counting_sort(array, int_numbers_amount, max_number);
		cout << '\n';

		cout << "Сортировка подсчет распределения для упорядоченных по возрастанию элементов: " << endl;
		fin.open(string_numbers_amount + "_ascending.txt");
		if (fin.is_open()) {
			for (int i = 0; i < int_numbers_amount; i++) {
				fin >> array[i];
			}
			fin.close();
		}
		counting_sort(array, int_numbers_amount, max_number);
		cout << '\n';

		cout << "Сортировка подсчет распределения для упорядоченных по убыванию элементов: " << endl;
		fin.open(string_numbers_amount + "_descending.txt");
		if (fin.is_open()) {
			for (int i = 0; i < int_numbers_amount; i++) {
				fin >> array[i];
			}
			fin.close();
		}
		counting_sort(array, int_numbers_amount, max_number);
		cout << '\n';
	}
	catch (invalid_argument& err) {
		cerr << "\n" << err.what() << endl;
	}

	



	return 0;
}