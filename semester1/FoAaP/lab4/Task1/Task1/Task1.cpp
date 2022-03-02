#include <iostream>
using namespace std;


void k_variant(int n) {
	double sum, product, temp;

	cout << "Вариант к) \n" << endl;

	sum = 0.;
	product = 1;
	temp = 1.;



	for (int i = 1; i <= n; i++) {
		temp /= i;
		sum += temp;
		product *= temp;
	}

	cout << "Сумма первых " << n << " членов равна " << sum << endl;
	cout << "Произведение первых " << n << " членов равна " << product << endl;

}

int main() {
	setlocale(LC_ALL, "Russian");

	double sum, product, temp;
	int n;

	sum = 0.;
	product = 1;
	temp = 1.;

	cout << "Введите количество N членов: ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		temp /= 2;
		sum += temp;
		product *= temp;

	}
	
	cout << "Сумма первых " << n << " членов равна " << sum << endl;
	cout << "Произведение первых " << n << " членов равна " << product << endl;

	k_variant(n);

	system("pause");
	return 0;
}


