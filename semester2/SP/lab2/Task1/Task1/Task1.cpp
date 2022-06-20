#include <iostream>

using namespace std;

template <typename n>
void enter_number(n& x) {
	while (!(cin >> x) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

class QuadraticEquation {
	double a;
	double b;
	double c;
	double discriminant;

	double x1;
	double x2;
public:
	QuadraticEquation(double a, double b, double c) {
		this->a = a;
		this->b = b;
		this->c = c;

		cout << "Квадратное уравнение: ";
		if (a != 0) {
			cout << a << "x^2";
		}

		if (b == 1) {
			cout << '+' << "x";
		}
		else if (b > 1) {
			cout << '+' << this->b << "x";
		}
		else if (b != 0) {
			cout << this->b << "x";
		}


		if (c >= 1) {
			cout << '+' << this->c;
		}
		else if (c != 0) {
			cout << this->c;
		}
		cout << "=0" << endl;

		if (this->a != 0) {
			this->discriminant = b * b - 4 * a * c;
			cout << "\nДискриминант D: " << this->discriminant << endl;
			if (this->discriminant >= 0) {
				cout << "Корень из D: " << sqrt(this->discriminant) << endl;
			}

			if (this->discriminant == 0) {
				cout << "\nУравнение имеет действительные решения" << endl;
				this->x1 = -b / (2 * a);
				this->x2 = -b / (2 * a);
				cout << "Корень x1 = x2 = " << this->x1 << endl;
			}
			else if (this->discriminant > 0) {
				cout << "\nУравнение имеет действительные решения" << endl;
				this->x1 = (-b + sqrt(this->discriminant)) / (2 * a);
				this->x2 = (-b - sqrt(this->discriminant)) / (2 * a);
				cout << "Корень x1 = " << this->x1 << endl;
				cout << "Корень x2 = " << this->x2 << endl;
			}
			else {
				cout << "\nУравнение не имеет решений в действительных числах" << endl;
			}
		}
		else if (this->a == 0 && this->b != 0) {
			cout << "\nУравнение имеет действительные решения" << endl;
			cout << "x = " << -this->c / this->b << endl;
		}
		else if (this->a == 0 && this->b == 0) {
			if (this->c == 0) {
				cout << "Утверждение верно" << endl;
			}
			else {
				cout << "Утверждение ложно" << endl;
			}
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	double a, b, c;
	cout << "Введите коэффициент a: ";
	enter_number(a);
	cout << "Введите коэффициент b: ";
	enter_number(b);
	cout << "Введите коэффициент c: ";
	enter_number(c);

	QuadraticEquation quadratic_equation(a, b, c);

	return 0;
}