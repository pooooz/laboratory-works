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
	int** identity_matrix;
	T** inverse_matrix;

	T** U;
	T** L;

public:
	Matrix(int n) {
		if (n <= 0) {
			throw invalid_argument("N должно быть строго больше 0");
		}

		this->N = n;
		this->table = new T * [this->N];
		this->identity_matrix = new int * [this->N];
		this->inverse_matrix = new T * [this->N];


		this->L = new T * [this->N];
		this->U = new T * [this->N];

		for (int i = 0; i < this->N; i++) {
			this->table[i] = new T[N];
			this->identity_matrix[i] = new int[this->N];
			this->inverse_matrix[i] = new T[this->N];

			this->L[i] = new T[this->N];
			this->U[i] = new T[this->N];
		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->N; j++) {
				this->table[i][j] = 0;
				this->identity_matrix[i][j] = 0;
			}
			this->identity_matrix[i][i] = 1;
		}

		for (int i = 0; i < this->N; i++) {
			int j = 0;
			while (j < i) {
				this->U[i][j] = 0;
				j++;
			}
			this->U[i][i] = 1;
		}

		for (int i = this->N - 1; i >= 0; i--) {
			int j = this->N - 1;
			while (j > i) {
				this->L[i][j] = 0;
				j--;
			}
		}
	}

	Matrix(const Matrix& matrix) {
		this->N = matrix.N;

		this->table = new T * [this->N];
		for (int i = 0; i < this->N; i++) {
			this->table[i] = new T[this->N];
		}

		this->identity_matrix = new int * [this->N];
		for (int i = 0; i < this->N; i++) {
			this->identity_matrix[i] = new int[this->N];
		}

		this->inverse_matrix = new T * [this->N];
		for (int i = 0; i < this->N; i++) {
			this->inverse_matrix[i] = new T[this->N];
		}


		this->L = new T * [this->N];
		for (int i = 0; i < this->N; i++) {
			this->L[i] = new T[this->N];
		}

		this->U = new T * [this->N];
		for (int i = 0; i < this->N; i++) {
			this->U[i] = new T[this->N];
		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->N; j++) {
				this->table[i][j] = matrix.table[i][j];
				this->identity_matrix[i][j] = matrix.identity_matrix[i][j];
				this->inverse_matrix[i][j] = matrix.inverse_matrix[i][j];

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

	void print_LU() {
		cout << "LU-разложение: " << endl;
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->N; j++) {
				T sum = 0;
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

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->N; j++) {
				cout << setw(12) << this->L[i][j];
			}
			cout << "   |   ";
			for (int j = 0; j < this->N; j++) {
				cout << setw(12) << this->U[i][j];
			}
			cout << '\n';

		}
		cout << "\n";
	}

	void print_inverse_matrix() {
		for (int k = 0; k < this->N; k++) {
			double* x = new T[this->N];
			double* y = new T[this->N];

			y[0] = this->identity_matrix[0][k] / this->L[0][0];
			for (int i = 1; i < this->N; i++) {
				double sum = 0;
				for (int j = 0; j < i; j++)
					sum += this->L[i][j] * y[j];
				y[i] = (this->identity_matrix[i][k] - sum) / this->L[i][i];
			}

			cout << "Вектор Y" << k + 1 << ": " << endl;
			for (int i = 0; i < this->N; i++) {
				cout << "y" << k + 1 << i + 1 << ": " << y[i] << endl;
			}
			cout << endl;

			for (int k = this->N - 1; k >= 0; k--) {
				x[k] = y[k];
				for (int i = 0; i < k; i++)
					y[i] = y[i] - this->U[i][k] * x[k];
			}

			for (int i = 0; i < this->N; i++) {
				this->inverse_matrix[i][k] = x[i];
			}
		}

		cout << "Обратная матрица: " << endl;
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->N; j++) {
				cout << setw(12) << this->inverse_matrix[i][j];
			}
			cout << endl;
		}

		cout << '\n';
	}

	T* operator [] (const int index) {
		return this->table[index];
	}

	friend ostream& operator << (ostream& os, const Matrix matrix) {
		cout << "Исходная матрица: " << endl;
		for (int i = 0; i < matrix.N; i++) {
			for (int j = 0; j < matrix.N; j++) {
				os << setw(12) << matrix.table[i][j];
			}
			os << endl;
		}

		cout << '\n';

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
};

// Из условия входным параметром является расширенная матрица размером N x N, 
int main() {
	setlocale(LC_ALL, "Russian");
	try {
		cout << "Введите количество строк и столбцов матрицы N: ";
		int n;
		enter_number(n);

		Matrix<double> matrix(n);
		cin >> matrix;

		cout << matrix;

		matrix.print_LU();

		matrix.print_inverse_matrix();
	}
	catch (invalid_argument& error) {
		cout << error.what() << endl;
	}

	return 0;
}