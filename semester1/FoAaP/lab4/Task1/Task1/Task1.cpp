#include <iostream>
using namespace std;


void k_variant(int n) {
	double sum, product, temp;

	cout << "������� �) \n" << endl;

	sum = 0.;
	product = 1;
	temp = 1.;



	for (int i = 1; i <= n; i++) {
		temp /= i;
		sum += temp;
		product *= temp;
	}

	cout << "����� ������ " << n << " ������ ����� " << sum << endl;
	cout << "������������ ������ " << n << " ������ ����� " << product << endl;

}

int main() {
	setlocale(LC_ALL, "Russian");

	double sum, product, temp;
	int n;

	sum = 0.;
	product = 1;
	temp = 1.;

	cout << "������� ���������� N ������: ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		temp /= 2;
		sum += temp;
		product *= temp;

	}
	
	cout << "����� ������ " << n << " ������ ����� " << sum << endl;
	cout << "������������ ������ " << n << " ������ ����� " << product << endl;

	k_variant(n);

	system("pause");
	return 0;
}


