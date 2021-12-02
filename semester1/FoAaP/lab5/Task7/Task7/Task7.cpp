#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	long double a, b, x, x2, deltaX;

	cout << "¬ведите начальное значение X1: ";
	cin >> x;

	cout << "¬ведите конечное значение X2: ";
	cin >> x2;

	cout << "¬ведите шаг значени€ deltaX: ";
	cin >> deltaX;

	cout << "¬ведите a: ";
	cin >> a;

	cout << "¬ведите b: ";
	cin >> b;

	cout << setw(20) << left << "X" << setw(20) << left << "Y1" << setw(20) << left << "Y2" << setw(20) << left << "Y3" << endl;


	for (x; x <= x2; x += deltaX) {

		long double y1, y2, y3 = 0;

		if (x <= 1) {
			y1 = sqrt(log(fabs(x)) * log(fabs(x)) + x * x);
		}
		else {
			y1 = ((1 - a) * x * x) + a;
		}

		if (x <= 0) {
			y2 = 1 - pow(M_E, x);
		}
		else {
			y2 = cos(b * x);
		}

		if (x <= -1) {
			y3 = sin(log(fabs(x)));
		}
		else {
			y3 = sin((x + 1) * (x + 1));
		}

		cout << setw(20) << left << x << setw(20) << left << y1 << setw(20) << left << y2 << setw(20) << left << y3 << endl;

	}

	system("pause");
	return 0;
}