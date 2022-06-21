#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class ColumnarizeStringСharacters {
public:
	ColumnarizeStringСharacters(string initial_string) {
		try {
			if (initial_string.size() < 3) {
				throw invalid_argument("Длина строки меньше, чем 3 символа");
			}
			for (int i = 2; i < initial_string.size(); i += 3) {
				cout << initial_string[i] << endl;
			}
		}
		catch (invalid_argument& error) {
			cerr << error.what() << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Введите строку: ";
	string initial_string;
	getline(cin, initial_string);

	ColumnarizeStringСharacters resolve(initial_string);

	return 0;
}