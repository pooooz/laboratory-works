#include <iostream>
#include <fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	string file_name;
	cin >> file_name;

	ofstream fout(file_name);

	srand(4541);

	if (fout.is_open()) {
		for (int count = 0; count < 100000; ++count) {
			fout << rand() << ' ';

			if ((count + 1) % 5 == 0)
				fout << endl;
		}
		fout.close();
		cout << "Данные выведены в файл " << file_name << endl;
	}

	return 0;
}