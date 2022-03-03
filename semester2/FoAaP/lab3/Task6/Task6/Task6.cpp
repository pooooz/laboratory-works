#include <iostream>
#include "geometry.h"

using namespace std;

void enter_number_IR(long double& n) {
	while (!(cin >> n) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Введите кооринаты центра круга!" << endl;
	long double x, y;
	cout << "Введите координату x центра: ";
	enter_number_IR(x);
	cout << "Введите координату y центра: ";
	enter_number_IR(y);

	cout << "Введите радиус круга: ";
	long double radius;
	enter_number_IR(radius);

	Point center = Point(x, y);
	Circle circle = Circle(center, radius);

	circle.info();

	cout << "\nПлощадь круга: " << circle.get_area() << endl;

	cout << "\nВведите кооринаты точки 1 сектора!" << endl;
	long double x1, y1;
	cout << "Введите координату x точки 1 сектора: ";
	enter_number_IR(x1);
	cout << "Введите координату y точки 1 сектора: ";
	enter_number_IR(y1);

	cout << "\nВведите кооринаты точки 2 сектора!" << endl;
	long double x2, y2;
	cout << "Введите координату x точки 2 сектора: ";
	enter_number_IR(x2);
	cout << "Введите координату y точки 2 сектора: ";
	enter_number_IR(y2);

	try {
		Point p1 = Point(x1, y1);
		Point p2 = Point(x2, y2);

		Sector sector = Sector(circle, p1, p2);

		cout << "Площадь вектора: " << sector.get_area() << endl;
	}
	catch (std::invalid_argument& ex) {
		cerr << "\n\n" << ex.what() << endl;
	}

	return 0;
}