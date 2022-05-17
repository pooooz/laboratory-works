#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

double function_6(double x) {
	return 3 * x - pow(M_E, x);
}

int factorial(int n) {
	int factorial = 1;

	for (int i = 1; i <= n; ++i) {
		factorial *= i;
	}
	return factorial;
}

// Презентационная функция для интерполяционного многочлена в форме Лагранжа
void print_lagrange_polynomial(vector<double> x, vector<double> y) {
	vector<string> polynomial;
	int size = x.size();
	for (int i = 0; i < size; i++) {
		if ((y[i]) < 0) {
			polynomial.push_back(" - ");
		}
		polynomial.push_back(to_string(fabs(y[i])) + "*");
		for (int j = 0; j < size; j++) {
			if (i != j) {
				polynomial.push_back("((x-" + to_string(x[j]).erase(5) 
					+ ") / (" + to_string(x[i]).erase(5) + "-" + to_string(x[j]).erase(5) + "))");
				if (i != size - 1) {
					if (j != size - 1)
						polynomial.push_back(" * ");
				}
				else {
					if (j != size - 2)
						polynomial.push_back(" * ");
				}
			}
		}
		if (i != size - 1) {
			if (y[i + 1] >= 0) {
				polynomial.push_back(" + ");
			}
		}
	}

	cout << "\nМногочлен в форме Лагранжа: Ln(x) = ";
	for (auto iter = polynomial.begin(); iter != polynomial.end(); iter++) {
		cout << *iter;
	}
	cout << endl;
}

double lagrange_polynomial(double xi, vector<double> x, vector<double> y) {
	int size = x.size();
	double sum = 0;
	for (int i = 0; i < size; i++) {
		double temp = 1;
		for (int j = 0; j < size; j++) {
			if (i != j) temp *= (xi - x[j]) / (x[i] - x[j]);
		}
		sum += y[i] * temp;
	}
	return sum;
}

// Презентационная функция для интерполяционного многочлена в форме Ньютона
void print_newton_polynomial(int n, vector<double> x, vector<double> y) {
	vector<string> polynomial;
	polynomial.push_back(to_string(y[0]));
	for (int i = 1; i <= n; ++i) {
		string F_str;
		for (int j = 0; j <= i; ++j) {
			string den_str;
			for (int k = 0; k <= i; ++k)
				if (k != j) {
					den_str += "/(" + to_string(x[j]).erase(5) + " - " + to_string(x[k]).erase(5) + ")";
				}
			if (j != 0) {
				y[j] >= 0 ? F_str += " + " : F_str += " - ";
			}
			F_str += to_string(fabs(y[j])) + den_str;
		}

		for (int k = 0; k < i; ++k) {
			if (k == 0) {
				F_str += ")";
			}
			F_str += " * (x - " + to_string(x[k]).erase(5) + ")";
		}

		polynomial.push_back(" + ((" + F_str + ")");
	}

	cout << "\nМногочлен в форме Ньютона: Nn(x) = ";
	for (auto iter = polynomial.begin(); iter != polynomial.end(); iter++) {
		cout << *iter;
	}
	cout << endl;
}
double newton_polynomial(double xi, int n, vector<double> x, vector<double> y) {
	double sum = y[0];
	for (int i = 1; i <= n; ++i) {
		double F = 0;
		for (int j = 0; j <= i; ++j) {
			double den = 1;
			for (int k = 0; k <= i; ++k)
				if (k != j) {
					den *= (x[j] - x[k]);
				}
			F += y[j] / den;
		}

		for (int k = 0; k < i; ++k) {
			F *= (xi - x[k]);
		}

		sum += F;
	}
	return sum;
}

void error_estimate(double error, int power, double point, vector<double> x) {
	cout << "Оценка погрешности: ";
	double analytical_error;
	if (power >= 1) {
		analytical_error = pow(M_E, x[x.size() - 1]) / factorial(power + 1);
		for (auto iter = x.begin(); iter != x.end(); iter++) {
			analytical_error *= fabs(point - *iter);
		}
		// погрешность (error) будет всегда меньше или равной оценке, если полагаться на теорию
		if (error <= analytical_error) { // Могу быть уверенным в себе ;)
			cout << error << " <= " << analytical_error << " - верно" << endl;
		}
	}
	else { // При power == 0
		analytical_error = fabs(3 - pow(M_E, x[x.size() - 1])) / factorial(power + 1);
		for (auto iter = x.begin(); iter != x.end(); iter++) {
			analytical_error *= fabs(point - *iter);
		}
		if (error <= analytical_error) {
			cout << error << " <= " << analytical_error << " - верно" << endl;
		}
	}
}

