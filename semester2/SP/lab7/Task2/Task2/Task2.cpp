#include <iostream>
#include <iomanip>

using namespace std;

template <typename n>
void enter_number(n& x) {
	while (!(cin >> x) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

class ArrayOfLargestModules {
	int n = 0;
	int m = 0;
	int** arr = nullptr;
	int* max_elements = nullptr;

	void print_info() {
		cout << "Ваш массив: " << setw(21) << " max" << endl;
		for (int i = 0; i < this->n; i++) {
			for (int j = 0; j < this->m; j++) {
				cout << setw(8) << this->arr[i][j];
			}
			cout << '|';
			cout << setw(8) << this->max_elements[i];
			cout << '\n';
		}
		cout << endl;
	}

	void find_max_elements() {
		for (int i = 0; i < this->n; i++) {
			for (int j = 0; j < this->m; j++) {
				if (abs(this->arr[i][j]) > abs(this->max_elements[i])) {
					this->max_elements[i] = this->arr[i][j];
				}
			}
		}
	}

public:
	ArrayOfLargestModules(int n, int m) {
		try {
			if (n < 1 || m < 1) {
				throw invalid_argument("\nКоличество строк и столбцов должно быть не меньше, чем 1");
			}

			this->n = n;
			this->m = m;

			this->max_elements = new int[n];
			this->arr = new int* [n];
			for (int i = 0; i < n; i++) {
				this->arr[i] = new int[m];
				this->max_elements[i] = 0;
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << "Введите элемент c идексом [" << i << ',' << j << "] массива: ";
					enter_number(this->arr[i][j]);
				}
				cout << '\n';
			}

			this->find_max_elements();
			this->print_info();

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
	
	ArrayOfLargestModules resolve(n, m);

	return 0;
}