#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename n>
void enter_number(n& x) {
	while (!(cin >> x) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

class ArrayFingElementChallenge {
	int length = 0;
	vector<double> arr;

	void print_array() {
		cout << "Ваш массив: ";
		for (auto iter = this->arr.begin(); iter != this->arr.end(); iter++) {
			cout << *iter << ' ';
		}
		cout << endl;
	}

	void print_rest_of_array() {
		double elem;
		cout << "Введите элемент для поиска: ";
		enter_number(elem);

		auto iter = find(this->arr.begin(), this->arr.end(), elem);
		cout << '\n';
		if (iter != this->arr.end()) {
			iter++;
			if (iter != this->arr.end()) {
				cout << "Элемент найден" << endl;
				cout << "Оставшаяся часть массива: ";
				for (iter; iter != this->arr.end(); iter++) {
					cout << *iter << ' ';
				}
			}
			else {
				cout << "Элемент является последним элементом массива, за ним ничего нет" << endl;
			}
		}
		else {
			cout << "Элемент не найден" << endl;
		}
	}

public:
	ArrayFingElementChallenge(int length) {
		try {
			if (length < 1) {
				throw invalid_argument("Длина массива не может быть меньше, чем 1");
			}

			this->length = length;

			for (int i = 0; i < length; i++) {
				double tmp;
				cout << "Введите элемент " << i + 1 << " массива: ";
				enter_number(tmp);
				this->arr.push_back(tmp);
			}
			cout << endl;

			sort(this->arr.begin(), this->arr.end());

			this->print_array();
			this->print_rest_of_array();
		}
		catch (invalid_argument& error) {
			cerr << error.what() << endl;
		}

	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество элементов массива: ";
	int n; 
	enter_number(n);

	ArrayFingElementChallenge resolve(n);

	return 0;
}