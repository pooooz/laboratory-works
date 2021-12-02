#include <iostream>
#include <math.h>

using namespace std;

double calculate_side(double d1, double square) {

	double d2 = 2 * square / d1;

	double side = sqrt(pow(d1 / 2, 2) + pow(d2 / 2, 2));
	
	return side;
}

double calculate_perimeter(double side) {

	double perimeter = side * 4;

	return perimeter;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	double d1, square;

	cout << "Введите диагональ" << endl;
	cin >> d1;

	cout << "Введите площадь" << endl;
	cin >> square;

	cout << "Сторона ромба: " << calculate_side(d1, square) << endl;

	cout << "Периметр ромба: " << calculate_perimeter(calculate_side(d1, square)) << endl;
	
	return 0;
}