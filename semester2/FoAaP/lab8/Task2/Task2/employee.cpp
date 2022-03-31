#include "employee.h"
#include <algorithm>
// Оператор для сравнения двух работников между собой

bool operator < (EMPLOYEE emp1, EMPLOYEE emp2) {
	// сравниваем по опыту работы работников
	bool result = emp1.Work_exp < emp2.Work_exp;
	return result;
}

// =========== Метод для упорядочения списка группы
void GROUP::sort() {
	// выполняем сортировку контейнера Employees с помощью
	// библиотечного алгоритма sort
	std::sort(this->Employees.begin(), this->Employees.end());
}
