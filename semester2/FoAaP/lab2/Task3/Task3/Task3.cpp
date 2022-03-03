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

	cout << "Введите координаты точки начала вектора 1!" << endl;
	long double x1, y1;
	cout << "Введите координату x начала вектора 1: ";
	enter_number_IR(x1);
	cout << "Введите координату y начала вектора 1: ";
	enter_number_IR(y1);

	cout << "Введите координаты точки конца вектора 1!" << endl;;
	long double x2, y2;
	cout << "Введите координату x конца вектора 1: ";
	enter_number_IR(x2);
	cout << "Введите координату y конца вектора 1: ";
	enter_number_IR(y2);


	Point start1 = Point(x1, y1);
	Point end1 = Point(x2, y2);
	Vector vector1 = Vector(start1, end1);


	cout << "Введите координаты точки начала вектора 2!" << endl;;
	long double x3, y3;
	cout << "Введите координату x начала вектора 2: ";
	enter_number_IR(x3);
	cout << "Введите координату y начала вектора 2: ";
	enter_number_IR(y3);

	cout << "Введите координаты точки конца вектора 2!" << endl;;
	long double x4, y4;
	cout << "Введите координату x конца вектора 2: ";
	enter_number_IR(x4);
	cout << "Введите координату y конца вектора 2: ";
	enter_number_IR(y4);

	
	Point start2 = Point(x3, y3);
	Point end2 = Point(x4, y4);
	Vector vector2 = Vector(start2, end2);

	cout << "\n" << "Координаты 1-го вектора: ";
	vector1.info();
	cout << "\n" << "Координаты 2-го вектора: ";
	vector2.info();

	cout << "\n";

	long double scalarProduct = vector1.scalar_product(vector2);
	cout << "Скалярное произведение веторов: " << scalarProduct << endl;

	cout << "\n";

	Vector vectorSum = Vector::vector_sum(vector1, vector2);
	cout << "Сумма векторов!";
	vectorSum.info();
	cout << "\n";

	cout << "Введите скаляр: ";
	long double scalar;
	enter_number_IR(scalar);
	cout << "\n Новый координаты первого вектора:";
	vector1.multiply_by_scalar(scalar);
	vector1.info();

	return 0;
}