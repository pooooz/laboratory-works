#include <iostream>
#define _USE_MATH_DEFINES 
#include <math.h>

using namespace std;

long double own_min(double value1, double value2) {
	if (value1 < value2) {
		return value1;
	}
	else {
		return value2;
	}
}

long double own_max(double value1, double value2) {
	if (value1 > value2) {
		return value1;
	}
	else {
		return value2;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");

	long double x, y;

	cout << "Введите x: " << endl;
	cin >> x;

	cout << "Введите y: " << endl;
	cin >> y;

	if ((y < 0 && y-x == 0) || (y-x == 0 && y == 0)) {
		cout << "0 в знаменателе!!!" << endl;
	}
	else {
		cout << "Результат: " << own_min(own_min(M_E, abs(y - x)), own_max(x, y)) / own_max(abs(y - x), y) << endl;
	}

	system("pause");

	return 0;
}