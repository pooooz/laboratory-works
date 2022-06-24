#define _USE_MATH_DEFINES
#include <iostream>

using namespace std;

template <typename n>
void enter_number(n& x) {
	while (!(cin >> x) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введено некорректное значение! Повторите ввод!!!: ";
	}
}

class FindDiagonalLength {
	double max_square_area = 0;
	int index = 0;

	void print_max_square() {
		cout << "\nМаксимальной является диагональ квадрата номер " << this->index + 1 << ", её длина: " 
			<< sqrt(this->max_square_area) * M_SQRT2 << endl;
	}

public:
	FindDiagonalLength(int squares_count) {
		try {
			if (squares_count <= 0) {
				throw invalid_argument("Количество квадратов должно быть больше, чем 0");
			}
			for (int i = 0; i < squares_count; i++) {
			input:
				double temp_area;
				cout << "Введите площадь квадрата " << i + 1 << ": ";
				enter_number(temp_area);

				if (temp_area <= 0) {
					cout << "\nНе хотелось бы, чтобы площадь квадрата была меньшей либо равной 0. Попрошу Вас повторить ввод!: ";
					goto input;
				}

				if (temp_area > max_square_area) {
					this->max_square_area = temp_area;
					this->index = i;
				}
			}
			print_max_square();
		}
		catch (invalid_argument& error) {
			cerr << error.what() << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	
	int squares_count;
	cout << "Введите количество квадратов: ";
	enter_number(squares_count);

	FindDiagonalLength resolve(squares_count);

	return 0;
}