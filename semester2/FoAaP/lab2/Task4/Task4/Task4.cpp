#include <iostream>

#include "geometry.h"

using namespace std;

void enter_number_IR(long double& n) {
	while (!(cin >> n) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "������� ������������ ��������! ��������� ����!!!" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "������� ��������� ����� 1!" << endl;
	long double x1, y1;
	cout << "������� ���������� x ����� 1: ";
	enter_number_IR(x1);
	cout << "������� ���������� y ����� 1: ";
	enter_number_IR(y1);

	cout << "������� ��������� ����� 2!" << endl;
	long double x2, y2;
	cout << "������� ���������� x ����� 2: ";
	enter_number_IR(x2);
	cout << "������� ���������� y ����� 2: ";
	enter_number_IR(y2);

	cout << "������� ��������� ����� 3!" << endl;
	long double x3, y3;
	cout << "������� ���������� x ����� 3: ";
	enter_number_IR(x3);
	cout << "������� ���������� y ����� 3: ";
	enter_number_IR(y3);

	Point A = Point(x1, y1),
		  B = Point(x2, y2),
		  C = Point(x3, y3);

	Triangle triangle = Triangle(A, B, C);
	Point medianPoint = triangle.get_median_point();

	cout << "\n";

	cout << "���������� x ����� ����������� ������ ������������: " << medianPoint.getX() << endl;
	cout << "���������� y ����� ����������� ������ ������������: " << medianPoint.getY() << endl;

	cout << "\n\n";

	Point heightsPoint = triangle.get_heights_point();

	cout << "���������� x ����� ����������� ����� ������������: " << heightsPoint.getX() << endl;
	cout << "���������� y ����� ����������� ����� ������������: " << heightsPoint.getY() << endl;

	return 0;
}