#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int number, temp, counter, sum;

	cout << "������� �����: ";
	cin >> number;

	temp = number;
	counter = 0;
	sum = 0;

	while (temp > 0) {
		counter++;
		temp /= 10;
	}

	cout << "���������� ���� � �����: " << counter << endl;

	
	for (int i = 1; i <= counter; i++) {
		sum += number % 10;
		number /= 10;
	}

	cout << "����� ���� ��������� �����: " << sum << endl;

	system("pause");
	return 0;
}