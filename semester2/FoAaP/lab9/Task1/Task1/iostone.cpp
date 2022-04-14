#include "iostone.h"
#include "Stone.h"

using namespace std;

istream& operator >> (istream& in, PreciousStone& Stone) {
	in >> Stone.name;
	in >> Stone.weight;
	in >> Stone.transparency;
	Stone.calculate_cost();
	return in;
};


istream& operator >> (istream& in, SemipreciousStone& Stone) {
	in >> Stone.name;
	in >> Stone.weight;
	in >> Stone.transparency;
	Stone.calculate_cost();
	return in;
};


ostream& operator << (ostream& out, StoneGroup Group) {
	out << "***************" << endl;
	out << "Камни в наличии" << endl;
	out << "***************" << endl;

	out << "\n";
	vector<Stone*>::iterator iter;
	iter = Group.Stones.begin();
	while (iter != Group.Stones.end()) {
		(*iter)->print_info();
		out << endl;
;		iter++;
	}
	out << "Количество камней в наличии: " << Group.Stones.size() << endl << '\n';
	return out;
}