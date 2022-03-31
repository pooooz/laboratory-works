#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;
class STUDENT {
	string LastName;       // Фамилия
	string FirstName;      // Имя
	string MiddleName;     // Отчество
	int  Number;            // Номерстуденческого
	friend ostream& operator << (ostream& out, STUDENT Student);
	friend istream& operator >> (istream& in, STUDENT& Student);
	friend bool operator < (STUDENT stud1, STUDENT stud2);
};
// ------ описание объектного типа данных ГРУППА --------
class GROUP {
	string Name;              // Названиегруппы
	vector<STUDENT> Students; // Контейнер (вектор) студентов
public:
	void sort();              // Упорядочение списка студентов
	// дружественныефункции - операторы
	friend ostream& operator << (ostream& out, GROUP Group);
	friend istream& operator >> (istream& in, GROUP& Group);
};