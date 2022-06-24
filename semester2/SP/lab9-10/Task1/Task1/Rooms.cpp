#include "Rooms.h"

Room::Room(string name, double area) {
	this->name = name;
	this->area = area;
};

double Room::get_price() {
	return this->price;
}

void Room::print_info() {
	cout << "Название комнаты: " << this->name << endl;
	cout << "Площадь комнаты: " << this->area << " (м^2)" << endl;
	cout << "Стоимость комнаты: " << '$' << this->price << endl;
}

double Room::get_area() {
	return this->area;
}

Bathroom::Bathroom(string name, double area) : Room(name, area) {
	this->count_price();
}

void Bathroom::count_price() {
	this->price = this->area * 627.124;
}

Kitchen::Kitchen(string name, double area) : Room(name, area) {
	this->count_price();
}

void Kitchen::count_price() {
	this->price = this->area * 527.912;
}

RegularRoom::RegularRoom(string name, double area) : Room(name, area) {
	this->count_price();
}

void RegularRoom::count_price() {
	this->price = this->area * 403.601;
}
