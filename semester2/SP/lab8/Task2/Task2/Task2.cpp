#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class FileTypedWithNumbers {
    void resolve(string file_name) {
        ifstream file(file_name);
        if (file.is_open()) {
            while (!file.eof()) {
                string tmp_string;
                file >> tmp_string;

                for (int i = 0; i < tmp_string.size(); i++) {
                    if ((!isdigit(tmp_string[i]) && tmp_string[i] != '-') || 
                        tmp_string[i] == '.') {
                        throw invalid_argument("\nФайл должен состоять только из целых чисел");
                    }
                }
            }
            file.close();
        }
        else {
            throw invalid_argument("\nОшибка чтения файла");
        }

        ofstream output("out.txt");
        file.open(file_name);
        if (file.is_open()) {
            int evens_count = 0;
            while (!file.eof()) {
                string tmp_string;
                file >> tmp_string;
                if (stoi(tmp_string) % 2 == 0) {
                    output << tmp_string << ' ';
                    evens_count++;
                    if (evens_count % 5 == 0) {
                        output << '\n';
                    }
                }
            }
            file.close();
            cout << "Количество целых чисел в файле " << file_name << ": " << evens_count << endl;
        }
        else {
            throw invalid_argument("\nОшибка чтения файла");
        }
    }

public:
    FileTypedWithNumbers() {
        try {
            this->resolve("data.txt");
        }
        catch (invalid_argument& error) {
            cerr << error.what() << endl;
        }

    }
};


int main() {
    setlocale(LC_ALL, "Russian");

    FileTypedWithNumbers resolve = FileTypedWithNumbers();

    return 0;
}