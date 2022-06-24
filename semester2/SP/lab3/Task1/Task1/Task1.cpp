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

class Feast {
	int donated_sweets = 0;
	int guests_count = 0;
	int toddler_sweets = 0;
	int carlson_sweets = 0;
	bool isEnough = true;

	void carve_up() {
		for (int i = 0; i < this->guests_count; i++) {
			if (i != this->guests_count - 1) {
				if (this->donated_sweets % 2 != 0) {
					this->toddler_sweets++;
					this->donated_sweets -= this->donated_sweets / 2 + 1;
				}
				else {
					this->donated_sweets -= this->donated_sweets / 2;
				}
			}
			else {
				if (this->donated_sweets == 0) {
					this->isEnough = false;
				}
				this->carlson_sweets = this->donated_sweets;
				this->donated_sweets -= this->carlson_sweets;
			}
		}
	}

	void results() {
		cout << '\n';
		if (this->isEnough) {
			cout << "Фух, всем гостям хватило конфет!" << endl;
			cout << "Малыш съел: " << this->toddler_sweets << endl;
			cout << "Карлсон съел: " << this->carlson_sweets << endl;
		}
		else {
			cout << "Конфет хватило не всем :(" << endl;
			cout << "Малыш съел: " << this->toddler_sweets << endl;
			cout << "Карлсон не съел конфет :(" << endl;
		}
	}

public:
	Feast(int donated_sweets, int guests_count) {
		try {
			if (guests_count == 0) {
				throw invalid_argument("Праздник не удался! Никто не пришёл :( ");
			}
			if (guests_count < 0) {
				throw invalid_argument("Количество гостей не может быть отрицательным");
			}
			if (donated_sweets < 0) {
				throw invalid_argument("Количество конфет не может быть отрицательным");
			}

			this->donated_sweets = donated_sweets;
			this->guests_count = guests_count;

			carve_up();
			results();
		}
		catch (invalid_argument& error) {
			cerr << error.what() << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	int sweets_count;
	cout << "Введите количество подаренных конфет: ";
	enter_number(sweets_count);

	int guests_count;
	cout << "Введите количество гостей: ";
	enter_number(guests_count);

	Feast feast(sweets_count, guests_count);

	return 0;
}