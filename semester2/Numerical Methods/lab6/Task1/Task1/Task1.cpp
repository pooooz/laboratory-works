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
	T** table;
	T** U;
	T** L;

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
		this->L = new T * [this->N];
		this->U = new T * [this->N];

		for (int i = 0; i < this->N; i++) {
			this->table[i] = new T[M];
			this->L[i] = new T[M - 1];
			this->U[i] = new T[M - 1];
		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M; j++) {
				this->table[i][j] = 0;
			}
		}

		for (int i = 0; i < this->N; i++) {
			int j = 0;
			while (j < i) {
				this->U[i][j] = 0;
				j++;
			}
			this->U[i][i] = 1;
		}

		for (int i = this->N-1; i >= 0; i--) {
			int j = this->M - 2;
			while (j > i) {
				this->L[i][j] = 0;
				j--;
			}
		}
	}

	Matrix(const Matrix& matrix) {
		this->N = matrix.N;
		this->M = matrix.M;

		this->table = new T * [this->N];
		for (int i = 0; i < this->N; i++) {
			this->table[i] = new T[this->M];
		}

		this->L = new T * [this->N];
		for (int i = 0; i < this->N; i++) {
			this->L[i] = new T[this->M-1];
		}

		this->U = new T * [this->N];
		for (int i = 0; i < this->N; i++) {
			this->U[i] = new T[this->M-1];
		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M; j++) {
				this->table[i][j] = matrix.table[i][j];
			}
		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M-1; j++) {
				this->L[i][j] = matrix.L[i][j];
				this->U[i][j] = matrix.U[i][j];
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

	int get_M() {
		return this->M;
	}

	void display() {
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M; j++) {
				cout << setw(10) << this->table[i][j];
			}
			cout << endl;
		}
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

		cout << '\n';

		for (int i = 0; i < matrix.N; i++) {
			for (int j = 0; j < matrix.M - 1; j++) {
				os << setw(12) << matrix.U[i][j];
			}
			cout << "   |   ";
			for (int j = 0; j < matrix.M - 1; j++) {
				os << setw(12) << matrix.L[i][j];
			}
			os << '\n';

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

	// Ниже костыльно, но сырно (チルノ)
	void reverse_stroke() {
		double * x = new T[this->M - 1];
		double * y = new T[this->M - 1];

		y[0] = this->table[0][M - 1] / this->L[0][0];
		for (int i = 1; i < this->N; i++) {
			double sum = 0;
			for (int j = 0; j < i; j++)
				sum += this->L[i][j] * y[j];
			y[i] = (this->table[i][this->M - 1] - sum) / this->L[i][i];
		}

		x[this->N - 1] = y[this->N - 1];
		for (int i = this->N - 2; i >= 0; i--) {
			double sum = 0;
			for (int j = this->N - 1; j >= i + 1; j--)
				sum += x[j] * this->U[i][j];
			x[i] = y[i] - sum;
		}

		cout << "Решение системы: " << endl;
		for (int i = 0; i < this->M - 1; i++) {
			cout << "x" << i + 1 << " = " << x[i] << endl;
		}
		cout << endl;
	}

	void resolve() {
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M - 1; j++) {
				double sum = 0;
				if (i < j) {
					for (int s = 0; s <= i - 1; s++) {
						sum += this->L[i][s] * this->U[s][j];
					}
					this->U[i][j] = (this->table[i][j] - sum) / this->L[i][i];
				}
				else {
					for (int s = 0; s <= j - 1; s++) {
						sum += this->L[i][s] * this->U[s][j];
					}
					this->L[i][j] = this->table[i][j] - sum;
				}

			}
		}
		reverse_stroke();
	}
};

// Из условия входным параметром будет расширенная матрица размером N x (N + 1), 
// у которой определитель не равен нулю
int main() {
	setlocale(LC_ALL, "Russian");
	try {
		cout << "Введите количество строк матрицы N: ";
		int n;
		enter_number(n);

		cout << "Введите количество столбцов матрицы M: ";
		int m;
		enter_number(m);

		Matrix<double> matrix(n, m);
		cin >> matrix;
		matrix.resolve();
		cout << matrix;
	}
	catch (invalid_argument& error) {
		cout << error.what() << endl;
	}

	return 0;
}