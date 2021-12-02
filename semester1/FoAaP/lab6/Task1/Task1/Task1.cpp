#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	double n;

	cout << "������� ���������� ��������� ������� n: ";
	cin >> n;

	if (n >= 1 && n - int(n) == 0) {
		long double *Array = new long double[n];

		for (int i = 0; i < n; i++) {
			long double temp;
			cout << "������� �������� " << i + 1 << " �������� �������: ";
			cin >> temp;
			Array[i] = temp;
		}

		cout << "\n��� ������: [ ";

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

		cout << "\n����� ������������� ��������� ������� �����: " << sum << endl;

		delete[]Array;
	}
	else {
		cout << "������������ ����" << endl;
	}


	system("pause");
	return 0;
}