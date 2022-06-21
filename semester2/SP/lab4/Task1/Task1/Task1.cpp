#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

default_random_engine randomEngine(time(NULL));

int get_random_number(int min, int max) {
	uniform_int_distribution<int> randomNum(min, max);
	return randomNum(randomEngine);
}

class WeatherChallenge {
	int days_count = 31;
	int days_without_precipitation_count = 0;
	int* data_array;

	void print_data() {
		cout << "\nВ этот день наблюдались осадки - 1" << endl;
		cout << "В этот день не наблюдалось осадков - 0" << endl;
		cout << '\n';
		for (int i = 0; i < this->days_count; i++) {
			cout << setw(2) << setfill('0') << i + 1 << ".03: ";
			cout << this->data_array[i] << endl;
			if (i != 0 && i % 10 == 0) {
				cout << '\n';
			}
		}
		cout << "Дней без осадков: " << this->days_without_precipitation_count << endl;
		cout << " - Верно ли, что осадков не было 10 дней в месяц?" << endl;
		if (this->days_without_precipitation_count > 10) {
			cout << " - Нет, осадков не было больше, чем 10 дней в месяц" << endl;
		}
		else if (this->days_without_precipitation_count < 10) {
			cout << " - Нет, осадков не было меньше, чем 10 дней в месяц" << endl;
		}
		else {
			cout << " - Да, осадков не было 10 дней в месяц" << endl;
		}
	}
public:
	WeatherChallenge() {
		this->data_array = new int[this->days_count];
		for (int i = 0; i < this->days_count; i++) {
			this->data_array[i] = get_random_number(0, 1);
			if (this->data_array[i] == 0) {
				this->days_without_precipitation_count++;
			}
		}
		print_data();
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	WeatherChallenge();

	return 0;
}