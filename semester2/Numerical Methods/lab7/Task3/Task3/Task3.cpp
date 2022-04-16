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

template <typename T>
class Matrix {
	int N;
	T** table;

public:
	Matrix() {
		this->N = 0;
		this->table = nullptr;
		this->inverse_matrix = nullptr;
	}

	Matrix(int n) {
		if (n <= 0) {
			throw invalid_argument("N должно быть строго больше 0");
		}

		this->N = n;
		this->table = new T * [this->N];

		for (int i = 0; i < this->N; i++) {
			this->table[i] = new T[2 * N];
		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->N; j++) {
				this->table[i][j] = 0;
			}
		}

		for (int i = 0; i < this->N; i++) {
			for (int j = this->N; j < 2 * this->N; j++) {
				this->table[i][j] = 0;
			}
			this->table[i][i + this->N] = 1;
		}
	}

	Matrix(const Matrix& matrix) {
		this->N = matrix.N;

		this->table = new T * [this->N];
		for (int i = 0; i < this->N; i++) {
			this->table[i] = new T[this->N * 2];
		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < 2 * this->N; j++) {
				this->table[i][j] = matrix.table[i][j];
			}
		}
	}

	~Matrix() {
		for (int i = 0; i < this->N; i++) {
			delete[] this->table[i];
		}

		delete[] this->table;
	}

	int get_N() {
		return this->N;
	}

	T* operator [] (const int index) {
		return this->table[index];
	}

	friend ostream& operator << (ostream& os, const Matrix matrix) {
		for (int i = 0; i < matrix.N; i++) {
			for (int j = 0; j < 2 * matrix.N; j++) {
				if (j == matrix.N) {
					os << "|";
				}
				os << setw(12) << matrix.table[i][j];
			}
			os << endl;
		}
		os << "\n";
		return os;
	}

	friend istream& operator >> (istream& in, Matrix& matrix) {
		for (int i = 0; i < matrix.N; i++) {
			for (int j = 0; j < matrix.N; j++) {
				cout << "Введите элемент (" << i << ", " << j << "): ";
				enter_number(matrix.table[i][j]);
			}
			cout << endl;
		}
		cout << "\n";
		return in;
	}

	void divide_line_by(T divider, int line) {
		for (int j = 0; j < 2 * this->N; j++) {
			this->table[line][j] /= divider;
		}
	}

	void subtract(int k, int m, T coefficient) {
		for (int j = 0; j < 2 * this->N; j++) {
			this->table[k][j] -= coefficient * this->table[m][j];
		}
	}

	T variables_line_sum(int line) {
		T sum = 0;
		for (int i = 0; i < this->N; i++) {
			sum += this->table[line][i];
		}
		return sum;
	}

	void print_inverse_matrix() {
		for (int i = 0; i < this->N; i++) {
			int counter = 0;
			if (this->table[i][i] == 0 && i != this->N - 1) {
				for (int index = this->N - 1; index > i; index--) {
					if (this->table[index][i] != 0) {
						swap(this->table[i], this->table[index]);
						cout << *this;
						counter++;
						break;
					}
				}
			}

			divide_line_by(this->table[i][i], i);
			for (int k = 0; k < this->N; k++) {
				if (i != k) {
					subtract(k, i, this->table[k][i]);
				}
			}

			cout << *this;
		}

		cout << "Обратная матрица: " << endl;
		for (int i = 0; i < this->N; i++) {
			for (int j = N; j < 2 * this->N; j++) {
				cout << setw(12) << this->table[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
};

//Из условия входным параметром будет расширенная матрица размером N x (N + 1), у которой определитель не равен нулю
int main() {
	setlocale(LC_ALL, "Russian");
	try {
		cout << "Введите количество строк матрицы N: ";
		int n;
		enter_number(n);

		Matrix<double> matrix(n);
		cin >> matrix;
		cout << matrix;
		matrix.print_inverse_matrix();
	}
	catch (invalid_argument& error) {
		cout << error.what() << endl;
	}

	return 0;
}