#include <iostream>

using namespace std;

template <typename n>
void enter_number(n& x) {
	while (!(cin >> x) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

class TwoDimensionalArray {
	int** arr = nullptr;
	int n = 0;
	int m = 0;

	void print_array() {
		cout << "Ваш массив: " << endl;
		for (int i = 0; i < this->n; i++) {
			for (int j = 0; j < this->m; j++) {
				cout << this->arr[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << endl;
	}

	void print_indexes_of_first_zero() {
		bool isZero = false;
		for (int i = 0; i < this->n && !isZero; i++) {
			for (int j = 0; j < this->m && !isZero; j++) {
				if (this->arr[i][j] == 0) {
					cout << "Координаты первого нулевого элемента: [" << i << ',' << j << ']' << endl;
					isZero = true;
				}
			}
		}
		if (!isZero) {
			cout << "В двумерном массиве нет нулей" << endl;
		}
	}

	void print_indexes_of_last_event() {
		bool isEven = false;
		for (int i = this->n - 1; i >= 0 && !isEven; i--) {
			for (int j = this->m - 1; j >= 0 && !isEven; j--) {
				if (this->arr[i][j] % 2 == 0) {
					cout << "Координаты последнего чётного элемента: [" << i << ',' << j << ']' << endl;
					isEven = true;
				}
			}
		}
		if (!isEven) {
			cout << "Массив состоит из нечётных элементов" << endl;
		}
	}

public:
	TwoDimensionalArray(int n, int m) {
		try {
			if (n < 1 || m < 1) {
				throw invalid_argument("\nКоличество строк и столбцов должно быть не меньше, чем 1");
			}

			this->n = n;
			this->m = m;

			this->arr = new int*[n];
			for (int i = 0; i < n; i++) {
				this->arr[i] = new int[m];
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << "Введите элемент c идексом [" << i << ',' << j << "] массива: ";
					enter_number(this->arr[i][j]);
				}
				cout << '\n';
			}

			this->print_array();
			this->print_indexes_of_first_zero();
			this->print_indexes_of_last_event();
		}
		catch (invalid_argument& error) {
			cerr << error.what() << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите количество подмассивов (строк) двумерного массива: ";
	enter_number(n);

	int m;
	cout << "Введите количество элементов (столбцов) каждого подмассива двумерного массива: ";
	enter_number(m);

	TwoDimensionalArray resolve(n, m);

	return 0;
}