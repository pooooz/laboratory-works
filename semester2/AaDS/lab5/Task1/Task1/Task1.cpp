#include <iostream>

using namespace std;

int grid[8][8];
int solution_count = 0;

void print(int n) {
    solution_count++;
    for (int i = 0; i <= n - 1; i++) {
        for (int j = 0; j <= n - 1; j++) {

            cout << grid[i][j] << " ";

        }
        cout << endl;
    }
    cout << "Решение: " << solution_count << endl;
    cout << endl;
    cout << endl;
}
bool isSafe(int col, int row, int n) {
    // Проверка на одну вертикаль
    for (int i = 0; i < row; i++) {
        if (grid[i][col]) {
            return false;
        }
    }
    // Проверка на верхнюю диагональ
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (grid[i][j]) {
            return false;
        }
    }
    // Проверка на нижнюю диагональ
    for (int i = row, j = col; i >= 0 && j < n; j++, i--) {
        if (grid[i][j]) {
            return false;
        }
    }
    return true;
}

bool solve(int n, int row) {
    if (n == row) {
        print(n);
        return true;
    }
    bool res = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(i, row, n)) {
            grid[row][i] = 1;
            res = solve(n, row + 1) || res;

            grid[row][i] = 0;
        }
    }
    return res;
}
int main() {
    setlocale(LC_ALL, "Russian");

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            grid[i][j] = 0;
        }
    }
    bool res = solve(8, 0);
    if (!res) {
        cout << "Нет решения" << endl;
    }
    else {
        cout << endl;
    }

    return 0;
}