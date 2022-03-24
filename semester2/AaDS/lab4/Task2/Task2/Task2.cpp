#include <iostream>
#include <iomanip>

using namespace std;

template <typename n>
void enter_number(n& x) {
    while (!(cin >> x) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
    }
}

int** full_pole; //Само поле доски
int n; // размерность

//Все возможные ходы коня
int possible_moves[8][2] = {
    { -1, -2 },
    { -2, -1 },
    { -2, 1 },
    { -1, 2 },
    { 1, 2 },
    { 2, 1 },
    { 2, -1 },
    { 1, -2 }
};

//Обнулить поле
void begin_horse(int** pole, int size) {
    full_pole = pole;
    n = size;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            pole[i][j] = 0;
}

//Определить возможность хода
bool can_step(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

// Вывод поля
void out_pole() {
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setfill('0') << setw(2) << full_pole[i][j] << "  ";
        cout << endl;
    }
    cout << "\n";
}

//Поиск пути
int max_counter = 0;
bool find_moves(int x, int y, int counter) {
    if (counter > max_counter) {
        max_counter = counter;
    }

    full_pole[x][y] = counter;
    if (counter > n * n - 1)
        return true;

    //цикл проверки хода
    for (int i = 0; i < 8; i++) {
        int NxMove_x = x + possible_moves[i][0];
        int NxMove_y = y + possible_moves[i][1];
        if (can_step(NxMove_x, NxMove_y) && full_pole[NxMove_x][NxMove_y] == 0 && find_moves(NxMove_x, NxMove_y, counter + 1)) {
            return true;
        }
    }

    full_pole[x][y] = 0;
    counter--;
    return false;
}

int display_count = 1;
bool find_movesMax(int x, int y, int counter, int max_counter) {
    //Занимает начальную позицию (start_x, start_y)
    // и записываем счетчик 
    full_pole[x][y] = counter;

    if (counter == max_counter && display_count == 1) {
        out_pole();
        display_count--;
    }
    //Если пройдены все поля, то завершить
    if (counter > n * n - 1)
        return true;
    //цикл проверки хода(и следующего)
    for (int i = 0; i < 8; i++)
    {
        int NxMove_x = x + possible_moves[i][0];
        int NxMove_y = y + possible_moves[i][1];
        if (can_step(NxMove_x, NxMove_y) && full_pole[NxMove_x][NxMove_y] == 0 && find_movesMax(NxMove_x, NxMove_y, counter + 1, max_counter)) {
            return true;
        }
    }
    //Продолжение будет только если не сработало условие

    full_pole[x][y] = 0;
    counter--;
    return false;
}

//Начало
int main() {
    int** pole = NULL;
    setlocale(LC_ALL, "Russian");
    cout << "Введите размер доски (3 - 8): ";
    enter_number(n);
    if (n < 3 || n > 8) {
        cout << "\nНекорректный размер доски (из условия 3 - 8)\n";
        return -1;
    }

    //Выделить память под двумерный массив
    pole = new int* [n];
    for (int i = 0; i < n; i++)
        pole[i] = new int[n];

    //Заполнить поле нулями
    begin_horse(pole, n);

    //Если обход вернет положительное значение, то вывести поле.
    //Если нет, то повторить до максимального значения ходов, которое нашли при выполнении первого прохода
    if (find_moves(0, 0, 1)) {
        out_pole();
    }
    else {
        cout << "\nМаксимальное количество пройденных клеток: " << max_counter << endl;
        find_movesMax(0, 0, 1, max_counter);
        cout << "Решение не найдено\n";
    }

    return 0;
}