#include <iostream>

using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");

	double n;
	cout << "Введите количество элементов массива n: ";
	cin >> n;

	if (n >= 1 && n - int(n) == 0) {
		long double* Array = new long double[n];

		for (int i = 0; i < n; i++) {
			long double temp;
			cout << "Введите значение " << i + 1 << " элемента массива: ";
			cin >> temp;
			Array[i] = temp;
		}

		cout << "Ваш массив: [ ";

		for (int i = 0; i < n; i++) {
			cout << *(Array + i) << " ";
		}
		cout << "]" << endl << endl;


		int zero_counter = 0;
		for (int i = 0; i <= n; i++) {
			if (*(Array + i) == 0) {
				zero_counter++;
			}
		}
		cout << "Количество нулей в массиве: " << zero_counter << endl;


		if (zero_counter >= 2) {
			int index = 0;
			while (*(Array + index) != 0) {
				index++;
			}

			cout << "Первый элемент массива, равный нулю: " << index + 1 << " элемент" << endl;
			index++;

			long double product = 1;

			while (Array[index] != 0) {
				product *= *(Array + index);
				index++;
			}
			cout << "Произведение элементов массива: " << product << endl << endl;

		}
		else {
			cout << "В массиве меньше двух нулей" << endl << endl;
		}
		delete[]Array;
	}
	else {
		cout << "Некорректный ввод" << endl;
	}

	system("pause");
	return 0;
}