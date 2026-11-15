// generator.cpp
// Програма створює файл log.txt з випадковими записами.
// Формат одного рядка (поля розділені символом '|'):
//   2026-11-15 12:30:45 | INFO | Server started
//   ^ time              ^ level  ^ message

#include <iostream>  // cout, cin
#include <fstream>   // ofstream - запис у файл
#include <string>    // string
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include <vector>    // vector - "розумний" масив
#include <sstream>   // ostringstream - збирання рядка з частин
#include <iomanip>   // setw, setfill - форматування чисел
#define NOMINMAX      // щоб windows.h не ламав std::min / std::max
#include <windows.h>  // SetConsoleOutputCP - налаштування кодування консолі Windows

using namespace std;

// Можливі рівні логів. Генератор вибиратиме один з них випадково.
const vector<string> LEVELS = {"INFO", "WARNING", "ERROR", "DEBUG"};

// Можливі тексти повідомлень. Додай свої!
const vector<string> MESSAGES = {
    "Server started",
    "User logged in",
    "Connection lost",
    "File not found",
    "Disk space low"
};

// Повертає випадковий рядок з вектора.
// Підказка: rand() % v.size() дає випадковий індекс від 0 до size-1.
string randomFrom(const vector<string>& v) {
    if (v.empty()) {
        return "";  // якщо вектор порожній, повертаємо порожній рядок
    }
    size_t index = rand() % v.size();
    return v[index];
}

// Повертає випадковий час у форматі "YYYY-MM-DD HH:MM:SS".
string randomTime() {
    int year = 2026;
    int month = 1 + rand() % 12;  // від 1 до 12
    int day = 1 + rand() % 28;    // від 1 до 28
    int hour = rand() % 24;       // від 0 до 23
    int minute = rand() % 60;     // від 0 до 59
    int second = rand() % 60;     // від 0 до 59

    ostringstream result;
    result << year << "-"
           << setw(2) << setfill('0') << month << "-"
           << setw(2) << setfill('0') << day << " "
           << setw(2) << setfill('0') << hour << ":"
           << setw(2) << setfill('0') << minute << ":"
           << setw(2) << setfill('0') << second;

    return result.str();  // перетворюємо потік у звичайний string
}

int main() {
    // Кирилиця в консолі: вмикаємо UTF-8 для виводу і вводу.
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    srand(time(nullptr));  // "зерно" для rand(), щоб кожен запуск давав різні числа

    int count;
    cout << "Скільки записів згенерувати? ";
    cin >> count;

    // Відкриваємо файл для запису. ios::trunc = стерти старий вміст.
    ofstream file("log.txt", ios::trunc);
    if (!file.is_open()) {
        cout << "Не вдалося відкрити log.txt\n";
        return 1;  // ненульовий код = помилка
    }

    for (int i = 0; i < count; ++i) {
        file << randomTime() << " | "
            << randomFrom(LEVELS) << " | "
            << randomFrom(MESSAGES) << '\n';
    }


    file.close();
    cout << "Готово! Записано " << count << " рядків у log.txt\n";
    return 0;
}

// Ідеї для розвитку (коли основне працюватиме):
//  - щоб записи йшли за порядком часу, спочатку згенеруй їх, потім відсортуй
//  - зроби так, щоб ERROR траплявся рідше, ніж INFO
