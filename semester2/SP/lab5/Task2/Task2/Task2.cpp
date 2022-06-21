#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class CountSpaces {
	int max_spaces_count = 0;
public:
	CountSpaces(string str) {
		int tmp = 0;
		for (int i = 0; i < str.size(); i++) {

			str[i] == ' ' ? tmp++ : tmp = 0;

			if (tmp > this->max_spaces_count) {
				this->max_spaces_count = tmp;
			}
		}

		cout << "Максимальное количество идущих подряд пробелов: " << this->max_spaces_count << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Введите строку: ";
	string str;
	getline(cin, str);

	CountSpaces resolve(str);

	return 0;
}