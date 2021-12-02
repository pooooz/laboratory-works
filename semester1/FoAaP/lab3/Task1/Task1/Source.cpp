#include <iostream>
#include <math.h>

using namespace std;

void find_concidence() {

}

int main() {

	setlocale(LC_ALL, "Russian");

	int num;

	cout << "Введите четырехзначное число: ";

	cin >> num;

	if ((num <= 9999 && num >= 1000) || (num >= -9999 && num <= -1000) ) {

		int n1, n2, n3, n4;
		n1 = num % 10;
		n2 = (num / 10) % 10;
		n3 = (num / 100) % 10;
		n4 = (num / 1000) % 10;

		if (n1 == n2 || n1 == n3 || n1 == n4 || n2 == n3 || n2 == n4 || n3 == n4) {
			cout << "Есть совпадения" << endl;
		}
		else {
			cout << "Совпадений нет" << endl;
		}

	}
	else {
		cout << "Некорректный ввод" << endl;
	}

	system("pause");
	return 0;
}