#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

struct Point {
    long double x;
    long double y;
};

struct Vector {
    long double x;
    long double y;
    long double length;
};

void enterNumber(long double& n) {
    while (!(cin >> n) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
        cerr << "Введён неверный формат координат точки! Повторите ввод!!!" << endl;
    }
}

void TaskA() {
   
}

void TaskC() {
    Point A;
    Point B;
    Point C;
    Point D;
    Vector AD;
    Vector BC;

    cout << "Вычисление длины средней линии трапеции, заданной координатами четырёх вершин" << endl;
    cout << "-----------------------------------------------------------------------------\n" << endl;

    cout << "Введите координаты точки A(x,y)" << endl;
    cout << "Введите A.x: ";
    enterNumber(A.x);
    cout << endl;

    cout << "Введите A.y: ";
    enterNumber(A.y);
    cout << endl;


    cout << "Введите координаты точки B(x,y)" << endl;
    cout << "Введите B.x: ";
    enterNumber(B.x);
    cout << endl;



    cout << "Введите B.y: ";
    enterNumber(B.y);
    cout << endl;
    
    cout << "Введите координаты точки C(x,y)" << endl;
    cout << "Введите C.x: ";
    enterNumber(C.x);
    cout << endl;

    cout << "Введите C.y: ";
    enterNumber(C.y);
    cout << endl;


    cout << "Введите координаты точки D(x,y)" << endl;
    cout << "Введите D.x: ";
    enterNumber(D.x);
    cout << endl;

    cout << "Введите D.y: ";
    enterNumber(D.y);
    cout << endl;

 


    AD.x = D.x - A.x;
    AD.y = D.y - A.y;
    AD.length = sqrt(AD.x * AD.x + AD.y * AD.y);

    BC.x = C.x - B.x;
    BC.y = C.y - B.y;
    BC.length = sqrt(BC.x * BC.x + BC.y * BC.y);


    long double middle_line = (AD.length + BC.length) / 2;

    cout << "Длина средней линии: " << middle_line;
}

void TaskE() {
    cout << "Определение координат четвёртой вершины ромба по заданным координатам первых трёх вершин" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;

    Point A;
    Point B;
    Point C;
    Point D;

    Point O;

    cout << "Введите координаты точки A(x,y)" << endl;
    cout << "Введите A.x: ";
    enterNumber(A.x);
    cout << endl;

    cout << "Введите A.y: ";
    enterNumber(A.y);
    cout << endl;


    cout << "Введите координаты точки B(x,y)" << endl;
    cout << "Введите B.x: ";
    enterNumber(B.x);
    cout << endl;

    cout << "Введите B.y: ";
    enterNumber(B.y);
    cout << endl;

    cout << "Введите координаты точки C(x,y)" << endl;
    cout << "Введите C.x: ";
    enterNumber(C.x);
    cout << endl;

    cout << "Введите C.y: ";
    enterNumber(C.y);
    cout << endl;

    cout << "Координаты точки D : D(" << A.x + C.x - B.x << "," << A.y + C.y - B.y << ")" << endl;
}

int main(int argc, char* argv[])
{
    ofstream cerrFile("errors.txt");
    cerr.rdbuf(cerrFile.rdbuf());
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (argc == 2 && argv[1] == to_string((int)atof(argv[1])) && atof(argv[1]) - int(atof(argv[1])) == 0)
    {
        switch (atoi(argv[1]))
        {
            case 1:
                TaskA();
                break;
            case 2:
                TaskC();
                break;
            case 3:
                TaskE();
                break;

        }
    }
    else
    {
        cout << "Введён неверный параметр! Повторите запуск программы с корректным параметром";
        cerr << "Введён неверный формат координат точки! Повторите ввод!!!" << endl;
    }
    cerrFile.close();
    return 0;
}