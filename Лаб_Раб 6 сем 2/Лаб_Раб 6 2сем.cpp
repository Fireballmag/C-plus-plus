#include <iostream>
#include <algorithm>
#include <conio.h>
#include <string>
#include <math.h>
using namespace std;

double input() {
    double a;
    int size;
    string a1;
    while (true) {
        try {
            cin >> a1;
            size = a1.length();
            for (int i = 0; i < size; i++) {
                a1[i] = (a1[i] == '.') ? ',' : a1[i];
            }
            a = stof(a1);
            break;
        }
        catch (...) {
            cout << " Введите циферки, пожалуйста!" << endl;
            cout << " Значение переменной =";
        }
    }
    return a;
}

double F(double x) {	
	return log(x) - 5 * sin(x) * sin(x);
}

double interval_division(double a, double b, double e, int& iterations) {
	double res, x2;
	double y0, y1, y2;
	y0 = F(a);
	y1 = F(b);
	iterations = 0;
	do {
		iterations++;
		x2 = (a + b) / 2;
		y2 = F(x2);
		if (y0 * y2 > 0) {
			a = x2;
			y0 = y2;
		}
		else {
			b = x2;
			y1 = y2;
		}
	} while (b - a > e);	
	res = (a + b) / 2;
	return res;
}

double dx(double x, double eps) {
	return (F(x + eps) - F(x - eps)) / (2 * eps);
}

double Newton(double x1, double eps, int& c) {
	double x0;
	c = 0;
	do {
		x0 = x1;
		c++;
		x1 = x0 - F(x0) / dx(x0, eps);
	} while (fabs(x1 - x0) > eps);
	return x1;
}

int main()
{
	setlocale(LC_ALL, "ru");
	while (1) {
		double a, b, e, res, step;
		int iter, n = 0, choise;
		cout << " Если вы хотите проверить код без ввода значений(значения из методички [2,6]) - нажмите 1; \n Ввести свои примеры - нажать 2;  " << endl;
		cout << " Введите номер желаемого пункта: "; cin >> choise;
		switch (choise) {
		case 1:
			cout << " Заранее введенные значения\n a = 2 \n b = 6 \n e = 0.00001 \n Шаг = 0.1" << endl;
			a = 2; b = 6; e = 0.00001; step = 0.1;
			break;
		default:
			cout << " Введите значения: ";
			cout << " a = "; a = input();
			if (a < 0) {
				cout << " Область определения функции находится на промежутке от 0 до плюс бесконечности! Меняю а на 0!" << endl;
				a = 0;
			}
			cout << " b = "; b = input();
			while (b <= a) {
				cout << " b меньше а, введите b которая будет больше а!" << endl;
				cout << " b = "; b = input();
			}
			cout << " e = "; e = input();
			while (e < 0) {
				cout << " Введите положительное е! " << endl;
				cout << " e = "; e = input();
			}
			cout << " Шаг = "; step = input();
			while (step <= 0 || step <= e) {
				cout << " Шаг меньше нуля или е!" << endl;
				cout << " Шаг = "; step = input();
			}				
			break;
		}
		
		cout << " Метод деления отрезка пополам:" << endl;
		for (double i = a; i < b; i += step) {
			if (F(i) * F(i + step) < 0 ) {
				res = interval_division(i, i + step, e, iter);
				n++;
				cout << " Корень " << n << " : " << res << " | f(x)=" << F(res) << " | " << iter << " число делений\n";
			}
		}
		if (n == 0) { cout << " На данном промежутке нет корней!" << endl; }
		else {
			n = 0;
			cout << endl;
			cout << " Метод Ньютона" << endl;
			for (double x = a; x <= b; x += step) {
				if (F(x) * F(x + step) < 0) {
					n++; 
					res = Newton(x, e, iter);
					cout << " Корень " << n << " : " << res << " | f(x)=" << F(res) << " | " << iter << " итераций\n";
				}
			}
		}
		system(("echo plot [" + to_string((int)floor(a)) + ":" + to_string((int)ceil(b)) + +"] x * x - 10 * sin(x) * sin(x),0 | D:\\gnuplot\\bin\\gnuplot --persist").c_str());
		string continue_str;
		cout << " Хотите решить еще пример? Если да, то введите 1 или yes: ";
		cin >> continue_str;
		if (!(continue_str == "1" || continue_str == "yes" || continue_str == "y")) {
			return 1;
		}
	}
}