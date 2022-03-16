#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void input_vector_items(vector<double> &sequence) {
	cout << "Введите последовательность дробных чисел (конец ввода - Ctrl+Z)\n";

	istream_iterator<double> cin_iterator(cin);
	istream_iterator<double> cin_end;

	while (cin_iterator != cin_end) {
		sequence.push_back(*cin_iterator);
		cin_iterator++;
	}

	if (sequence.begin() == sequence.end()) {
		throw "Вы не ввели ни одного элемента последовательности!";
	}
}

void print_vector_items(const vector<double> sequence) {
	vector<double>::const_iterator sequence_iterator = sequence.cbegin();
	cout << "Ваша последовательность: ";
	while (sequence_iterator != sequence.end()) {
		cout << *sequence_iterator << " ";
		sequence_iterator++;
	}
	cout << endl;
	cout << "\n";
}

// The sum of the elements of the sequence from the beginning to the last positive element (inclusive)
double task_6(vector<double> sequence) {
	double sum = 0;
	vector<double>::reverse_iterator last_positive = sequence.rbegin();
	
	bool is_all_negative = true;
	for (auto iter = sequence.begin(); iter != sequence.end(); iter++) {
		if (*iter > 0) 
			is_all_negative = false;
	}

	if (is_all_negative) {
		throw "Последовательность не содержит положительных элементов";
	}

	while (*last_positive <= 0) {
		last_positive++;
	}

	while (last_positive != sequence.rend()) {
		sum += *last_positive;
		last_positive++;
	}

	return sum;
}

int main() {
	setlocale(LC_ALL, "Russian");

	try {
		vector<double> sequence;

		input_vector_items(sequence);
		print_vector_items(sequence);

		cout << "Искомая сумма элементов: " << task_6(sequence) << endl;
	}
	catch (const char* error) {
		cerr << error << endl;
	}

	return 0;
}