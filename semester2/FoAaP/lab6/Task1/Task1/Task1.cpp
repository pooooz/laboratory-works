#include <iostream>
#include <string>
#include <regex>
#include <Windows.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russain");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "Введите начальную строку: " << endl;
	string base;
	getline(cin, base);

	cout << "\n";

	regex ex("\\([^\\)]*\\)");

	cout << "Начальная строка: " << base << endl;
	string new_str = regex_replace(base, ex, "");
	cout << "Форматированная строка: " << new_str << endl;

	return 0;
}