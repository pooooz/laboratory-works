#include <iostream>

using namespace std;

class LuckyNumbers {
	int digits_sum(int i) {
		int sum = 0;
		while (i > 0) {
			sum += i % 10;
			i /= 10;
		}
		return sum;
	}

public:
	LuckyNumbers() {
		for (int i = 100000; i < 1000000; i++) {
			if (this->digits_sum(i % 1000) == this->digits_sum(i / 1000)) {
				cout << i << endl;
			}
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	LuckyNumbers();

	return 0;
}