#include <iostream>
#include "Department.h"
#include <Windows.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	HumanResourcesDepartment Department;
	inputDepartment(&Department);
	insSort_descending(Department.Employees, atof(Department.Amount));
	outputDepartment(Department);

	outputListOfPensioners(Department);

	system("pause");
	return 0;
}
