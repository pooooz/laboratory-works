#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void initializeArray(long double** arrayPtr, size_t n, size_t m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "������� ������� " << i << " , " << j << " : ";
			cin >> arrayPtr[i][j];
		}
	}
}

void displayArray(long double** arrayPtr, size_t n, size_t m) {
	cout << "\n��������� ������: \n" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(10) << arrayPtr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void deleteArray(long double** arrayPtr, size_t n, size_t m) {
	for (int i = 0; i < n; i++) {
		delete[]arrayPtr[i];
	}
	delete[]arrayPtr;
}

bool checkZeroes(long double** arrayPtr, double n, double m, int i) {
	for (int j = 0; j < m; j++) {
		if (arrayPtr[i][j] == 0) {
			cout << "� ������ " << i + 1 << " ��������� ����" << endl;
			return false;
		}

	}
	return true;
}

long double countProduct(long double** arrayPtr, size_t n, size_t m) {
	long double product = 1;

	for (int i = 0; i < n; i++) {
		if (checkZeroes(arrayPtr, n, m, i)) {
			for (int j = 0; j < m; j++) {
				product *= arrayPtr[i][j];
			}
		}
	}
	return product;
}



int main() {
	setlocale(LC_ALL, "Russian");
	

	char* n = new char[255];
	char* m = new char[255];


	cout << "������� ����������� ������� n x m" << endl;
	cout << "������� ���������� �������� n: ";
	cin >> n;
	cout << "������� ���������� �� ��������� m: ";
	cin >> m;

	double k = atof(n);
	double z = atof(m);


	if (n == to_string((int)atof(n)) && m == to_string((int)atof(m)) && k > 0 && z > 0 && k - int(k) == 0 && z - int(z) == 0) {
		long double** arrayPtr = new long double* [k];
		for (int i = 0; i < k; i++) {
			arrayPtr[i] = new long double[z];
		}

		initializeArray(arrayPtr, k, z);

		displayArray(arrayPtr, k, z);

		cout << "�������� ������������: " << countProduct(arrayPtr, k, z) << "\n" << endl;

		deleteArray(arrayPtr, k, z);
		
	}
	else {
		cout << "������������ ����\n" << endl;
	}

	system("pause");
	return 0;
}