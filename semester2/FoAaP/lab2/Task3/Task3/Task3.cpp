#include <iostream>

#include "geometry.h"

using namespace std;

void enter_number_IR(long double& n) {
	while (!(cin >> n) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "¬ведено некорректное значение! ѕовторите ввод!!!" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "¬ведите координаты точки начала вектора 1!" << endl;
	long double x1, y1;
	cout << "¬ведите координату x начала вектора 1: ";
	enter_number_IR(x1);
	cout << "¬ведите координату y начала вектора 1: ";
	enter_number_IR(y1);

	cout << "¬ведите координаты точки конца вектора 1!" << endl;;
	long double x2, y2;
	cout << "¬ведите координату x конца вектора 1: ";
	enter_number_IR(x2);
	cout << "¬ведите координату y конца вектора 1: ";
	enter_number_IR(y2);


	Point start1 = Point(x1, y1);
	Point end1 = Point(x2, y2);
	Vector vector1 = Vector(start1, end1);


	cout << "¬ведите координаты точки начала вектора 2!" << endl;;
	long double x3, y3;
	cout << "¬ведите координату x начала вектора 2: ";
	enter_number_IR(x3);
	cout << "¬ведите координату y начала вектора 2: ";
	enter_number_IR(y3);

	cout << "¬ведите координаты точки конца вектора 2!" << endl;;
	long double x4, y4;
	cout << "¬ведите координату x конца вектора 2: ";
	enter_number_IR(x4);
	cout << "¬ведите координату y конца вектора 2: ";
	enter_number_IR(y4);

	
	Point start2 = Point(x3, y3);
	Point end2 = Point(x4, y4);
	Vector vector2 = Vector(start2, end2);

	vector1.info();
	vector2.info();

	cout << "\n";

	long double scalarProduct = vector1.scalar_product(vector2);
	cout << "—кал€рное произведение веторов: " << scalarProduct << endl;

	cout << "\n";

	Vector vectorSum = Vector::vector_sum(vector1, vector2);
	cout << "—умма векторов!";
	vectorSum.info();
	cout << "\n";

	cout << "¬ведите скал€р: ";
	long double scalar;
	enter_number_IR(scalar);
	cout << "\n";
	vector1.multiply_by_scalar(scalar);
	vector1.info();

	return 0;
}