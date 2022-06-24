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

class ArrayChallenge {
	int length;
	double* arr;

	double product = 1;
	double sum_of_six_elements = 0;
	double average = 0;

	void count_product() {
		for (int i = 0; i < this->length; i++) {
			this->product *= this->arr[i];
		}
	}

	void count_sum_of_six_elements() {
		for (int i = 0; i < 6; i++) {
			this->sum_of_six_elements += this->arr[i];
		}
	}

	void count_average() {
		double sum = 0;
		for (int i = 0; i < this->length; i++) {
			sum += this->arr[i];
		}
		this->average = sum / this->length;
	}

	void print_info() {
		cout << '\n';
		cout << "Произведение всех элементов массива: " << this->product << endl;
		cout << "Сумма первых шести элементов: " << this->sum_of_six_elements << endl;
		cout << "Среднее арифметическое всех элементов массива: " << this->average << endl;
	}

public:
	ArrayChallenge(int length) {
		try {
			if (length < 6) {
				throw invalid_argument("Массив должен содержать не меньше, чем 6 элементов");
			}
			this->length = length;
			this->arr = new double[length];

			for (int i = 0; i < length; i++) {
				cout << "Введите элемент " << i + 1 << " массива: ";
				enter_number(this->arr[i]);
			}

			count_product();
			count_sum_of_six_elements();
			count_average();
			print_info();
		}
		catch (invalid_argument& error) {
			cerr << error.what() << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Введите количество элементов массива (не меньше 6 из условия): ";
	int n;
	enter_number(n);

	ArrayChallenge resolve(n);

	return 0;
}