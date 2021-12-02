#include "Department.h"
#include <iostream>
#include <string>

using namespace std;

Employee inputEmployee(void) {
	char male = 'м';
	char female = 'ж';
	Employee employee;

	cout << "Введите фамилию: ";
	cin >> employee.LastName;
	cout << "Введите имя: ";
	cin >> employee.FirstName;
	cout << "Введите отчество: ";
	cin >> employee.MiddleName;

Gender:
	cout << "Введите пол работника (м/ж): ";
	cin >> employee.Gender;
	if (employee.Gender == male || employee.Gender == female) {

	}
	else {
		cout << "Указаны некорректные данные! Повторите ввод!!!" << endl;
		goto Gender;
	}


	cout << "Введите специальность: ";
	cin >> employee.Speciality;

Age:
	cout << "Введите возраст: ";
	cin >> employee.Age;
	if (employee.Age == to_string((int)atof(employee.Age)) && atof(employee.Age) > 0 &&
		atof(employee.Age) - int(atof(employee.Age)) == 0) {

	}
	else {
		cout << "Указаны некорректные данные! Повторите ввод!!!" << endl;
		goto Age;
	}

WorkExperience:
	cout << "Введите опыт работы (в количестве лет): ";
	cin >> employee.WorkExperience;
	if (employee.WorkExperience == to_string((int)atof(employee.WorkExperience)) && atof(employee.WorkExperience) > 0
		&& atof(employee.WorkExperience) - int(atof(employee.WorkExperience)) == 0 && atof(employee.WorkExperience) < atof(employee.Age)) {
	}
	else {
		cout << "Указаны некорректные данные! Повторите ввод!!!" << endl;
		goto WorkExperience;
	}


YearOfBirth:
	cout << "Введите год рождения: ";
	cin >> employee.YearOfBirth;
	if (employee.YearOfBirth == to_string((int)atof(employee.YearOfBirth)) && atof(employee.YearOfBirth) > 0
		&& atof(employee.YearOfBirth) - int(atof(employee.YearOfBirth)) == 0) {

	}
	else {
		cout << "Указаны некорректные данные! Повторите ввод!!!" << endl;
		goto YearOfBirth;
	}

	return employee;
}

void outputEmployee(Employee Employee) {
	cout.width(9);
	cout.fill('0');
	cout << "Полное имя: " << Employee.LastName << " " << Employee.FirstName << " " << Employee.MiddleName << endl;
	cout << "Пол работника: " << Employee.Gender << endl;
	cout << "Возраст: " << Employee.Age << " (" << Employee.YearOfBirth << ")" << endl;
	cout << "Специальность и стаж работы (в количестве лет): " << Employee.Speciality << ", " << Employee.WorkExperience << endl;
	cout << "\n";
}


void inputDepartment(HumanResourcesDepartment* Department) {
	cout << "Введите название отдела: ";
	cin >> Department->Name;

Amount:
	cout << "Введите количество работников (не более " << MAX_EMPLOYEES << "): ";
	cin >> Department->Amount;
	if (Department->Amount == to_string((int)atof(Department->Amount)) && atof(Department->Amount) > 0
		&& atof(Department->Amount) - int(atof(Department->Amount)) == 0 && atof(Department->Amount) <= 30) {
	}
	else {
		cout << "Указаны некорректные данные! Повторите ввод!!!" << endl;
		goto Amount;
	}
	for (int i = 0; i < atof(Department->Amount); i++) {
		cout << "------------------------------------------------" << endl;
		cout << "Введите информацию о " << (i + 1) << " работнике\n";
		cout << "------------------------------------------------" << endl;
		Department->Employees[i] = inputEmployee();
	}
}

void outputDepartment(HumanResourcesDepartment Department) {
	cout << endl;
	cout << "*------------------------------------------------*" << endl;
	cout << "Список работников отдела \"" << Department.Name << "\"" << ": \n";
	cout << "*------------------------------------------------*" << endl;
	for (int i = 0; i < atof(Department.Amount); i++) {
		outputEmployee(Department.Employees[i]);
	}
	cout << "\n" << endl;
}

void outputListOfPensioners(HumanResourcesDepartment Department) {
	char male = 'м';
	char female = 'ж';
	cout << endl;
	cout << "*------------------------------------------------*" << endl;
	cout << "Список пенсионеров отдела \"" << Department.Name << "\"" << ": \n";
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