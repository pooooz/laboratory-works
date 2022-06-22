#pragma once
#include <string>
#include <iostream>

// Предположим, что у каждой комнаты будет своя цена, которая зависит от типа этой комнаты

using namespace std;

class Room {
protected:
	string name;
	double area;
	double price;
	virtual void count_price() = 0;
public:
	Room(string name, double area);
	double get_price();
	double get_area();
	void print_info();
};

class Bathroom : public Room {
public:
	Bathroom(string name, double area);

	void count_price();
};

class Kitchen : public Room {
public:
	Kitchen(string name, double area);

	void count_price();
};


class RegularRoom : public Room {
public:
	RegularRoom(string name, double area);

	void count_price();
};