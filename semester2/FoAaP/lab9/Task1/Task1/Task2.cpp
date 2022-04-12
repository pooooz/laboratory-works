#include "Stone.h"
#include "iostone.h"
#include <fstream>
#include <windows.h>
#include <algorithm>

using namespace std;

template <class N>
void enter_number(N& n) {
	while (!(cin >> n) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	
	StoneGroup Group;
	try {
		ifstream fin("data.txt");

		string PreciousStones[] = { "Алмаз", "Рубин", "Сапфир", "Александрит" };
		string SemipreciousStones[] = { "Топаз", "Аквамарин", "Берилл" };

		if (fin.is_open()) {
			while (!fin.eof()) {
				Stone* tmp;
				string name;
				double weight;
				int transparency;

				fin >> name;
				fin >> weight;
				fin >> transparency;

				bool isPrecious = false;
				int counter = 0;
				for (int i = 0; i < sizeof(PreciousStones) / sizeof(string); i++) {
					if (name == PreciousStones[i]) {
						counter++;
						isPrecious = true;
						break;
					}
				}
				for (int i = 0; i < sizeof(SemipreciousStones) / sizeof(string); i++) {
					if (name == SemipreciousStones[i]) {
						counter++;
						break;
					}
				}

				if (counter != 1) {
					throw invalid_argument("Не удалось распознать ценность камня");
				}

				if (isPrecious) {
					tmp = new PreciousStone(name, weight, transparency);
				}
				else {
					tmp = new SemipreciousStone(name, weight, transparency);
				}
				
				Group.add(tmp);
			}
			fin.close();
			
			Group.sort();

			cout << Group;

			cout << "Введите количество камней для ожерелья: ";
			int stones_count;
			enter_number(stones_count);

			cout << "Введите значение прозрачности камня (Прозрачный, Полупрозрачный, Непрозрачный): ";
			string transparency;
			cin >> transparency;

			Group.make_necklace(transparency, stones_count);
			cout << endl;
			Group.necklace_info();
		}
	}
	catch (invalid_argument& err) {
		cerr << '\n' << err.what() << endl;
	}
	return 0;
}
