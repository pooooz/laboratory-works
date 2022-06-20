#include <iostream>

using namespace std;

template <typename n>
void enter_number(n& x) {
	while (!(cin >> x) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

class Age {
	int months;
	int years;
public:
	Age(int months) {
		this->months = months;
		try {
			if (!(this->months >= 1 && this->months <= 1188)) {
				throw invalid_argument("Количество месяцев выходит за пределы условия");
			}

			this->years = months / 12;
			int last_months_number = (this->months - this->years * 12) % 10;
			int last_years_number = (this->years) % 10;


			// Hell ))) May be optimized and fixed later, but it was a speedrun ))) Blood from the eyes)))
			if (this->years != 0) {
				cout << "Возраст: " << this->years;
				if (this->years >= 10 && this->years <= 20) {
					if (last_years_number != 1) {
						cout << " лет ";
					}
					else {
						cout << " год ";
					}
				}
				else {
					if (last_years_number != 1) {
						if (last_years_number >= 5) {
							cout << " лет ";
						}
						else {
							cout << " года ";
						}
					}
					else {
						cout << " год ";
					}
				}
			}

			if (last_months_number != 0) {
				if (this->years != 0) {
					if (last_months_number != 1) {
						if (last_months_number >= 5) {
							cout << "и " << this->months - this->years * 12 << " месяцев" << endl;
						}
						else {
							cout << "и " << this->months - this->years * 12 << " месяца" << endl;
						}
					}
					else {
						if (this->months - this->years * 12 >= 10) {
							cout << "и " << this->months - this->years * 12 << " месяцев" << endl;
						}
						else {
							cout << "и " << this->months - this->years * 12 << " месяц" << endl;
						}
					}
				}
				else {
					cout << "Возраст: ";
					if (last_months_number != 1) {
						if (last_months_number >= 5) {
							cout << this->months - this->years * 12 << " месяцев" << endl;
						}
						else {
							cout << this->months - this->years * 12 << " месяца" << endl;
						}
					}
					else {
						if (this->months - this->years * 12 >= 10) {
							cout << this->months - this->years * 12 << " месяцев" << endl;
						}
						else {
							cout << this->months - this->years * 12 << " месяц" << endl;
						}
					}
				}
				
			}
			
		}
		catch (invalid_argument& error) {
			cerr << error.what() << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	int months;
	cout << "Введите количество месяцев: ";
	enter_number(months);

	Age age(months);

	return 0;
}