#include <iostream>
#include <vector>

using namespace std;

void enter_number(long double& n) {
	while (!(cin >> n) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

void enter_number(int& n) {
	while (!(cin >> n) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	vector<long double> subsequence1;

	cout << "Введите количество членов последовательности: " << endl;
	int n;
	enter_number(n);

	cout << "Заполните последовательность!" << endl;

	for (int i = 0; i < n; i++) {
		cout << "Введите " << i + 1 << " элемент: ";
		long double temp;
		enter_number(temp);
		subsequence1.push_back(temp);
	}

	cout << "\n";
	cout << "Входная последовательность: " << endl;
	cout << "[ ";
	for (int i = 0; i < n; i++) {
		cout << subsequence1[i] << ", ";
	}
	cout << "]" << endl;


	vector<long double> subsequence2;

	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (fabs(subsequence1[i]) < 1) {
			subsequence2.insert(subsequence2.begin() + counter, subsequence1[i]);
			counter++;
		}
		else {
			subsequence2.push_back(subsequence1[i]);
		}
	}

	cout << "\nВыходная последовательность: " << endl;
	cout << "[ ";
	for (int i = 0; i < n; i++) {
		cout << subsequence2[i] << ", ";
	}
	cout << "]" << endl;

	return 0;
}