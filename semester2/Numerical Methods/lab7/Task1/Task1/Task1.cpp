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
	T determinant = 1;
	T** table;
	T** U;
	T** L;

public:
	Matrix(int n, int m) {
		if (n <= 0) {
			throw invalid_argument("N должно быть строго больше 0");
		}

		this->N = n;
		this->table = new T * [this->N];
		this->L = new T * [this->N];
		this->U = new T * [this->N];

		for (int i = 0; i < this->N; i++) {
			this->table[i] = new T[N];
			this->L[i] = new T[N];
			this->U[i] = new T[N];
		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->N; j++) {
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
		this->determinant = matrix.determinant;

		this->table = new T * [this->N];
		for (int i = 0; i < this->N; i++) {
			this->table[i] = new T[this->N];
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

	T get_determinant() {
		return this->determinant;
	}

	// Ниже костыльно, но сырно (チルノ)
	void print_LU() {
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
			this->determinant *= this->L[i][i];
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


	T* operator [] (const int index) {
		return this->table[index];
	}

	friend ostream& operator << (ostream& os, const Matrix matrix) {
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

		Matrix<double> matrix(n, n);
		cin >> matrix;
		cout << matrix;
		matrix.print_LU();
		cout << "Определитель исходной матрицы: " << matrix.get_determinant() << endl;
	}
	catch (invalid_argument& error) {
		cout << error.what() << endl;
	}

	return 0;
}