template <class T>
void print_vector(vector<T> vector) {
	for (auto iter = vector.begin(); iter != vector.end(); iter++) {
		cout << setw(10) << *iter;
		cout << '|';
	}
	cout << endl;
}

vector<double> generate_gap(double a, double b, double h) {
	vector<double> x;
	for (double i = a; i <= b; i += h) {
		x.push_back(i);
	}
	return x;
}

vector <double> generate_function_values(vector<double> x, double (*f)(double x)) {
	vector<double> y;
	for (auto iter = x.begin(); iter != x.end(); iter++) {
		y.push_back(f(*iter));
	}
	return y;
}

// Будем считать, что точки лежат строго в промежутке интерполирования
vector<double> generate_gap_by_power_and_point(vector<double> x, double point, int power) {
	if (power + 1 == x.size()) {
		return vector<double>(x);
	}

	if (power >= x.size() ) {
		throw invalid_argument("Не хватает точек для постраения многочлена данной степени");
	}

	vector<double> gap;

	auto value = upper_bound(x.begin(), x.end(), point);
	value--;
	int points_count = power + 1;
	int counter = 0;
	for (value; value != x.end() && counter < points_count; value++) {
		gap.push_back(*value);
		counter++;
	}
	if (counter < points_count) {
		value = upper_bound(x.begin(), x.end(), point);
		value--;
		value--;

		for (value; value != x.begin() && counter < points_count; value--) {
			gap.insert(gap.begin(), *value);
			counter++;
		}
	}
	return gap;
}

int main() {
	// Не делал проверку пользовательского ввода
	setlocale(LC_ALL, "Russian");

	cout << "Введите начало отрезка ([a, b]) интерполирования a: ";
	double a;
	cin >> a;

	cout << "Введите конец отрезка ([a, b]) интерполирования b: ";
	double b;
	cin >> b;

	cout << "Введите шаг интерполирования h: ";
	double h;
	cin >> h;
	cout << endl;

	vector<double> x = generate_gap(a, b, h);
	cout << "X: ";
	print_vector(x);

	vector<double> y = generate_function_values(x, function_6);
	cout << "Y: ";
	print_vector(y);

	cout << "\nВведите точку для вычисления значения интерполяционных многочленов: ";
	double point;
	cin >> point;

	cout << "\nВведите степень многочлена Лагранжа: ";
	int nl;
	cin >> nl;

	try {
		vector<double> gap = generate_gap_by_power_and_point(x, point, nl);
		vector<double> gap_y = generate_function_values(gap, function_6);
		cout << "Используемые значения:" << endl;
		cout << "X: ";
		print_vector(gap);
		cout << "Y: ";
		print_vector(gap_y);

		print_lagrange_polynomial(gap, gap_y);
		cout << endl;

		double value_l = lagrange_polynomial(point, gap, gap_y);
		double error_l = fabs(function_6(point) - value_l);
		cout << "Значение многочлена Лагранжа степени " << nl << " в точке " << point << ": "
			<< value_l << endl;
		cout << "Значение функции в точке " << point << ": " << function_6(point) << endl;
		cout << "Погрешность: " << error_l << endl;
		error_estimate(error_l, nl, point, gap);


		cout << "\nВведите степень многочлена Ньютона: ";
		int nn;
		cin >> nn;

		gap = generate_gap_by_power_and_point(x, point, nn);
		gap_y = generate_function_values(gap, function_6);
		cout << "Используемые значения:" << endl;
		cout << "X: ";
		print_vector(gap);
		cout << "Y: ";
		print_vector(gap_y);

		print_newton_polynomial(nn, gap, gap_y);
		cout << endl;

		double value_n = newton_polynomial(point, nn, gap, gap_y);
		double error_n = fabs(function_6(point) - value_n);
		cout << "Значение многочлена Ньютона степени " << nn << " в точке " << point << ": "
			<< value_n << endl;
		cout << "Значение функции в точке " << point << ": " << function_6(point) << endl;
		cout << "Погрешность: " << error_n << endl;
		error_estimate(error_n, nn, point, gap);
	}
	catch (invalid_argument& error) {
		cerr << '\n' << error.what() << endl;
	}

	return 0;
}