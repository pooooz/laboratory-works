#include <iostream>

using namespace std;

template <typename n>
void enter_number(n& x) {
	while (!(cin >> x) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "������� ������������ ��������! ��������� ����!!!" << endl;
	}
}

class BoatInTheRiver {
	double boat_speed_in_still_water;
	double river_speed;
	double attitude;

	double resolve() {
		return this->attitude;
	}
public:
	BoatInTheRiver(double boat_speed_in_still_water, double river_speed) {
		try {
			if (boat_speed_in_still_water < 0 && river_speed < 0) {
				throw invalid_argument("����� ��� ���� �� ����� ����� ������������� ��������, ���� ��� �� �������� �������� �� ������� ���������!");
			}

			this->boat_speed_in_still_water = boat_speed_in_still_water;
			this->river_speed = river_speed;

			this->attitude = fabs(boat_speed_in_still_water + river_speed) / fabs(boat_speed_in_still_water - river_speed);
			cout << "\n�������� ������ �� �������: " << fabs(boat_speed_in_still_water + river_speed) << endl;
			cout << "�������� ������ ������ �������: " << fabs(boat_speed_in_still_water - river_speed) << endl;
			cout << "\n��������� �������� �� ������� � �������� ������ �������: " << this->resolve() << endl;

		} 
		catch(invalid_argument& error) {
			cerr << error.what() << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	double A;
	double B;
	cout << "������� �������� ������ (��/�): ";
	enter_number(A);
	cout << "������� �������� ���� (��/�): ";
	enter_number(B);
	BoatInTheRiver boat_in_the_river(A, B);

	return 0;
}