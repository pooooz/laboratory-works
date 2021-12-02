#include "Department.h"
#include <iostream>
#include <string>

using namespace std;

Employee inputEmployee(void) {
	char male = '�';
	char female = '�';
	Employee employee;

	cout << "������� �������: ";
	cin >> employee.LastName;
	cout << "������� ���: ";
	cin >> employee.FirstName;
	cout << "������� ��������: ";
	cin >> employee.MiddleName;

Gender:
	cout << "������� ��� ��������� (�/�): ";
	cin >> employee.Gender;
	if (employee.Gender == male || employee.Gender == female) {

	}
	else {
		cout << "������� ������������ ������! ��������� ����!!!" << endl;
		goto Gender;
	}


	cout << "������� �������������: ";
	cin >> employee.Speciality;

Age:
	cout << "������� �������: ";
	cin >> employee.Age;
	if (employee.Age == to_string((int)atof(employee.Age)) && atof(employee.Age) > 0 &&
		atof(employee.Age) - int(atof(employee.Age)) == 0) {

	}
	else {
		cout << "������� ������������ ������! ��������� ����!!!" << endl;
		goto Age;
	}

WorkExperience:
	cout << "������� ���� ������ (� ���������� ���): ";
	cin >> employee.WorkExperience;
	if (employee.WorkExperience == to_string((int)atof(employee.WorkExperience)) && atof(employee.WorkExperience) > 0
		&& atof(employee.WorkExperience) - int(atof(employee.WorkExperience)) == 0 && atof(employee.WorkExperience) < atof(employee.Age)) {
	}
	else {
		cout << "������� ������������ ������! ��������� ����!!!" << endl;
		goto WorkExperience;
	}


YearOfBirth:
	cout << "������� ��� ��������: ";
	cin >> employee.YearOfBirth;
	if (employee.YearOfBirth == to_string((int)atof(employee.YearOfBirth)) && atof(employee.YearOfBirth) > 0
		&& atof(employee.YearOfBirth) - int(atof(employee.YearOfBirth)) == 0) {

	}
	else {
		cout << "������� ������������ ������! ��������� ����!!!" << endl;
		goto YearOfBirth;
	}

	return employee;
}

void outputEmployee(Employee Employee) {
	cout.width(9);
	cout.fill('0');
	cout << "������ ���: " << Employee.LastName << " " << Employee.FirstName << " " << Employee.MiddleName << endl;
	cout << "��� ���������: " << Employee.Gender << endl;
	cout << "�������: " << Employee.Age << " (" << Employee.YearOfBirth << ")" << endl;
	cout << "������������� � ���� ������ (� ���������� ���): " << Employee.Speciality << ", " << Employee.WorkExperience << endl;
	cout << "\n";
}


void inputDepartment(HumanResourcesDepartment* Department) {
	cout << "������� �������� ������: ";
	cin >> Department->Name;

Amount:
	cout << "������� ���������� ���������� (�� ����� " << MAX_EMPLOYEES << "): ";
	cin >> Department->Amount;
	if (Department->Amount == to_string((int)atof(Department->Amount)) && atof(Department->Amount) > 0
		&& atof(Department->Amount) - int(atof(Department->Amount)) == 0 && atof(Department->Amount) <= 30) {
	}
	else {
		cout << "������� ������������ ������! ��������� ����!!!" << endl;
		goto Amount;
	}
	for (int i = 0; i < atof(Department->Amount); i++) {
		cout << "------------------------------------------------" << endl;
		cout << "������� ���������� � " << (i + 1) << " ���������\n";
		cout << "------------------------------------------------" << endl;
		Department->Employees[i] = inputEmployee();
	}
}

void outputDepartment(HumanResourcesDepartment Department) {
	cout << endl;
	cout << "*------------------------------------------------*" << endl;
	cout << "������ ���������� ������ \"" << Department.Name << "\"" << ": \n";
	cout << "*------------------------------------------------*" << endl;
	for (int i = 0; i < atof(Department.Amount); i++) {
		outputEmployee(Department.Employees[i]);
	}
	cout << "\n" << endl;
}

void outputListOfPensioners(HumanResourcesDepartment Department) {
	char male = '�';
	char female = '�';
	cout << endl;
	cout << "*------------------------------------------------*" << endl;
	cout << "������ ����������� ������ \"" << Department.Name << "\"" << ": \n";
	cout << "*------------------------------------------------*" << endl;
	for (int i = 0; i < atof(Department.Amount); i++) {
		if ((Department.Employees[i].Gender == male && atof(Department.Employees[i].Age) >= 63) ||
			(Department.Employees[i].Gender == female && atof(Department.Employees[i].Age) >= 58)) {
			outputEmployee(Department.Employees[i]);
		}
	}
}

void insSort_descending(Employee* arrayPtr, double array_size) {
	Employee temp;
	int index_of_previous;
	for (int i = 1; i < array_size; i++) {
		temp = arrayPtr[i];
		index_of_previous = i - 1;
		while (index_of_previous >= 0 && atof(arrayPtr[index_of_previous].WorkExperience) < atof(temp.WorkExperience)) {
			arrayPtr[index_of_previous + 1] = arrayPtr[index_of_previous];
			arrayPtr[index_of_previous] = temp;
			index_of_previous--;
		}
	}
}