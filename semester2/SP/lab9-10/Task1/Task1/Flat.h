#pragma once
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "Rooms.h"

using namespace std;

class Flat {
	vector<Room*> rooms;
	double price = 0;
	double area = 0;
public:
	Flat(vector<Room*> rooms);
	void print_info();
	void sort();
	void find_room_by_area(double area);

	Flat(string file_name);
};

