#include <Windows.h>
#include "Rooms.h"
#include "Flat.h"

using namespace std;

template <typename n>
void enter_number(n& x) {
	while (!(cin >> x) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const string FILE_NAME = "data.txt";

	try {
		Flat flat(FILE_NAME);
		flat.sort();
		flat.print_info();

		double area = 0;
		cout << "Введите площадь для поиска комнаты: ";
		enter_number(area);

		if (area <= 0) {
			throw invalid_argument("Комната не может иметь площадь меньшую или раную нулю");
		}

		flat.find_room_by_area(area);

	}
	catch (invalid_argument& error) {
		cerr << error.what() << endl;
	}

	return 0;
}