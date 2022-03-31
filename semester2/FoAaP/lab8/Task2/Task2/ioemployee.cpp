#define _CRT_SECURE_NO_WARNINGS
#include "ioemployee.h"
#include "employee.h"
#include <iostream>
#include <iomanip>
#include <iterator>
using namespace std;

Date convert(string str) {
	Date result;
	char* context = NULL;
	char* str_number = strtok_s((char*)str.c_str(), ".", &context);
	result.day = atoi(str_number);
	str_number = strtok_s(NULL, ".", &context);
	result.month = atoi(str_number);
	str_number = strtok_s(NULL, ".", &context);
	result.year = atoi(str_number);
	return result;
}

int get_age(int day, int month, int year) {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int age;

	age = (ltm->tm_year + 1900) - year;
	if (month > ltm->tm_mon + 1)
		age--;
	else if ((month == ltm->tm_mon + 1) && (day > ltm->tm_mday))
		age--;

	return age;
}

// Ввод информации о работнике из входного потока
istream& operator >> (istream& in, EMPLOYEE& Employee) {
	in >> Employee.LastName;
	in >> Employee.FirstName;
	in >> Employee.MiddleName;
	in >> Employee.Gender;
	in >> Employee.Birthdate;
	in >> Employee.Work_exp;
	char buffer[1];
	char char_buffer[255];
	in.read(buffer, 1);
	in.getline(char_buffer, 255);
	Employee.Speciality = string(char_buffer);
	return in;
}
// ======= Вывод информации о работнике в выходной поток ========
ostream& operator << (ostream& out, EMPLOYEE Employee) {
	// форматированный вывод полей объекта
	out << "Работник.......: ";
	out << Employee.LastName << " ";
	out << Employee.FirstName << " ";
	out << Employee.MiddleName << endl;

	Date temp_date;
	temp_date = convert(Employee.Birthdate);
	out << "Дата рождения..: ";
	out << setw(2) << setfill('0') << temp_date.day << '.';
	out << setw(2) << setfill('0') << temp_date.month << '.';
	out << setw(4) << setfill('0') << temp_date.year << endl;

	out << "Пол............: ";
	out << Employee.Gender << endl;

	int age = get_age(temp_date.day, temp_date.month, temp_date.year);
	out << "Полных лет.....: ";
	out << age << endl;

	out << "Специальность..: ";
	out << Employee.Speciality << endl;

	out << "Стаж работы....: ";
	out << Employee.Work_exp<< endl;
	out << '\n';
	return out;
}

// ======= Ввод информации о группе из входного потока =========
istream& operator >> (istream& in, GROUP& Group) {
	char temp[255];
	in.getline(temp, 255);
	Group.Name = string(temp);
	Group.Employees.clear();
	// ввод списка работников с использованием итераторов
	istream_iterator<EMPLOYEE>in_iter(in);
	istream_iterator<EMPLOYEE>in_end;
	while (in_iter != in_end) {
		EMPLOYEE stud = *in_iter;
		Group.Employees.push_back(stud);
		in_iter++;
	}
	return in;
}

// ====== Вывод информации о группе в выходной поток ===========
ostream& operator << (ostream& out, GROUP Group) {
	out << "Список сотрудников \"" << Group.Name << "\"" << endl;
	out << "\n";
	// вывод списка работников с использованием итераторов
	vector<EMPLOYEE>::iterator iter;
	iter = Group.Employees.begin();
	while (iter != Group.Employees.end()) {
		out << *iter << endl;
		iter++;
	}
	return out;
}