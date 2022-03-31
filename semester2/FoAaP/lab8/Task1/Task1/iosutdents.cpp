#include "iostudents.h"
#include "students.h"
#include <iostream>
#include <iterator>
using namespace std;
// Ввод информации о студенте из входного потока
istream& operator >> (istream& in, STUDENT& Student) {
	in >> Student.LastName;
	in >> Student.FirstName;
	in >> Student.MiddleName;
	in >> Student.Number;
	return in;
}
// ======= Вывод информации о студенте в выходной поток ========
ostream& operator << (ostream& out, STUDENT Student) {
	// форматированный вывод полей объекта
	out.width(8);
	out.fill('0');
	out << Student.Number << " "
		<< Student.LastName << " "
		<< Student.FirstName[0] << ". "
		<< Student.MiddleName[0] << ".";
	return out;
}

// ======= Ввод информации о группе из входного потока =========
istream& operator >> (istream& in, GROUP& Group) {
	in >> Group.Name;
	Group.Students.clear();
	// ввод списка студентов с использованием итераторов
	istream_iterator<STUDENT>in_iter(in);
	istream_iterator<STUDENT>in_end;
	while (in_iter != in_end) {
		STUDENT stud = *in_iter;
		Group.Students.push_back(stud);
		in_iter++;
	}
	return in;
}

// ====== Вывод информации о группе в выходной поток ===========
ostream& operator << (ostream& out, GROUP Group) {
	out << "Список группы " << Group.Name << endl;
	// вывод списка студентов с использованием итераторов
	vector<STUDENT>::iterator iter;
	iter = Group.Students.begin();
	while (iter != Group.Students.end()) {
		out << *iter << endl;
		iter++;
	}
	return out;
}