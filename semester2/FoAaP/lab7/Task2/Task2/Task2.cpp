#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void insertion_sort_ascending(vector<double>& sequence) {
	for (auto i = sequence.begin() + 1; i != sequence.end(); i++)
		for (auto j = i; j != sequence.begin() && *j < *(j - 1); j--)
			iter_swap(j - 1, j);
}

void insertion_sort_descending(vector<double>& sequence) {
	for (auto i = sequence.begin() + 1; i != sequence.end(); i++)
		for (auto j = i; j != sequence.begin() && *j > *(j - 1); j--)
			iter_swap(j - 1, j);
}

void input_vector_items(vector<double>& sequence) {
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

int main() {
	setlocale(LC_ALL, "Russian");

	try {
		vector<double> sequence;

		input_vector_items(sequence);
		print_vector_items(sequence);

		cout << "Сортировка вставками по возрастанию" << endl;
		insertion_sort_ascending(sequence);
		print_vector_items(sequence);

		cout << "Сортировка вставками по убыванию" << endl;
		insertion_sort_descending(sequence);
		print_vector_items(sequence);
	}
	catch (const char* error) {
		cerr << error << endl;
	}

	return 0;
}