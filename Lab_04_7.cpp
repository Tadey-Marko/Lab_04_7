#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h> // Потрібно для налаштування кодування консолі

using namespace std;

int main()
{
    // Встановлюємо кодування UTF-8 (65001) для коректного виводу кирилиці
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double xp, xk, dx, eps;

    // Введення вхідних даних
    cout << "Введіть xp (початкове x): ";
    cin >> xp;
    cout << "Введіть xk (кінцеве x): ";
    cin >> xk;
    cout << "Введіть dx (крок): ";
    cin >> dx;
    cout << "Введіть eps (точність): ";
    cin >> eps;

    cout << endl;
    // Вивід шапки таблиці
    cout << "------------------------------------------------------------" << endl;
    cout << "|" << setw(10) << "x"
        << "|" << setw(15) << "f(x) = exp(x^2)"
        << "|" << setw(15) << "Сума ряду S"
        << "|" << setw(12) << "К-сть (n)" << " |" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << fixed;

    double x = xp;
    while (x <= xk + dx / 2.0) // Цикл табуляції за аргументом x
    {
        int n = 0;
        double a = 1.0;  // Перший доданок a0 = 1
        double S = a;    // Початкова сума ряду

        // Ітераційний цикл обчислення суми ряду Тейлора
        do {
            n++;
            double R = (x * x) / n; // Коефіціент рекурентності
            a *= R;                  // Обчислення наступного доданка
            S += a;                  // Накопичення суми
        } while (fabs(a) >= eps);

        // Вивід рядка таблиці
        cout << "|" << setw(10) << setprecision(2) << x
            << "|" << setw(15) << setprecision(6) << exp(x * x)
            << "|" << setw(15) << setprecision(6) << S
            << "|" << setw(12) << n << " |" << endl;

        x += dx;
    }

    cout << "------------------------------------------------------------" << endl;

    return 0;
}