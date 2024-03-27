#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <conio.h>

using namespace std;

int array_size() {
    int a;
    string a1;
    while (true) {
        try {
            cin >> a1;
            a = stof(a1);
            break;
        }
        catch (...) {
            cout << "Введите положительное число!" << endl;
        }
    }
    return a;
}

void norm_function(double n) {  
    double otvet=1; 
    for (double k = 2; k <= n; k+=2) {
        otvet = otvet * ((k / (k - 1)) * (k / (k + 1)));
    }

    cout << "Результат стандартной функции: " << otvet << endl;
}

double recurs_function(double n) {// вот рекурсивная функция
   if (n < 2)   return 1;
   return n / (n - 1) * n / (n + 1) * recurs_function(n - 2);
}


int main()
{
    setlocale(LC_ALL, "ru");
    while (1) {
        double n;

        cout << "Введите положительное число:";
        while (true) {
                n = array_size();
                if (n > 0) {
                    int g = static_cast<int>(n);
                    if (g % 2 != 0) {
                        cout << "Введите четное число!" << endl;
                        continue;
                    }
                    break;
                }
                else {
                    cout << "Введите положительное число:";
                }
            }

        norm_function(n);
        cout << "Результат рекурсивной функции: " << recurs_function(n) << endl;

        string continue_str;
        cout << "\nПовторить? Если да, то введите 1 или y: ";
        cin >> continue_str;
        if (!(continue_str == "1" || continue_str == "y")) {
            return 1;
        }
    }
    return 0;
}

//Найти максимальный элемент в массиве ai (i=1, ..., n), используя очевидное соотношение max(a1, ..., an) = max[max(a1, ..., an–1), an].