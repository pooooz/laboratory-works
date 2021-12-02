#include <iostream>
#include "BinaryTree.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите количество элементов бинарного дерева: ";
	int n = 0;
	enterNumberI(n);
	long double* b = new long double[n];
	cout << "Введите элементы бинарного дерева: ";
	for (int i = 0; i < n; i++) enterNumberIR(b[i]);
	TREE* top;
	first(top, b[0]);
	for (int i = 1; i < n; i++)
		add(top, b[i]);
	cout << endl;
	print_tree_level(top, 0);

	cout << "\nВведите уровень: ";
	int level;
	enterNumberI(level);
	cout << recSumm(top, level) << endl;
	cout << endl;

	system("pause");
	return 0;
}