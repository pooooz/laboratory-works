#include <iostream>
#include <Windows.h>
#include <set>

using namespace std;

int length(char* str) {
	int counter = 0;
	while (str[counter] != '\0') {
		counter++;
	}
	return counter;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");


	char* str = new char[255];
	set<char>symbols;


	cout << "Введите строку: ";
	cin.getline(str, 255);

	for (int i = 0; i < length(str); i++) {
		symbols.insert(str[i]);
	}

	cout << "В строке " << str << " " << symbols.size() << " различных символа(ов)" << endl ;

	delete[]str;


	system("pause");
	return 0;
}