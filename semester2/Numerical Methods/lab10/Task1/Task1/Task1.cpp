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

	Matrix(long double** table, int n, int m) {
		this->N = n;
		this->M = m;
		this->table = new T * [this->N];
		for (int i = 0; i < this->N; i++) {
			this->table[i] = new T[this->M];
		}

		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M; j++) {
				this->table[i][j] = table[i][j];
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

			T sum = variables_line_sum(i);
			if (this->table[i][i] == 0 && sum == 0) {
				break;
			}
			else if (this->table[i][i] == 0 && sum != 0) {
				divide_line_by(this->table[i][i + 1], i);
				for (int k = i + 1; k < this->N - counter; k++) {
					subtract(k, i, this->table[k][i + 1]);
				}
			}
			else if (this->table[i][i] != 0) {
				divide_line_by(this->table[i][i], i);
				for (int k = i + 1; k < this->N - counter; k++) {
					subtract(k, i, this->table[k][i]);
				}
			}
			cout << *this;
		}
	}

	void solution_verification() {
		bool no_solutions = false;
		T diagonal_sum = 0;

		int min_variables_row_count = this->M - 1;
		for (int i = 0; i < this->N; i++) {
			T sum = variables_line_sum(i);

			if (sum == 0 && this->table[i][this->M - 1] != 0) {
				throw invalid_argument("Система не имеет решений");
			}
		}

		for (int i = 0; i < this->N; i++) {
			if (this->table[i][i] == 0) {
				throw invalid_argument("Система имеет бесконечное множество решений");
			}
		}
	}

	T* reverse_stroke() {
		T* x = new T[this->M - 1];
		T* y = new T[this->M - 1];

		for (int i = 0; i < this->M - 1; i++) {
			y[i] = this->table[i][this->M - 1];
		}
		cout << "\n";

		for (int k = this->M - 2; k >= 0; k--) {
			x[k] = y[k];
			for (int i = 0; i < k; i++)
				y[i] = y[i] - this->table[i][k] * x[k];
		}

		cout << "Решение системы: " << endl;
		for (int i = 0; i < this->M - 1; i++) {
			cout << "k" << i + 1 << " = " << x[i] << endl;
		}

		return x;
	}

	T* resolve() {
		straight_stroke();
		solution_verification();
		T* result = reverse_stroke();
		return result;
	}
};

// Метод наименьших квадратов
long double sum_powers_x(double x[], int power, int size) {
	long double result = 0;
	for (int i = 0; i < size; i++) {
		result += pow(x[i], power);
	}
	return result;
}

long double sum_powers_xy(double x[], double y[], int power, int size) {
	long double result = 0;
	for (int i = 0; i < size; i++) {
		result += pow(x[i], power) * (y[i]);
	}
	return result;
}

void print_equation(long double* coefficients, int k) {
	cout << '\n';
	cout << "Искомое уравнение " << k << " степени: ";
	cout << "f(x) = ";
	int power = k;

	if (k != 1) {
		cout << coefficients[0] << " * x^" << power << ' ';
	}
	
	power--;
	for (int i = 1; i < k - 1; i++) {
		if (coefficients[i] >= 0) {
			cout << "+ ";
		}
		else {
			cout << "- ";
		}
		cout << fabs(coefficients[i]) << " * x^" << power << ' ';
		power--;
	}

	if (coefficients[k - 1] >= 0) {
		cout << "+ ";
	}
	else {
		cout << "- ";
	}
	cout << fabs(coefficients[k - 1]) << " * x" << ' ';

	if (coefficients[k] >= 0) {
		cout << "+ ";
	}
	else {
		cout << "- ";
	}
	cout << fabs(coefficients[k]) << endl;
}

long double function_value(double x, long double* coefficients, int k) {
	long double function_value = 0;
	int power = k;
	for (int i = 0; i < k; i++) {
		function_value += coefficients[i] * pow(x, power);
		power--;
	}
	function_value += coefficients[k];

	return function_value;
}

long double sum_of_squared_deviation(double x[], double y[], long double* coefficients, int k, int size) {
	long double sum_of_squared_deviation = 0;
	for (int i = 0; i < size; i++) {
		long double temp = function_value(x[i], coefficients, k) - y[i];
		sum_of_squared_deviation += temp * temp;
	}
	return sum_of_squared_deviation;
}

void least_square_method(double x[], double y[], int k, int size) {
	cout << "\n**********Поиск аппроксимирующей функции " << k << " степени**********" << endl;
	long double** sum_matrix = new long double*[k + 1];
	for (int i = 0; i < k + 1; i++) {
		sum_matrix[i] = new long double[k + 2];
	}

	int counter = 1;
	int power_of_x = k * 2;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k + 1; j++) {
			sum_matrix[i][j] = sum_powers_x(x, power_of_x, size);
			power_of_x--;
		}
		power_of_x = k * 2 - counter;
		counter++;
	}

	int power_of_xy = k;
	for (int i = 0; i < k + 1; i++) {
		sum_matrix[i][k + 1] = sum_powers_xy(x, y, power_of_xy, size);
		power_of_xy--;
	}

	int last_row_power = k;
	for (int i = 0; i < k + 1; i++) {
		sum_matrix[k][i] = sum_powers_x(x, last_row_power, size);
		last_row_power--;
	}
	sum_matrix[k][k + 1] = sum_powers_xy(x, y, 0, size);

	cout << '\n';
	for (int i = 0; i < k + 1; i++) {
		for (int j = 0; j < k + 2; j++) {
			if (j == k + 1) {
				cout << "|";
			}
			cout << setw(12) << sum_matrix[i][j];
		}
		cout << '\n';
	}
	cout << "\n";

	Matrix<long double> m(sum_matrix, k + 1, k + 2);
	long double* coefficients =  m.resolve();
	print_equation(coefficients, k);

	cout << "Сумма квадратов отклонений: ||r|| = " << sum_of_squared_deviation(x, y, coefficients, k, size) << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	try {
		double x[] = { -3, -2, 1, 0, 1, 2 };
		double y[] = { -1.4, -4.3, -5.2, -4.1, -1.1, 4.2 };

		least_square_method(x, y, 1, size(x));
		least_square_method(x, y, 2, size(x));
		least_square_method(x, y, 3, size(x));
	}
	catch (invalid_argument& error) {
		cout << error.what() << endl;
	}

	return 0;
}