#include <iostream>
#include <string>
#include <regex>
#include <Windows.h>

using namespace std;

class CountCharactersNumber {
	int characters_count = 0;
public:
	CountCharactersNumber(string str) {
		try {
			if (str.find('-') != str.npos) {
				throw invalid_argument("Строка содержит символ \"-\"");
			}

			for (auto iter = str.begin(); iter != str.end(); iter++) {
				if (*iter == ' ' && iter != str.begin() || *iter == '\0') {
					break;
				}
				if (*iter == 'o' || *iter == 'о') {
					this->characters_count++;
				}
			}
			cout << "Количество символов \"о\" в первом слове: " << this->characters_count << endl;
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

	if (int('-') == int(' ')) {
		cout << "Пиздец" << endl;
	}

	cout << "Введите строку: ";
	string str;
	getline(cin, str);

	CountCharactersNumber resolve(regex_replace(str, regex(" {2,}"), " "));
}