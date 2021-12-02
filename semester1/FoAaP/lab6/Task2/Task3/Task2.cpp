#include <iostream>

using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");

	double n;
	cout << "������� ���������� ��������� ������� n: ";
	cin >> n;

	if (n >= 1 && n - int(n) == 0) {
		long double* Array = new long double[n];

		for (int i = 0; i < n; i++) {
			long double temp;
			cout << "������� �������� " << i + 1 << " �������� �������: ";
			cin >> temp;
			Array[i] = temp;
		}

		cout << "��� ������: [ ";

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
		cout << "���������� ����� � �������: " << zero_counter << endl;


		if (zero_counter >= 2) {
			int index = 0;
			while (*(Array + index) != 0) {
				index++;
			}

			cout << "������ ������� �������, ������ ����: " << index + 1 << " �������" << endl;
			index++;

			long double product = 1;

			while (Array[index] != 0) {
				product *= *(Array + index);
				index++;
			}
			cout << "������������ ��������� �������: " << product << endl << endl;

		}
		else {
			cout << "� ������� ������ ���� �����" << endl << endl;
		}
		delete[]Array;
	}
	else {
		cout << "������������ ����" << endl;
	}

	system("pause");
	return 0;
}