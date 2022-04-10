#pragma once
#include "students.h"
// Ввод информации о студенте из потока
istream& operator >> (istream& in, STUDENT& Student);
// Вывод информации о студенте в выходной поток
ostream& operator << (ostream& out, STUDENT Student);
// Ввод информации о группе из входного потока
istream& operator >> (istream& in, GROUP& Group);
// Вывод информации о группе в выходной поток
ostream& operator << (ostream& out, GROUP Group);