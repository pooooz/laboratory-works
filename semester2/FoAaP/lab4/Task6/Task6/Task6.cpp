#include <iostream>
#include "complex.h"

using namespace std;

void enter_number_IR(long double& n) {
	while (!(cin >> n) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

ostream& operator << (ostream& os, complex number) {
	if (number.get_Im() < 0) {
		os << number.get_Re() << " - " << fabs(number.get_Im()) << 'i';
	}
	else {
		os << number.get_Re() << " + " << number.get_Im() << 'i';
	}
	return os;
}

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Комплексное число 1: a + bi !!!" << endl;
	cout << "Введите действительную часть комплексного числа 1 (a): ";
	long double a;
	enter_number_IR(a);
	cout << "Введите коэффициент мнимой части комплексного числа 1 (b): ";
	long double b;
	enter_number_IR(b);

	cout << "\n";

	cout << "Комплексное число 2: c + ki !!!" << endl;
	cout << "Введите действительную часть комплексного числа 2 (c): ";
	long double c;
	enter_number_IR(c);
	cout << "Введите коэффициент мнимой части комплексного числа 2 (k): ";
	long double k;
	enter_number_IR(k);

	complex first = complex(a, b);
	complex second = complex(c, k);

	cout << "Первое число: " << endl;
	cout << first << endl;
	cout << "\n";

	cout << "Второе число: " << endl;
	cout << second << endl;
	cout << "\n";

	cout << "Результат вычитания: ";
	cout << first - second << endl;

	try {
		cout << "Результат деления: ";
		cout << first / second << endl;
	}
	catch (std::invalid_argument& ex) {
		cerr << ex.what() << endl;
	}
	

	return 0;
}