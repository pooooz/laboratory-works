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

class DayWithWeather {
	bool isPresipitation;
	int temperature;
public:
	DayWithWeather(bool isPresipitation, int temperature) {
		this->isPresipitation = isPresipitation;
		this->temperature = temperature;
	}

	bool get_presipitation() {
		return this->isPresipitation;
	}

	int get_temperature() {
		return this->temperature;
	}
};

class WeatherChallenge {
	int days_count = 31;
	int days_without_precipitation = 0;
	int rainy_days = 0;
	int snowy_days = 0;
	vector<DayWithWeather> data_array;

	void print_data() {
		cout << "\nВ этот день наблюдались осадки - 1" << endl;
		cout << "В этот день не наблюдалось осадков - 0" << endl;
		cout << '\n';
		for (int i = 0; i < this->days_count; i++) {
			cout << "День " << setw(2) << setfill('0') << i + 1 << endl;
			cout << "Были ли осадки?: " << setw(1);
			this->data_array[i].get_presipitation() ? cout << "Да" << endl : cout << "Нет" << endl;
			cout << "Температура: " << this->data_array[i].get_temperature();
			cout << '\n' << endl;
		}
		cout << "Дней без осадков: " << this->days_without_precipitation << endl;
		cout << "Количество дней, когда шёл снег: " << this->snowy_days << endl;
		cout << "Количество дней, когда шёл дождь: " << this->rainy_days << endl;
	}
public:
	WeatherChallenge() {
		for (int i = 0; i < this->days_count; i++) {
			bool isPresipitation = bool(get_random_number(0, 1));
			int temperature = get_random_number(-20, 5);

			if (isPresipitation) {
				if (temperature >= 0) {
					this->rainy_days++;
				}
				else {
					this->snowy_days++;
				}
			}
			else {
				this->days_without_precipitation++;
			}

			this->data_array.push_back(DayWithWeather(isPresipitation, temperature));
		}
		print_data();
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	WeatherChallenge();

	return 0;
}