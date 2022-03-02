#include <iostream>
#include <math.h>

using namespace std;

double intersection(double a, double k, double b, double r, double m, double c) {

	double x = 0;
	double y = 0;

	if (a == r && k == m && b == c) {
		cout << "\n Прямые совпадают \n" << endl;
	}
	else if (k / a == m / r) {
		cout << "\n Прямые параллельны \n" << endl;
	}
	else if (a == 0) {
		x = -(b / k);
		y = k * x + b;

		cout << "\n Прямые пересекаются в точке " << "(" << x << ";" << y << ")" << endl;
	}
	else if (r == 0) {
		x = -(c / m);
		y = k * x + b;

		cout << "\n Прямые пересекаются в точке " << "(" << x << ";" << y << ")" << endl;
	}
	else {
		x = (c/r - b/a) / (k/a - m/r);
		y = k * x + b;

		cout << "\n Прямые пересекаются в точке " << "(" << x << ";" << y << ")" << endl;
	}

	
	return 0;
}


int main() {

	setlocale(LC_ALL, "Russian");

	double k, b, m, c, a, r;
	
	cout << "Пусть первая прямая задана зависимостью формата a * y = k * x + b" << endl;

	cout << "Введите коэффициент a: ";
	cin >> a;

	cout << "Введите коэффициент k: ";
	cin >> k;

	cout << "Введите коэффициент b: ";
	cin >> b;


	if (a == 0) {
		cout << "\n Первая прямая задана зависимостью x = " << -(b / k) << endl;
	}
	else if (k == 0) {
		cout << "\n Первая прямая задана зависимостью y = " << b / a << endl;
	}
	else if (b > 0) {
		cout << "\n Первая прямая задана зависимостью y = " << k / a << " * x + " << b / a << endl;
	}
	else if (b < 0) {
		cout << "\n Первая прямая задана зависимостью y = " << k / a << " * x - " << abs(b) / a << endl;
	}
	else {
		cout << "\n Первая прямая задана зависимостью y = " << k / a << " * x " << endl;
	}



	cout << "\n Пусть вторая прямая задана зависимостью формата r * y = m * x + c" << endl;
	
	cout << "Введите коэффициент r: ";
	cin >> r;

	cout << "Введите коэффициент m: ";
	cin >> m;

	cout << "Введите коэффициент c: ";
	cin >> c;


	if (r == 0) {
		cout << "\n Вторая прямая задана зависимостью x = " << -(c / m) << endl;
	}
	else if (m == 0) {
		cout << "\n Вторая прямая задана зависимостью y = " << c / r << endl;
	}
	else if (c > 0) {
		cout << "\n Вторая прямая задана зависимостью y = " << m / r << " * x + " << c / r << endl;
	}
	else if (c < 0) {
		cout << "\n Вторая прямая задана зависимостью y = " << m / r << " * x - " << abs(c) / r << endl;
	}
	
	else {
		cout << "\n Вторая прямая задана зависимостью y = " << m / r << " * x " << endl;
	}

	intersection(a, k, b, r, m, c);

	system("pause");
	return 0;
}