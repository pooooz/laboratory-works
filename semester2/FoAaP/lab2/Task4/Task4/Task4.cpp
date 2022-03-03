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

	cout << "Введите кооринаты точки 1!" << endl;
	long double x1, y1;
	cout << "Введите координату x точки 1: ";
	enter_number_IR(x1);
	cout << "Введите координату y точки 1: ";
	enter_number_IR(y1);

	cout << "Введите кооринаты точки 2!" << endl;
	long double x2, y2;
	cout << "Введите координату x точки 2: ";
	enter_number_IR(x2);
	cout << "Введите координату y точки 2: ";
	enter_number_IR(y2);

	cout << "Введите кооринаты точки 3!" << endl;
	long double x3, y3;
	cout << "Введите координату x точки 3: ";
	enter_number_IR(x3);
	cout << "Введите координату y точки 3: ";
	enter_number_IR(y3);

	Point A = Point(x1, y1),
		  B = Point(x2, y2),
		  C = Point(x3, y3);
	try {
		Triangle triangle = Triangle(A, B, C);
		Point medianPoint = triangle.get_median_point();
		cout << "\n";

		cout << "Координата x точки пересечения медиан треугольника: " << medianPoint.getX() << endl;
		cout << "Координата y точки пересечения медиан треугольника: " << medianPoint.getY() << endl;

		cout << "\n\n";

		Point heightsPoint = triangle.get_heights_point();

		cout << "Координата x точки пересечения высот треугольника: " << heightsPoint.getX() << endl;
		cout << "Координата y точки пересечения высот треугольника: " << heightsPoint.getY() << endl;
	}
	catch (std::invalid_argument const& ex) {
		cerr << "\n\n" << ex.what() << endl;
		cerr << "\n" << "Треугольник не существует!" << endl;
	}
	
	return 0;
}