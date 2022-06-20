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

class Triangle {
	double a;
	double b;
	double c;
public:
	Triangle(double a, double b, double c) {
		this->a = a;
		this->b = b;
		this->c = c;

		try {
			if (this->a <= 0 || this->b <= 0 || this->c <= 0) {
				throw invalid_argument("\nДлина любой стороны треугольника должна быть большей либо равной 0");
			}

			if (this->a == this->b || this->a == this->c || this->b == this->c) {
				cout << "Треугольник равнобедренный" << endl;
			}
			else {
				cout << "Треугольник не является равнобедренным" << endl;
			}

		}
		catch (invalid_argument& error) {
			cerr << error.what() << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	double a, b, c;

	cout << "Введите a: ";
	enter_number(a);

	cout << "Введите b: ";
	enter_number(b);

	cout << "Введите c: ";
	enter_number(c);

	Triangle triangle(a, b, c);

	return 0;
}