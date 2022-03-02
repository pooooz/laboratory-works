#include "BinaryTree.h"
#include <iostream>
using namespace std;

void enterNumberI(int& n) {
	while (!(cin >> n) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

void enterNumberIR(long double& n) {
	while (!(cin >> n) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

void first(TREE*& top, long double d) {
	top = new TREE;
	top->d = d;
	top->left = top->right = NULL;
}

TREE* search(TREE* top, long double d) {
	TREE* pv = top, * ppv = pv;
	while (pv) {
		ppv = pv;
		if (d < pv->d) pv = pv->left;
		else pv = pv->right;
	}
	return ppv;
}

void add(TREE* top, long double d) {
	TREE* ppv, * pnew = new TREE;
	pnew->d = d;
	pnew->left = NULL;
	pnew->right = NULL;
	ppv = search(top, d);
	if (d < ppv->d) ppv->left = pnew;
	else ppv->right = pnew;
}

void print_tree_level(TREE* top, int level) {
	if (top) {
		print_tree_level(top->left, level + 1);
		for (int i = 0; i < level; i++)
			cout << "       ";
		cout << top->d << endl;
		print_tree_level(top->right, level + 1);
	}
}

void del_tree(TREE*& top) {
	if (top) {
		del_tree(top->left);
		del_tree(top->right);
		delete top;
		top = NULL;
	}
}

long double summLevel(TREE* tree, int lvl, long double& count) {
	if (lvl < 0) {
		return 0;
	}
	if (tree == nullptr) {
		return 0;
	}
	if (lvl == 0)
	{
		++count;
		return tree->d;
	}
	return summLevel(tree->right, lvl - 1, count) + summLevel(tree->left, lvl - 1, count);
}
long double recSumm(TREE* tree, int lvl) {
	long double count = 0;
	float summ = summLevel(tree, lvl, count);
	if (count == 0)
		return 0;
	return summ / count;
}
