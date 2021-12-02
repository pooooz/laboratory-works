#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int length(char* str) {
	int counter = 0;
	while (str[counter] != '\0') {
		counter++;
	}
	return counter;
}

char* own_strrchr(char* str, char chr) {
	int i = length(str) - 1;
	if (str[i] == chr)
	{
		return &str[i];
	}
	while (str[i]) {
		if (str[i] == chr)
		{
			return &str[i];
		}
		i--;
	}
	return NULL;
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	char* str = new char[255];
	char srch;
	cout << str;

	cout << "Введите строку: ";
	cin.getline(str, 255);

	cout << "Введите символ: ";
	cin >> srch;


	cout << "\nРезультат strrchr: ";
	cout << strrchr(str, srch) << endl;

	cout << "\nРезультат собственной функции: ";
	cout << own_strrchr(str, srch) << "\n" << endl;

	delete[]str;
	

	system("pause");
	return 0;
}