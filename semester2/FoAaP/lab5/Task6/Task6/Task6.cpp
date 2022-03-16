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
	}

	Matrix(int n) {
		if (n <= 0) {
			throw invalid_argument("N должно быть строго больше 0");
		}

		this->N = n;
		this->table = new T * [this->N];

		for (int i = 0; i < this->N; i++) {
			this->table[i] = new T[N];
		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->N; j++) {
				this->table[i][j] = 0;
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

	void display() {
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->N; j++) {
				cout << setw(8) << this->table[i][j];
			}
			cout << endl;
		}
	}

	Matrix pow(int n) {
		Matrix res(this->N);
		if (n < 0) {
			throw invalid_argument("Натуральные числа это 1, 2, 3, ...");
		}
		res = *this;
		for (int i = 1; i < n; i++) {
			res = res * *this;
		}
		return res;
	}

	Matrix(const Matrix& matrix) {
		this->N = matrix.N;

		this->table = new T * [this->N];
		for (int i = 0; i < this->N; i++) {
			this->table[i] = new T[this->N];

		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->N; j++) {
				this->table[i][j] = matrix.table[i][j];
			}
		}
	}

	Matrix& operator=(const Matrix& matrix) {
		if (this->N > 0) {
			for (int i = 0; i < this->N; i++) {
				delete[] this->table[i];
			}

			delete[] this->table;
		}

		this->N = matrix.N;

		this->table = new T * [this->N];
		for (int i = 0; i < this->N; i++) {
			this->table[i] = new T[this->N];

		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->N; j++) {
				this->table[i][j] = matrix.table[i][j];
			}
		}

		return *this;
	}

	T* operator [] (const int index) {
		return this->table[index];
	}

	friend ostream& operator << (ostream& os, const Matrix matrix) {
		for (int i = 0; i < matrix.N; i++) {
			for (int j = 0; j < matrix.N; j++) {
				os << setw(8) << matrix.table[i][j];
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

	friend Matrix operator * (Matrix& m1, Matrix& m2) {
		Matrix res(m1.N);
		for (int i = 0; i < res.get_N(); i++) {
			for (int j = 0; j < res.get_N(); j++) {
				for (int k = 0; k < res.get_N(); k++) {
					res.table[i][j] += m1.table[i][k] * m2.table[k][j];
				}
			}
		}
		return res;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Введите количество строк и столбцов матрицы NxN (N): ";
	int N;
	enter_number(N);

	try {
		Matrix<double> matrix1(N);
		cin >> matrix1;
		cout << "Матрица matrix1: " << endl;
		cout << matrix1;

		Matrix<double> matrix2;
		matrix2 = matrix1;
		cout << "Матрица matrix2(создана копированием matrix1): " << endl;
		cout << matrix2;
		cout << "Переопределите значение элементов матрицы matrix2:" << endl;
		cin >> matrix2;
		cout << "Новая матрица matrix2: " << endl;
		cout << matrix2;


		cout << "Произведение matrix1 * matrix2: " << endl;
		cout << matrix1 * matrix2;

		cout << "Введите натуральную степень n: ";
		int n;
		enter_number(n);

		cout << "Матрица matrix1 в степени " << n << endl;
		cout << matrix1.pow(n);
	}
	catch (invalid_argument& error) {
		cout << error.what() << endl;
	}

	return 0;
}