#include "Stone.h"
#include <algorithm>
#include <string>

double Stone::get_cost() {
	return this->cost;
}

int Stone::get_transparency() {
	return this->transparency;
}

PreciousStone::PreciousStone(string name, double weight, int transparency) {
	this->name = name;
	if (this->name.length() == 0) {
		throw invalid_argument("Некорректно указано название камня");
	}

	this->weight = weight * 5;
	if (this->weight == 0) {
		throw invalid_argument("Некорректно указан вес камня");
	}

	this->transparency = transparency;
	if (this->transparency != 1 && this->transparency != 2 && this->transparency != 3) {
		throw invalid_argument("Некорректно указана прозрачность камня");
	}
	this->calculate_cost();
}

void PreciousStone::calculate_cost() {
	switch (this->transparency) {
	case 1: {
		this->cost = 1.53 * this->weight * 10;
		break;
	}
	case 2: {
		this->cost = 1.43 * this->weight * 10;
		break;
	}
	case 3: {
		this->cost = 1.23 * this->weight * 10;
		break;
	}
	default:
		break;
	}
}

void PreciousStone::print_info() {
	cout << "Название камня.......: " << this->name << endl;
	cout << "Драгоценность камня..: " << "Драгоценный" << endl;
	cout << "Вес камня (в каратах): " << this->weight << endl;
	cout << "Цена камня...........: " << this->cost << endl;
	switch (this->transparency) {
	case 1:
		cout << "Прозрачность.........: " << "Прозрачный" << endl;
		break;
	case 2:
		cout << "Прозрачность.........: " << "Полупрозрачный" << endl;
		break;
	case 3:
		cout << "Прозрачность.........: " << "Непрозрачный" << endl;
		break;
	}
}

SemipreciousStone::SemipreciousStone(string name, double weight, int transparency) {
	this->name = name;
	this->weight = weight * 5;
	this->transparency = transparency;
	this->calculate_cost();
}

void SemipreciousStone::calculate_cost() {
	switch (this->transparency) {
	case 1: {
		this->cost = 1.43 * this->weight * 10;
		break;
	}
	case 2: {
		this->cost = 1.27 * this->weight * 10;
		break;
	}
	case 3: {
		this->cost = 1.11 * this->weight * 10;
		break;
	}
	default:
		break;
	}
}

void SemipreciousStone::print_info() {
	cout << "Название камня.......: " << this->name << endl;
	cout << "Драгоценность камня..: " << "Полудрагоценный" << endl;
	cout << "Вес камня (в каратах): " << this->weight << endl;
	cout << "Цена камня...........: " << this->cost << endl;
	switch (this->transparency) {
	case 1:
		cout << "Прозрачность.........: " << "Прозрачный" << endl;
		break;
	case 2:
		cout << "Прозрачность.........: " << "Полупрозрачный" << endl;
		break;
	case 3:
		cout << "Прозрачность.........: " << "Непрозрачный" << endl;
		break;
	}
}

void StoneGroup::sort() {
	for (auto i = this->Stones.begin() + 1; i != this->Stones.end(); i++)
		for (auto j = i; j != this->Stones.begin() && (*j)->get_cost() > ( * (j - 1))->get_cost(); j--)
			iter_swap(j - 1, j);
}

void StoneGroup::add(Stone* stone) {
	this->Stones.push_back(stone);
}

void StoneGroup::make_necklace(string transparency, int count) {
	if (count < 0) {
		throw invalid_argument("Количество камней должно быть больше нуля");
	}
	if (count > this->Stones.size()) {
		throw invalid_argument("Количетво камней в ожерелье не может превышать количество камней в наличии");
	}


	std::transform(transparency.begin(), transparency.end(), transparency.begin(), tolower);
	if (!(transparency == "прозрачный" || transparency == "полупрозрачный" || transparency == "непрозрачный")) {
		throw invalid_argument("Нет такого параметра прозрачности");
	}

	int numerical_transparency;
	if (transparency == "прозрачный") {
		numerical_transparency = 1;
	}
	else if (transparency == "полупрозрачный") {
		numerical_transparency = 2;
	}
	else {
		numerical_transparency = 3;
	}

	vector<Stone*>::iterator iter;
	iter = this->Stones.begin();
	while(iter != this->Stones.end() && this->Necklace.size() != count) {
		if ((*iter)->get_transparency() == numerical_transparency) {
			this->Necklace.push_back(*iter);
		}
		iter++;
	}

	if (this->Necklace.size() < count) {
		this->Necklace.clear();
		throw invalid_argument("Не хватает камней такой прозрачности для изготовления ожерелья");
	}
}

void StoneGroup::necklace_info() {
	cout << "********" << endl;
	cout << "Ожерелье" << endl;
	cout << "********" << endl;

	long double necklace_cost = 0;
	vector<Stone*>::iterator iter;
	iter = this->Necklace.begin();
	while (iter != this->Necklace.end()) {
		(*iter)->print_info();
		necklace_cost += (*iter)->get_cost();
		cout << endl;
		iter++;
	}
	cout << "Стоимость ожерелья: " << necklace_cost << endl;
}

