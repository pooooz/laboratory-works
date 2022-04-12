#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <ctime>

#include "Employee.h"
#include "file_reader.h"

using namespace std;

void insSort_descending(Employee* employees[], double array_size) {
	Employee* temp;
	int index_of_previous;
	for (int i = 1; i < array_size; i++) {
		temp = employees[i];
		index_of_previous = i - 1;
		while (index_of_previous >= 0 && employees[index_of_previous]->work_experience < temp->work_experience) {
			employees[index_of_previous + 1] = employees[index_of_previous];
			employees[index_of_previous] = temp;
			index_of_previous--;
		}
	}
}

void print_employee(Employee* worker) {
	cout << "Работник.......: ";
	cout << worker->last_name << " ";
	cout << worker->first_name << " ";
	cout << worker->middle_name << endl;

	cout << "Дата рождения..: ";
	cout << setw(2) << setfill('0') << worker->birthdate.day << '.';
	cout << setw(2) << setfill('0') << worker->birthdate.month << '.';
	cout << setw(4) << setfill('0') << worker->birthdate.year << endl;

	cout << "Пол............: ";
	cout << worker->gender << endl;

	cout << "Полных лет.....: ";
	cout << worker->age << endl;

	cout << "Специальность..: ";
	cout << worker->speciality << endl;

	cout << "Стаж работы....: ";
	cout << worker->work_experience << endl;
	cout << '\n';
}

void print_employees(Employee* employees[], int size) {
	for (int i = 0; i < size; i++) {
		print_employee(employees[i]);
	}
}

void print_retired_workers(Employee* employees[], int size) {
	char male = 'м';
	char female = 'ж';
	for (int i = 0; i < size; i++) {
		if ((employees[i]->gender[0] == male && employees[i]->age >= 62)
		|| (employees[i]->gender[0] == female && employees[i]->age >= 57)) {
			print_employee(employees[i]);
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Employee* employees[MAX_EMPLOYEES];
	int size;

	try {
		read("data.txt", employees, size);
		cout << "***** Работники *****\n\n";
		insSort_descending(employees, size);
		print_employees(employees, size);
		cout << "********************************************\n";
		cout << "Сотрудники на пенсии!!!\n";
		cout << "********************************************" << endl;
		print_retired_workers(employees, size);

	}
	catch (invalid_argument error) {
			cerr << error.what() << endl;
	}

	return 0;
}