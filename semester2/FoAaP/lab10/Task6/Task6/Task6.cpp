#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <Windows.h>

using namespace std;

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

template <class N>
void enter_number(N& n) {
	while (!(cin >> n) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

bool is_number(const string& s) {
	auto it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

class Bus {
	int number;
	int route;
	string initials;
public:
	Bus(int number, int route, string initials) {
		this->number = number;
		this->route = route;
		this->initials = initials;
	};

	int get_route() {
		return this->route;
	};

	string get_initials() {
		return this->initials;
	};
};

bool operator < (pair<int, Bus>& a, pair<int, Bus>& b) {
	return a.second.get_route() < b.second.get_route();
}
class BusDepot {
	map<int, Bus> in_depot;
	map<int, Bus> on_road;

public:
	BusDepot(string file_name) {
		try {
			fstream fin(file_name);
			if (fin.is_open()) {
				while (!fin.eof()) {
					char tmp_buffer[1];
					string tmp_number;
					string tmp_route;
					string tmp_initials;

					fin >> tmp_route;
					if (!is_number(tmp_route)) {
						throw invalid_argument("Некорректно указан номер маршрута автобуса!");
					}

					fin >> tmp_number;
					if (!is_number(tmp_number)) {
						throw invalid_argument("Некорректно указан номер автобуса!");
					}

					fin.read(tmp_buffer, 1);
					getline(fin, tmp_initials);

					int dots_count = 0;
					for (int i = 0; i < tmp_initials.length(); i++) {
						if (tmp_initials[i] == '.') {
							dots_count++;
						}
					}
					if (dots_count != 2) {
						throw invalid_argument("Некорректно указаны фамилия и инициалы");
					}

					Bus tmp_bus(stoi(tmp_number), stoi(tmp_route), tmp_initials);
					in_depot.insert(pair<int, Bus>(stoi(tmp_number), tmp_bus));
				}
				fin.close();
			}
			else {
				throw invalid_argument("Не удалось открыть файл");
			}
		}
		catch (invalid_argument& error) {
			SetConsoleTextAttribute(handle, 4);
			cerr << error.what() << endl;
			SetConsoleTextAttribute(handle, 7);
		}
	};

	void send_bus(int number) {
		if (!(this->in_depot.empty())) {
			auto bus = this->in_depot.find(number);
			if (bus == this->in_depot.end()) {
				SetConsoleTextAttribute(handle, 4);
				cout << "В парке нет автобуса с таким номером" << endl << '\n';
				SetConsoleTextAttribute(handle, 7);
			}
			else {
				this->on_road.insert(pair<int, Bus>((*bus).first, (*bus).second));
				this->in_depot.erase(number);
			}
		}
		else {
			SetConsoleTextAttribute(handle, 4);
			cout << "Парк пуст" << endl << '\n';
			SetConsoleTextAttribute(handle, 7);
		}
	};

	void receive_bus(int number) {
		if (!(this->on_road.empty())) {
			auto bus = this->on_road.find(number);
			if (bus == this->on_road.end()) {
				SetConsoleTextAttribute(handle, 4);
				cout << "На маршруте нет автобуса с таким номером" << endl << '\n';
				SetConsoleTextAttribute(handle, 7);
			}
			else {
				this->in_depot.insert(pair<int, Bus>((*bus).first, (*bus).second));
				this->on_road.erase(number);
			}
		}
		else {
			SetConsoleTextAttribute(handle, 4);
			cout << "Нет автобусов в пути" << endl << '\n';
			SetConsoleTextAttribute(handle, 7);
		}
	};

	void display_buses_by_number() {
		cout << "-------------------------Список автобусов по их номерам-------------------------" << endl;
		cout << "********Автобусы в парке********" << endl;
		if (on_road.empty()) {
			cout << "Нет автобусов в парке" << endl;
		}
		for (auto& in_depot_iterator : this->in_depot) {
			cout << "Номер автобуса...: " << in_depot_iterator.first << endl;
			cout << "Номер маршрута...: " << in_depot_iterator.second.get_route() << endl;
			cout << "Инициалы водителя: " << in_depot_iterator.second.get_initials() << endl;
			cout << '\n';
		}
		
		cout << "********Автобусы в пути*********" << endl;
		if (on_road.empty()) {
			cout << "Нет автобусов в пути" << endl;
		}
		for (auto on_road_iterator : this->on_road) {
			cout << "Номер автобуса...: " << on_road_iterator.first << endl;
			cout << "Номер маршрута...: " << on_road_iterator.second.get_route() << endl;
			cout << "Инициалы водителя: " << on_road_iterator.second.get_initials() << endl;
			cout << '\n';
		}
	};

	void display_buses_by_route() {
		vector<pair<int, Bus>> in_depot_sorted;
		vector<pair<int, Bus>> on_road_sorted;
		for (auto& it : this->in_depot) {
			in_depot_sorted.push_back(it);
		}
		for (auto& it : this->on_road) {
			on_road_sorted.push_back(it);
		}
		sort(in_depot_sorted.begin(), in_depot_sorted.end());
		sort(on_road_sorted.begin(), on_road_sorted.end());

		cout << "-------------------------Список автобусов по их маршрутам-------------------------" << endl;
		cout << "********Автобусы в парке********" << endl;
		if (in_depot_sorted.empty()) {
			cout << "Нет автобусов в парке" << endl;
		}
		for (auto& in_depot_iterator : in_depot_sorted) {
			cout << "Номер автобуса...: " << in_depot_iterator.first << endl;
			cout << "Номер маршрута...: " << in_depot_iterator.second.get_route() << endl;
			cout << "Инициалы водителя: " << in_depot_iterator.second.get_initials() << endl;
			cout << '\n';
		}

		cout << "********Автобусы в пути*********" << endl;
		if (on_road_sorted.empty()) {
			cout << "Нет автобусов в пути" << endl;
		}
		for (auto on_road_iterator : on_road_sorted) {
			cout << "Номер автобуса...: " << on_road_iterator.first << endl;
			cout << "Номер маршрута...: " << on_road_iterator.second.get_route() << endl;
			cout << "Инициалы водителя: " << on_road_iterator.second.get_initials() << endl;
			cout << '\n';
		}
	};
};

int main() {
	setlocale(LC_ALL, "Russian");

	BusDepot bus_depot("Depot.txt");
	
menu:
	bus_depot.display_buses_by_route();
	cout << '\n';
	SetConsoleTextAttribute(handle, 2);
	cout << "Меню: " << endl;
	SetConsoleTextAttribute(handle, 8);
	cout << "1 - Отправить автобус" << endl;
	cout << "2 - Зафиксировать прибытие автобуса в парк" << endl;
	cout << "3 - Вывести список автобусов по номерам маршрутов" << endl;
	cout << "4 - Вывести список автобусов по номерам автобусов" << endl << '\n';
	cout << "0 - Выход" << endl;
	int user_input;
	SetConsoleTextAttribute(handle, 1);
	cout << "Выберите действие: ";
	enter_number(user_input);
	cout << '\n';
	SetConsoleTextAttribute(handle, 7);

	int bus_number;
	switch (user_input) {
	case 1:
		cout << "Введите номер автобуса: ";
		enter_number(bus_number);
		cout << endl;
		bus_depot.send_bus(bus_number);
		goto menu;
		break;
	case 2:
		cout << "Введите номер автобуса: ";
		enter_number(bus_number);
		cout << endl;
		bus_depot.receive_bus(bus_number);
		goto menu;
		break;
	case 3:
		bus_depot.display_buses_by_route();
		goto menu;
		break;
	case 4:
		bus_depot.display_buses_by_number();
		goto menu;
		break;
	default:
		SetConsoleTextAttribute(handle, 4);
		cout << "Некорректный номер действия!!! " << endl;
		cout << "@Выберите одно из действий (1, 2, 3, 4, 0)" << endl;
		goto menu;
		break;
	}

	return 0;
}