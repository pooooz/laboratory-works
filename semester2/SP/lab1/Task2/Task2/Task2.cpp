#include <iostream>
#include <string>

using namespace std;

template <typename n>
void enter_number(n& x) {
	while (!(cin >> x) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

class ThreeDigitNumber {
	int int_number;
	string string_number;
public:
	ThreeDigitNumber(int number) {
		try {
			if (!(abs(number) > 99 && abs(number) < 1000)) {
				throw invalid_argument("Число должно быть трёхзначным");
			}
			
			this->int_number = number;
			this->string_number = to_string(this->int_number);
			
			char last_char = this->string_number[this->string_number.size() - 1];
			cout << "Последняя цифра справа: " << (int)last_char - (int)'0' << endl;

			this->string_number.pop_back();

			if ((int)last_char - (int)'0' != 0 && this->int_number > 0) {
				cout << "Результат: " << this->string_number.insert(0, 1, last_char) << endl;
			}
			else if ((int)last_char - (int)'0' != 0 && this->int_number < 0) {
				cout << "Результат: " << this->string_number.insert(1, 1, last_char) << endl;
			}
		} 
		catch (invalid_argument& error) {
			cerr << error.what() << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	int number;
	cout << "Введите трёззачное число: ";
	enter_number(number);

	ThreeDigitNumber three_digit_number(number);

	return 0;
}