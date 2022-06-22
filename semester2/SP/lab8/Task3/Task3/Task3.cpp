#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LineByLineReading {
	int more_than_thirty_characters_lines = 0;
	int more_than_three_spaces_lines = 0;
	int lines_that_starts_whith_T = 0;

    bool is_more_than_three_spaces(string str) {
        int spaces_count = 0;

        auto iter = str.begin();
        while (iter != str.end() && spaces_count <= 3) {
            if (*iter == ' ') {
                spaces_count++;
            }
            iter++;
        }
        return spaces_count > 3;
    }

    bool is_more_than_thirty_characters(string str) {
        return str.size() > 30;
    }

	void resolve(string file_name) {
        ifstream file(file_name);
        if (file.is_open()) {
            int count = 0;
            while (!file.eof()) {
                string tmp_line;
                getline(file, tmp_line);
                if (tmp_line[0] == 'T' || tmp_line[0] == 'Т') {
                    this->lines_that_starts_whith_T++;
                }
                if (this->is_more_than_three_spaces(tmp_line)) {
                    this->more_than_three_spaces_lines++;
                }
                if (this->is_more_than_thirty_characters(tmp_line)) {
                    this->more_than_thirty_characters_lines++;
                }
            }
            file.close();

            cout << "Количество строк, которые начинаются c \"T\": " << this->lines_that_starts_whith_T << endl;
            cout << "Количество строк, в которых больше, чем 3 пробела: " << this->more_than_three_spaces_lines << endl;
            cout << "количество строк, в которых больше, чем 30 символов: " << this->more_than_thirty_characters_lines << endl;
        }
        else {
            throw invalid_argument("\nОшибка чтения файла");
        }
	}
public:
	LineByLineReading() {
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

    LineByLineReading resolve = LineByLineReading();

	return 0;
}