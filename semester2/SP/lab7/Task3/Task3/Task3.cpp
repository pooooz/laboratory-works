#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

bool isPositiveInt(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool isIntInRange(int n, int min, int max) {
    if (n >= min && n <= max) {
        return true;
    }
    return false;
}

class Student {
    string surname;
    int marks_sum;
    vector<int> marks;
public:
    Student(string surname, int math, int physics, int russian, int english) {
        this->surname = surname;
        this->marks.push_back(math);
        this->marks.push_back(physics);
        this->marks.push_back(russian);
        this->marks.push_back(english);

        this->sum_marks();
    }

    void print_student() {
        cout << setw(15) << this->surname << ' ';
        for (auto iter = this->marks.begin(); iter != this->marks.end(); iter++) {
            cout << setw(5) << *iter << '|';
        }
        cout << setw(5) << this->marks_sum;
        cout << endl;
    }

    void sum_marks() {
        int sum = 0;
        for (auto iter = this->marks.begin(); iter != this->marks.end(); iter++) {
            sum += *iter;
        }
        this->marks_sum = sum;
    }

    int get_marks_sum() {
        return this->marks_sum;
    }

    string get_surname() {
        return this->surname;
    }
};

class Students {
    int students_count = 0;
    int max_marks_sum = 0;
    vector<Student> students;

    void read(string file_surname) {
        ifstream file(file_surname);
        if (file.is_open()) {
            int count = 0;
            while (!file.eof()) {
                string tmp_surname;
                string math;
                string physics;
                string russian;
                string english;

                file >> tmp_surname;
                file >> math;
                file >> physics;
                file >> russian;
                file >> english;

                if (!isPositiveInt(math) || !isIntInRange(stoi(math), 0, 10) ||
                    !isPositiveInt(physics) || !isIntInRange(stoi(physics), 0, 10) ||
                    !isPositiveInt(russian) || !isIntInRange(stoi(russian), 0, 10) ||
                    !isPositiveInt(english) || !isIntInRange(stoi(english), 0, 10)) {
                    throw invalid_argument(
                        "\nНеверный формат данных. Каждая оценка должна быть положительным целым числом в диапазоне от 0 до 10 включительно"
                    );
                }

                this->students.push_back(Student(tmp_surname, stoi(math), stoi(physics), stoi(russian), stoi(english)));
                count++;
            }
            file.close();
            this->students_count = count;
        }
        else {
            throw invalid_argument("\nОшибка чтения файла");
        }
    }

    void print_info() {
        cout << setw(18) << "Фамилия" << setw(6) << "Мат" << '|' << setw(6) 
            << "Физ|" << setw(6) << "Русск|" << setw(6) << "Англ|" << setw(6) << "Сумма" << endl;
        cout << "------------------------------------------------=" << endl;
        for (int i = 0; i < this->students_count; i++) {
            cout << setw(2) << i + 1 << '|';
            this->students[i].print_student();
            cout << "------------------------------------------------=" << endl;
        }
        cout << "Максимальная сумма оценок: " << this->max_marks_sum << endl;
    }

    void find_max_marsk_sum() {
        for (auto iter = this->students.begin(); iter != this->students.end(); iter++) {
            int marks_sum = (*iter).get_marks_sum();
            if (marks_sum > this->max_marks_sum) {
                this->max_marks_sum = marks_sum;
            }
        }
    }

    void print_best_students() {
        cout << "Ученики с такой суммой оценок " << endl;
        for (auto iter = this->students.begin(); iter != this->students.end(); iter++) {
            if ((*iter).get_marks_sum() == this->max_marks_sum) {
                cout << '·' << (*iter).get_surname() << endl;
            }
        }
    }

public:
    Students() {
        try {
            this->read("data.txt");
            this->find_max_marsk_sum();
            this->print_info();
            this->print_best_students();
        }
        catch (invalid_argument& error) {
            cerr << error.what() << endl;
        }
    }
};

int main() {
	setlocale(LC_ALL, "Russian");

    Students small_class = Students();

	return 0;
}