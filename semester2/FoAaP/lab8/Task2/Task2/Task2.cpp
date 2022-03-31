#include "employee.h"
#include "ioemployee.h"
#include <fstream>
#include <windows.h>

using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char FileName[100];
	cout << "Из какого файла вводить данные?\n";
	cin.getline(FileName, sizeof(FileName));
	GROUP Group;
	// создать поток для ввода данных из файла
	ifstream fin(FileName);
	if (fin.is_open()) {
		// прочитать группу из этого потока
		fin >> Group;
		// закрыть поток
		fin.close();
		// упорядочить группу
		Group.sort();
		// вывести группу в поток cout (на экран)
		cout << Group;
		cout << "В какой файл выводить данные?\n";
		cin.getline(FileName, sizeof(FileName));
		// создать поток для вывода данных в файл
		ofstream fout(FileName);
		if (fout.is_open())
		{      // записать группу в этот файл
			fout << Group;
			fout.close();
			cout << "Данные выведены в файл " << FileName << endl;
		}
		else
		{
			cout << "Ошибка записи в файл " << FileName << endl;
		}
	}
	else {
		cout << "Файл " << FileName << " не найден\n";
	}
	return 0;
}
