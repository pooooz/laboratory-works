#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    long double n, a, b;
    cout << "Введите количество элементов массива n: ";
    cin >> n;
	cout << endl;


    if (n >= 1 && n - int(n) == 0) {
		
		long double* Array = new long double[n];

		for (int i = 0; i < n; i++) {
			cout << "Введите " << i + 1 << " элемент массива: ";
			cin >> *(Array + i);
		}
		cout << endl;

		cout << "Первоначальный массив: [ ";
		for (int i = 0; i < n; i++) {
			cout << *(Array + i) << " ";
		}
		cout << "]\n" << endl;

		long double a, b;
		cout << "Укажите промежуток удаления элементов [a;b]" << endl;
		cout << "Введите a: ";
		cin >> a;
		cout << "Введите b: ";
		cin >> b;
		cout << endl;

		if (a <= b) {

			for (int i = 0; i < n; i++) {
				if (fabs(*(Array + i)) >= a && fabs(*(Array + i)) <= b) {
					for (int ix = i; ix < n - 1; ix++)
					{
						Array[ix] = Array[ix + 1];
					}
					n--;
					i--;
				}
			}

			cout << "Конечный массив: [ ";
			for (int i = 0; i < n; i++) {
				cout << *(Array + i) << " ";
			}
			cout << "]\n" << endl;
		}
		else {
			cout << "a должно быть меньше, чем b!!!" << endl;
		}

		delete[]Array;
    }
    else {
        cout << "Некорректный ввод!!!" << endl;
    }


    system("pause");
    return 0;
}
