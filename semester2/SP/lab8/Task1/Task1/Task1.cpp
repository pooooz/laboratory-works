#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

bool isalpha_rus(char c) {
    return c >= 'а' && c <= 'я' || c >= 'А' && c <= 'Я'
        || c == 'ё' || c == 'Ё';
}

class FileTypedWithLetters {
    void resolve(string file_name) {
        ifstream file(file_name);
        if (file.is_open()) {
            int count = 0;
            while (!file.eof()) {
                char tmp_char;
                file >> tmp_char;

                if (!isalpha(tmp_char) && !isalpha_rus(tmp_char)) {
                    throw invalid_argument("\nФайл должен состоять только из букв");
                } 
            }
            file.close();
        }
        else {
            throw invalid_argument("\nОшибка чтения файла");
        }

        file.open(file_name);
        if (file.is_open()) {
            int count = 0;
            while (!file.eof()) {
                char tmp_char;
                file >> tmp_char;

                if (count % 2 == 0) {
                    cout << tmp_char;
                }
                count++;
            }
            cout << endl;
            file.close();
        }
        else {
            throw invalid_argument("\nОшибка чтения файла");
        }
    }

public:
    FileTypedWithLetters() {
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

    FileTypedWithLetters resolve = FileTypedWithLetters();

    return 0;
}