#include <iostream>
#include <cmath>

using namespace std;

double for_realization(double h, double x) {
	double sum, term;

	sum = 0;
	term = 1;

	for (int i = 1; fabs(term) >= h; i++) {
		sum += term;
		term *= x * x / (2 * i * (2 * i - 1));
	}

	return sum;
}

double while_realization(double h, double x) {
	double sum, term;
	int i;

	sum = 0;
	term = 1;
	i = 1;

	while (fabs(term) >= h) {
		sum += term;
		term *= x * x / (2 * i * (2 * i - 1));
		i++;
	}

	return sum;
}

double do_while_realization(double h, double x) {
	double sum, term;
	int i;

	sum = 0;
	term = 1;
	i = 1;

	do {
		sum += term;
		term *= x * x / (2 * i * (2 * i - 1));
		i++;
	} 	while (fabs(term) >= h);

	return sum;
}



int main() {
	setlocale(LC_ALL, "Russian");

	double h, x, comparison;

	cout << "������� �������� h: ";
	cin >> h;

	cout << "������� x: ";
	cin >> x;

	cout << "\n\n";

	comparison = cosh(x);

	cout << "����� �� for:  " << for_realization(h, x) << endl;
	cout << "����� �� while: " << while_realization(h, x) << endl;;
	cout << "����� �� do while: " << while_realization(h, x) << endl;


	cout << "������� �� cmath: " << comparison << "\n\n";


	system("pause");
	return 0;
}