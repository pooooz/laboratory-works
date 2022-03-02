#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	double n;

	cout << "Введите количество элементов массива n: ";
	cin >> n;

	if (n >= 1 && n - int(n) == 0) {
		long double *Array = new long double[n];

		for (int i = 0; i < n; i++) {
			long double temp;
			cout << "Введите значение " << i + 1 << " элемента массива: ";
			cin >> temp;
			Array[i] = temp;
		}

		cout << "\nВаш массив: [ ";

		for (int i = 0; i < n; i++) {
			cout << *(Array + i) << " ";
		}
		cout << "]" << endl;

		long double sum = 0;

		for (int i = 0; i <= n; i++) {
			if (*(Array + i) > 0) {
				sum += *(Array + i);
			}
		}

		cout << "\nСумма положительных элементов массива равна: " << sum << endl;

		delete[]Array;
	}
	else {
		cout << "Некорректный ввод" << endl;
	}


	system("pause");
	return 0;
}