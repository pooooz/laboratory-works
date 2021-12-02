#include <iostream>

using namespace std;

int task4_3(int a) {


	int a1 = a * a * a; // 3
	a1 *= a1; // 6
	a1 *= a1; // 12
	a1 *= a; // 13

	cout << "Число " << a << " в степени 13 = " << a1 << endl;
	return 0;
}

int task4_4(int a) {
	int a1 = a * a; // 2
	a1 *= a1; // 4
	a1 *= a1; // 8
	a1 *= a1 / a; // 15

	cout << "Число " << a << " в степени 15 = " << a1 << endl;
	return 0;
}

int task4_5(int a) {

	int a1 = a * a; // 2
	a1 *= a1 * a; // 5
	a1 *= a1; // 10
	a1 *= a1 * a; // 21

	cout << "Число " << a << " в степени 21 = " << a1 << endl;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int a;
	cout << "Введите число" << endl;
	cin >> a;

	task4_3(a);
	task4_4(a);
	task4_5(a);
	return 0;
}
