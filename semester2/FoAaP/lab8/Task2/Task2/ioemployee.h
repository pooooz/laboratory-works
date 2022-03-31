#pragma once
#include "employee.h"
// Ввод информации о работнике из потока
istream& operator >> (istream& in, EMPLOYEE& Employee);
// Вывод информации о работнике в выходной поток
ostream& operator << (ostream& out, EMPLOYEE Employee);
// Ввод информации о группе из входного потока
istream& operator >> (istream& in, GROUP& Group);
// Вывод информации о группе в выходной поток
ostream& operator << (ostream& out, GROUP Group);