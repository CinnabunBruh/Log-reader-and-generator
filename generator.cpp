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
    // TODO 1: поверни випадковий елемент вектора v
    return v[0];  // тимчасова заглушка - заміни на випадковий вибір
}

// Повертає випадковий час у форматі "YYYY-MM-DD HH:MM:SS".
string randomTime() {
    // TODO 2: згенеруй випадкові рік/місяць/день/години/хвилини/секунди.
    // Підказки:
    //  - місяць: rand() % 12 + 1, день: rand() % 28 + 1 (так простіше, ніж рахувати дні)
    //  - щоб числа були з нулем попереду (05, а не 5), використай
    //    to_string() і допиши "0" вручну, або <iomanip>: setw(2) << setfill('0')
    return "2026-01-01 00:00:00";  // тимчасова заглушка
}

int main() {
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

    // TODO 3: у циклі від 0 до count запиши в file рядок формату
    //   <time> | <level> | <message>
    // Використай randomTime(), randomFrom(LEVELS), randomFrom(MESSAGES).
    // Не забудь '\n' в кінці кожного рядка.

    file.close();
    cout << "Готово! Записано " << count << " рядків у log.txt\n";
    return 0;
}

// Ідеї для розвитку (коли основне працюватиме):
//  - щоб записи йшли за порядком часу, спочатку згенеруй їх, потім відсортуй
//  - зроби так, щоб ERROR траплявся рідше, ніж INFO
