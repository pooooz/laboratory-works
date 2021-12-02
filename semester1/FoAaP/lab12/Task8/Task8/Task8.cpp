#include <iostream>
#include <Windows.h>
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"

using namespace std;

void enterNumber(int& n) {
    while (!(cin >> n) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
        cerr << "Введён неверный формат координат точки! Повторите ввод!!!" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введите количество элементов последовательности символов: ";
    int N = 0;
    enterNumber(N);

    //Stack realization
    char * arr = new char[N+1];
    cout << "Введите последовательность символов" << endl;

    for (int i = 0; i < N; i++) {
        cout << "Введите символ " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    Node_s* top = first_s(arr[0]);
    for (int i = 1; i < N; i++)push_s(&top, arr[i]);
    while (top)
        cout << pop_s(&top) << ' ';
    cout << "\n" << endl;


    Node_s* comp = first_s(arr[0]);
    for (int i = 1; i < N; i++)push_s(&comp, arr[i]);
    int i = 0;

    while (comp) {
        char temp = pop_s(&comp);
        if (temp != arr[i]) {
            cout << "Не симметрична!\n" << endl;
            break;
        }
        i++;
    }

    //Queue realization
    Node_q* pbeg = first_q(arr[N-1]);
    Node_q* pend = pbeg;
    for (int i = N-2; i >= 0; i--)add_q(&pend, arr[i]);
    int j = 0;
    while (pbeg) {
       char temp = del_q(&pbeg);
       if (temp != arr[j]) {
           cout << "Не симметрична!\n" << endl;
           break;
       }
       j++;
    }

    //Deque realization
    Node_d* pbeg_d = first_d(arr[N-1]);
    Node_d* pend_d = pbeg_d;
    for (int i = N-2; i >= 0; i--)addLast_d(&pend_d, arr[i]);
   
    int k = 0;
    while (pbeg_d) {
        char temp = delFirst_d(&pbeg_d);
        if (temp != arr[k]) {
            cout << "Не симметрична!\n" << endl;
            break;
        }
        k++;
    }


    system("pause");
    return 0;
}