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

public:
	Matrix() {
		this->N = 0;
		this->M = 0;
		this->table = nullptr;
	}

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

		for (int i = 0; i < this->N; i++) {
			this->table[i] = new T[M];
		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M; j++) {
				this->table[i][j] = 0;
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

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M; j++) {
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

	T variables_line_sum(int line) {
		T sum = 0;
		for (int i = 0; i < this->M - 1; i++) {
			sum += this->table[line][i];
		}
		return sum;
	}

	// Ниже костыльно, но сырно
	void straight_stroke() {
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
	}

	void reverse_stroke() {
		T* x = new T[M - 1];
		for (int i = 0; i < M - 1; i++) {
			x[i] = this->table[i][M - 1];
			cout << "x" << i + 1 << " = " << x[i] << endl;
		}

	}

	void resolve() {
		straight_stroke();
		reverse_stroke();
	}
};

//Из условия входным параметром будет расширенная матрица размером N x (N + 1), у которой определитель не равен нулю
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
		cout << matrix;
		matrix.resolve();
	}
	catch (invalid_argument& error) {
		cout << error.what() << endl;
	}

	return 0;
}