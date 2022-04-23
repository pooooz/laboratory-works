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
	int M;
	bool is_diagonal_dominance = true;
	T** table;
	T** B;
	T* g;
	T* X;

	void divide_line_by(T divider, int line) {
		for (int j = 0; j < this->M; j++) {
			this->table[line][j] /= divider;
		}
	}

	void subtract(int k, int m, T coefficient) {
		for (int j = 0; j < this->M; j++) {
			this->table[k][j] -= coefficient * this->table[m][j];
		}
	}

	void check_diagonal_dominance() {
		for (int i = 0; i < this->N; i++) {
			T sum = variables_line_absolute_sum(i) - this->table[i][i];
			if (this->table[i][i] <= fabs(sum)) {
				this->is_diagonal_dominance = false;
				throw invalid_argument("Не выполняется условие диагонального преобладания");
			}
		}
		cout << "Условие диагонального преобладания выполняется" << endl;
	}

	void build_B_and_g() {
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M - 1; j++) {
				if (i == j) {
					this->B[i][j] = 0;
				}
				else {
					this->B[i][j] = -this->table[i][j] / this->table[i][i];
				}
			}
			this->g[i] = this->table[i][M - 1] / this->table[i][i];
		}
	}

public:
	Matrix(int n, int m) {
		if (n <= 0 || m <= 0) {
			throw invalid_argument("N и M должны быть строго больше 0");
		}

		if (n < m - 1) {
			throw invalid_argument("Количество уравнений меньше, чем неизвестных переменных");
		}

		this->N = n;
		this->M = m;

		this->table = new T * [this->N];
		this->B = new T * [this->N];
		this->g = new T[this->M - 1];
		this->X = new T[this->M - 1];

		for (int i = 0; i < this->N; i++) {
			this->table[i] = new T[M];
			this->B[i] = new T[M - 1];
		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M; j++) {
				this->table[i][j] = 0;
			}
			this->g[i] = 0;
			this->X[i] = 0;
		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M - 1; j++) {
				this->B[i][j] = 0;
			}
		}
	}

	Matrix(const Matrix& matrix) {
		this->N = matrix.N;
		this->M = matrix.M;
		this->is_diagonal_dominance = matrix.is_diagonal_dominance;

		this->table = new T * [this->N];
		this->B = new T * [this->N];
		this->g = new T[this->M - 1];
		this->X = new T[this->M - 1];

		for (int i = 0; i < this->N; i++) {
			this->table[i] = new T[this->M];
			this->B[i] = new T[this->M - 1];
		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M; j++) {
				this->table[i][j] = matrix.table[i][j];
			}
			this->g[i] = matrix.g[i];
			this->X[i] = matrix.X[i];
		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M - 1; j++) {
				this->B[i][j] = matrix.B[i][j];
			}
		}
	}

	~Matrix() {
		for (int i = 0; i < this->N; i++) {
			delete[] this->table[i];
			delete[] this->B[i];

		}
		delete[] this->B;
		delete[] this->table;
		delete[] this->g;
		delete[] this->X;
	}

	T* operator [] (const int index) {
		return this->table[index];
	}

	friend ostream& operator << (ostream& os, const Matrix matrix) {
		for (int i = 0; i < matrix.N; i++) {
			for (int j = 0; j < matrix.M; j++) {
				if (j == matrix.M - 1) {
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
			for (int j = 0; j < matrix.M; j++) {
				cout << "Введите элемент (" << i << ", " << j << "): ";
				enter_number(matrix.table[i][j]);
			}
			cout << endl;
		}
		cout << "\n";
		return in;
	}

	T variables_line_absolute_sum(int line) {
		T sum = 0;
		for (int i = 0; i < this->M - 1; i++) {
			sum += fabs(this->table[line][i]);
		}
		return sum;
	}

	void display_B_and_g() {
		cout << "Матрица B:" << endl;
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M - 1; j++) {
				cout << setw(12) << this->B[i][j];
				if (j == this->M - 2) {
					cout << "|";
				}
			}
			cout << setw(12) << this->g[i];
			cout << endl;
		}
		cout << "\n";
	}

	T find_max(T* arr, int size) {
		T max = arr[0];
		for (int i = 0; i < size; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		return max;
	}

	void resolve(long double exactness) {
		check_diagonal_dominance();
		build_B_and_g();
		display_B_and_g();

		T* X = new T[this->M-1];
		T* Xi = new T[this->M-1];
		T* dif = new T[this->M - 1];
		int counter = 0;

		for (int i = 0; i < this->M - 1; i++) {
			X[i] = this->g[i];
			Xi[i] = 0;
		}

		for (int i = 0; i < this->M - 1; i++) {
			dif[i] = fabs(Xi[i] - X[i]);
		}

		while (find_max(dif, this->M - 1) > exactness) {
			for (int i = 0; i < this->M - 1; i++) {
				X[i] = Xi[i];
				Xi[i] = 0;
			}

			for (int i = 0; i < this->N; i++) {
				for (int j = 0; j < this->M - 1; j++) {
					Xi[i] += this->B[i][j] * X[j];
				}
				Xi[i] += this->g[i];
			}

			for (int i = 0; i < this->M - 1; i++) {
				dif[i] = fabs(Xi[i] - X[i]);
			}

			cout << "Номер итерации: " << counter << endl;
			for (int i = 0; i < this->M - 1; i++) {
				cout << "x[" << i << "]: " << Xi[i] << endl;
			}
			cout << endl;
			counter++;
		}

		cout << "\nРешение системы с точностью [" << exactness << "], количество итераций {" << counter - 1 << "}:" << endl;
		for (int i = 0; i < this->M - 1; i++) {
			this->X[i] = Xi[i];
			cout << "x" << i + 1 << ": " << this->X[i] << endl;
		}

	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	try {
		cout << "Введите количество строк матрицы N: ";
		int n;
		enter_number(n);

		cout << "Введите количество столбцов матрицы M: ";
		int m;
		enter_number(m);

		cout << "Введите точность: ";
		long double exactness;
		enter_number(exactness);

		cout << endl;

		Matrix<double> matrix(n, m);
		cin >> matrix;
		cout << matrix;
		matrix.resolve(exactness);
	}
	catch (invalid_argument& error) {
		cout << error.what() << endl;
	}

	return 0;
}