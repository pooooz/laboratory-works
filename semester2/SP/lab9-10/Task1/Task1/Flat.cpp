#include "Flat.h"

void trim(string& str) {
	auto it = unique(str.begin(), str.end(), [](char lt, char rg) {return lt == ' ' && rg == ' '; });
	str.erase(it, str.end());

	const string WHITESPACE = " \n\r\t\f\v";

	size_t start = str.find_first_not_of(WHITESPACE);
	str = (start == std::string::npos) ? "" : str.substr(start);

	size_t end = str.find_last_not_of(WHITESPACE);
	str = (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

void str_tolowercase(string& str) {
	transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {return tolower(c); });
}

bool comp(Room* first, Room* second) {
	return first->get_price() > second->get_price();
}

Flat::Flat(vector<Room*> rooms) {
	this->rooms = rooms;

	double rooms_price = 0;
	for (auto iter = this->rooms.begin(); iter != this->rooms.end(); iter++) {
		rooms_price += (*iter)->get_price();
	}
}

Flat::Flat(string file_name) {
	vector <Room*> tmp_rooms;
	ifstream file("data.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			char buffer[255];
			string tmp_area;
			string initial_name;
			Room* tmp_room;
			char tmp_char_name[255];

			file >> tmp_area;
			file.read(buffer, 1);
			file.getline(tmp_char_name, 255);
			initial_name = string(tmp_char_name);

			int dots_count = 0;
			for (int i = 0; i < tmp_area.size(); i++) {
				if (!isdigit(tmp_area[i]) && tmp_area[i] != '.') {
					throw invalid_argument("\nПлощадь комнаты должна быть положительным числом");
				}
				if (tmp_area[i] == '.') {
					dots_count++;
				}
				if (dots_count > 1) {
					throw invalid_argument("\nНекорректный формат данных");
				}
			}
			if (stoi(tmp_area) <= 0) {
				throw invalid_argument("\nПлощадь не может быть меньшей либо равной нулю");
			}

			trim(initial_name);
			string name = initial_name;
			str_tolowercase(name);
			trim(name);
			name[0] = toupper(name[0]);
			replace(tmp_area.begin(), tmp_area.end(), '.', ',');

			if (name == "Ванная" || name == "Ванная комната" || name == "Ванна") {
				tmp_room = new Bathroom(name, stod(tmp_area));
				tmp_rooms.push_back(tmp_room);
			} else if (name == "Кухонная" || name == "Кухонная комната" || name == "Кухня") {
				tmp_room = new Kitchen(name, stod(tmp_area));
				tmp_rooms.push_back(tmp_room);
			}
			else {
				tmp_room = new RegularRoom(name, stod(tmp_area));
				tmp_rooms.push_back(tmp_room);
			}
		}
		file.close();

		this->rooms = tmp_rooms;
		for (auto iter = this->rooms.begin(); iter != this->rooms.end(); iter++) {
			this->price += (*iter)->get_price();
			this->area += (*iter)->get_area();
		}
	}
	else {
		throw invalid_argument("\nНевозможно найти файл");
	}
}

void Flat::print_info() {
	cout << "Комнат в квартире: " << this->rooms.size() << endl;
	cout << "Общая площадь квартиры: " << this->area << " (м^2)" << endl;
	cout << "Стоимость квартиры: " << '$' << this->price << endl;
	cout << "Перечень комнат: " << endl;
	cout << '\n';
	for (auto iter = this->rooms.begin(); iter != this->rooms.end(); iter++) {
		(*iter)->print_info();
		cout << '\n';
	}
}

void Flat::sort() {
	std::sort(this->rooms.begin(), this->rooms.end(), comp);
}

void Flat::find_room_by_area(double area) {
	cout << "Комнаты с указанной площадью: " << endl;
	for (auto iter = this->rooms.begin(); iter != this->rooms.end(); iter++) {
		if ((*iter)->get_area() == area) {
			cout << '\n';
			(*iter)->print_info();
		}
	}
}