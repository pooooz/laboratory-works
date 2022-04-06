#pragma once
#include <string>
#include <vector>
#include <iostream>

class Date {
public:
	int day;
	int month;
	int year;
};

using namespace std;
class EMPLOYEE {
	string LastName;
	string FirstName;
	string MiddleName;
	string Gender;
	string Birthdate;
	int Work_exp = 0;
	string Speciality;
	int Age = 0;
	
	friend ostream& operator << (ostream& out, EMPLOYEE Employee);
	friend istream& operator >> (istream& in, EMPLOYEE& Employee);
	friend bool operator < (EMPLOYEE emp1, EMPLOYEE emp2);
public:
	string get_Gender() {
		return this->Gender;
	}
	int get_Age() {
		return this->Age;
	}
};
// ------ описание объектного типа данных ГРУППА --------
class GROUP {
	string Name;
	vector<EMPLOYEE> Employees;
public:
	void sort();
	friend ostream& operator << (ostream& out, GROUP Group);
	friend istream& operator >> (istream& in, GROUP& Group);
};