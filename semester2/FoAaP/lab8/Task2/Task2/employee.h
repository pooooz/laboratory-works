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
	int Work_exp;
	string Speciality;
	
	friend ostream& operator << (ostream& out, EMPLOYEE Employee);
	friend istream& operator >> (istream& in, EMPLOYEE& Employee);
	friend bool operator < (EMPLOYEE emp1, EMPLOYEE emp2);
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