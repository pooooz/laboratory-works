#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

default_random_engine randomEngine(time(NULL));

int get_random_number(int min, int max) {
	uniform_int_distribution<int> randomNum(min, max);
	return randomNum(randomEngine);
}

class Employee {
	vector<int> salary;
	int max_salary = 0;
	int max_salary_index;

public:
	Employee(vector<int> salary) {
		this->salary = salary;

		for (int i = 0; i < 3; i++) {
			if (this->salary[i] > this->max_salary) {
				this->max_salary = this->salary[i];
				this->max_salary_index = i;
			}
		}
	}

	void print_salary() {
		for (auto iter = this->salary.begin(); iter != this->salary.end(); iter++) {
			cout << setw(8) << *iter;
		}
	}

	void print_max_salary() {
		cout << setw(8) << this->max_salary;
	}

	int get_salary_by_month(int i) {
		return this->salary[i];
	}

	int get_max_salary_index() {
		return this->max_salary_index;
	}
};

// Не стану комментировать т.к я просто не хочу сидеть на практике 2 недели. Multimap был бы быстрее
// P.S Просто надеюсь, что это никто и никогда не увидит
class FirstQuarter {
	vector<Employee> employee;
	vector<int> max_month_salary;
	vector<int> max_month_salary_index;
	int count = 12;

	void calc_max_month_salary() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < this->count; j++) {
				int salary_by_month = this->employee[j].get_salary_by_month(i);
				if (salary_by_month > this->max_month_salary[i]) {
					this->max_month_salary[i] = salary_by_month;
					this->max_month_salary_index[i] = j;
				}
			}
		}
	}

	void print_info() {
		cout << "Работник   ";
		for (int i = 0; i < 3; i++) {
			cout << " Месяц " << i + 1;
		}
		cout << "    max";
		cout << endl;
		cout << "-------------------------------------------" << endl;
		for (int i = 0; i < this->count; i++) {
			cout << "Работник " << setw(2) <<  i + 1;
			this->employee[i].print_salary();
			this->employee[i].print_max_salary();
			cout << endl;
		}
		cout << setw(11) << "max";
		for (int i = 0; i < 3; i++) {
			cout << setw(8) << this->max_month_salary[i];
		}
		cout << endl;
		cout << '\n';
		for (int i = 0; i < this->count; i++) {
			cout << "Работник " << i + 1 << " получил максимальную зарплату в месяц " << this->employee[i].get_max_salary_index() + 1;
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < 3; i++) {
			cout << "В месяц " << i + 1 << " самую большую зарплату получил работник " << this->max_month_salary_index[i] + 1 << endl;
		}
	}
public:
	FirstQuarter() {
		employee.reserve(count);
		for (int i = 0; i < this->count; i++) {
			vector<int> temp;
			for (int i = 0; i < 3; i++) {
				this->max_month_salary.push_back(0);
				this->max_month_salary_index.push_back(0);
				temp.push_back(get_random_number(1000, 3000));
			}
			this->employee.push_back(Employee(temp));
		}
		calc_max_month_salary();
		print_info();
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	FirstQuarter first_quater = FirstQuarter();

	return 0;
}