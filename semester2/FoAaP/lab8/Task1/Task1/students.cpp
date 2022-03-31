﻿#include "students.h"
#include <algorithm>
// Оператор для сравнения двух студентов между собой

bool operator < (STUDENT stud1, STUDENT stud2) {
	// сравниваем по номеру студенческого билета
	bool result = stud1.Number < stud2.Number;
	return result;
}

// =========== Метод для упорядочения списка группы
void GROUP::sort() {
	// выполняем сортировку контейнера Students с помощью
  // библиотечного алгоритма sort
	std::sort(this->Students.begin(), this->Students.end());
	// по умолчанию порядок сортировки контейнера определяется
	  // перегруженным оператором <
}
