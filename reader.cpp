// reader.cpp
// Програма читає log.txt, розбирає кожен рядок на частини
// і дозволяє відсортувати записи за time, level або message.
//
// Формат рядка у файлі:  2026-11-15 12:30:45 | INFO | Server started

#include <iostream>
#include <fstream>    // ifstream - читання з файлу
#include <string>
#include <vector>
#include <algorithm>  // sort
#define NOMINMAX      // щоб windows.h не ламав std::min / std::max
#include <windows.h>  // SetConsoleOutputCP - налаштування кодування консолі Windows

using namespace std;

// Один запис логу. struct - це "коробка", що зберігає кілька значень разом.
struct LogEntry {
    string time;     // "2026-11-15 12:30:45"
    string level;    // "INFO", "ERROR", ...
    string message;  // "Server started"
};

// Розбирає один рядок файлу на LogEntry.
LogEntry parseLine(const string& line) {
    LogEntry entry;
    // TODO 1: розділи line по символу '|'.
    // Підказки:
    //  - line.find('|') повертає позицію першого '|' (або string::npos, якщо нема)
    //  - line.substr(початок, довжина) відрізає шматок рядка
    //  - знайди першу '|' і другу '|', відріж три частини
    //  - у частин будуть зайві пробіли по краях - обріж їх (напиши функцію trim)
    return entry;
}

// Читає весь файл і повертає вектор записів.
vector<LogEntry> readFile(const string& filename) {
    vector<LogEntry> entries;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не вдалося відкрити " << filename << "\n";
        return entries;  // порожній вектор
    }

    string line;
    // TODO 2: читай файл рядок за рядком: while (getline(file, line)) { ... }
    // Для кожного непорожнього рядка виклич parseLine і додай результат
    // у entries через entries.push_back(...).

    return entries;
}

// Виводить записи на екран.
void printEntries(const vector<LogEntry>& entries) {
    // TODO 3: пройдись по entries (for (const LogEntry& e : entries))
    // і виведи time, level, message в одному рядку.
}

// Сортування. Приклад як сортувати за часом - решту зроби за аналогією.
void sortByTime(vector<LogEntry>& entries) {
    // sort приймає початок, кінець і "порівнювач" - функцію, що відповідає
    // на питання "чи a має стояти перед b?". Тут це лямбда: [](...) { ... }
    sort(entries.begin(), entries.end(),
         [](const LogEntry& a, const LogEntry& b) {
             return a.time < b.time;  // формат YYYY-MM-DD... сортується як звичайний текст
         });
}

void sortByLevel(vector<LogEntry>& entries) {
    // TODO 4: за аналогією з sortByTime, але порівнюй a.level і b.level.
    // Бонус: щоб порядок був не алфавітний, а за важливістю
    // (ERROR > WARNING > INFO > DEBUG), напиши функцію, що перетворює
    // level на число, і порівнюй числа.
}

void sortByMessage(vector<LogEntry>& entries) {
    // TODO 5: те саме для message.
}

int main() {
    // Кирилиця в консолі: вмикаємо UTF-8 для виводу і вводу.
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    vector<LogEntry> entries = readFile("log.txt");
    cout << "Прочитано записів: " << entries.size() << "\n";

    // Просте меню. Повторюється, поки користувач не обере 0.
    int choice = -1;
    while (choice != 0) {
        cout << "\n1 - сортувати за time\n"
             << "2 - сортувати за level\n"
             << "3 - сортувати за message\n"
             << "4 - показати як є\n"
             << "0 - вихід\n"
             << "Ваш вибір: ";
        cin >> choice;

        // TODO 6: залежно від choice виклич потрібну функцію сортування
        // (switch або if / else if), а потім printEntries(entries).
    }

    return 0;
}

// Ідеї для розвитку:
//  - фільтр: показати лише рядки з певним level (ERROR)
//  - пошук за підрядком у message (message.find("text"))
//  - сортування за спаданням (a.time > b.time)
//  - читати ім'я файлу з аргументів main(int argc, char* argv[])
