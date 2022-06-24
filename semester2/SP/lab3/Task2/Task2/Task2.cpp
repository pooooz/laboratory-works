#include <iostream>

using namespace std;

template <typename n>
void enter_number(n& x) {
	while (!(cin >> x) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
	}
}

class findFirstEvenPair {
	int first_index = 0;
	int second_index = 0;
	int count = 0;
	int* arr = 0;

	void print_sequence() {
		cout << "\nВаша последовательность: ";
		for (int i = 0; i < this->count; i++) {
			i != this->count - 1 ? cout << this->arr[i] << ", " : cout << this->arr[i];
		}
		cout << endl;
	}

	void find_solution() {
		int i = 0;
		bool isSolution = false;
		for (int i = 0; i < this->count; i++) {
			if (this->arr[i] % 2 == 0 && this->arr[i - 1] % 2 == 0) {
				this->first_index = i-1;
				this->second_index = i;
				isSolution = true;
				break;
			}
		}
		if (isSolution) {
			cout << "\nНайдена чётная пара!" << endl;
			cout << "Порядковый номер первого числа пары: " << this->first_index + 1 << endl;
			cout << "Порядковый номер второго числа пары: " << this->second_index + 1 << endl;
		}
		else {
			cout << "\nНе найдено чётной пары" << endl;
		}
	}

public:
	findFirstEvenPair(int count) {
		try {
			if (count < 2) {
				throw invalid_argument("Количество чисел в последовательности должно быть не меньше, чем 2");
			}
			this->count = count;
			this->arr = new int[count];
			
			for (int i = 0; i < count - 1; i++) {
				cout << "Введите значение элемента последовательности " << i + 1 << ": ";
				enter_number(this->arr[i]);
			}
			this->arr[count - 1] = 9999;

			print_sequence();
			find_solution();
		}
		catch (invalid_argument& error) {
			cerr << error.what() << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Введите количество элементов последовательности: ";
	int count;
	enter_number(count);

	findFirstEvenPair resolve(count);

	return 0;
}