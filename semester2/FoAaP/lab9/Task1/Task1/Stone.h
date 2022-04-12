#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Stone {
protected:
	string name;
	double weight;
	int transparency;
	double cost;
	virtual void calculate_cost() = 0;
public:
	virtual void print_info() = 0;
	double get_cost();
	int get_transparency();
};


class PreciousStone : public Stone {
	void calculate_cost();
public:
	PreciousStone(string name, double weight, int transparency);
	void print_info();
	friend istream& operator >> (istream& in, PreciousStone& Stone);
};


class SemipreciousStone : public Stone {
	void calculate_cost();
public:
	SemipreciousStone(string name, double weight, int transparency);
	void print_info();
	friend istream& operator >> (istream& in, SemipreciousStone& Group);
};


class StoneGroup {
protected:
	vector<Stone*> Stones;
	vector<Stone*> Necklace;
public:
	void sort();
	void add(Stone* stone);
	void make_necklace(string transparency, int count);
	void necklace_info();
	friend ostream& operator << (ostream& out, StoneGroup Group);
};