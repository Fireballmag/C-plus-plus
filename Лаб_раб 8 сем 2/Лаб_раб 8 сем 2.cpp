#include <iostream>
#include <algorithm>
#include <conio.h>
#include <string>
#include <math.h>
using namespace std;

typedef double (*TFun)(double, double, int);

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

double f(double x) {
	return x*x - 10*sin(x)*sin(x);
}

double trapeze(double a, double b, int n) {
	double h = (b - a) / n, sum = 0;
	do {
		sum += (f(a) + f(a + h)) / 2;
		a += h;
	} while (a + h <= b);
	return sum * h;
}
double Simps(double a, double b, int n) {
	double s = 0, h, x;
	h = (b - a) / n;
	x = a;
	for (int i = 1; i <= n; i++) {
		s += f(x) + 4 * f(x + h / 2) + f(x + h);
		x += h;
	}
	return s * h / 6;
}

double eps(TFun f, double a, double b, double e, int& n) {
	n = 2;
	double bufer = f(a, b, n), bufer2, diff;
	do {
		n *= 2;
		bufer2 = f(a, b, n);
		diff = fabs(bufer - bufer2);
		bufer = bufer2;
	} while (diff > e);
	return bufer;
}

int main()
{
	setlocale(0, "ru");
	while (1) {	
		double a, b , e, bufer;
		int n, choise; 
		cout << " Если вы хотите проверить код без ввода значений(значения из методички [0,3]) - нажмите 1; \n Ввести свои значения - нажать 2;  " << endl;
		cout << " Введите номер желаемого пункта: "; cin >> choise;
		switch (choise) {
		case 1:
			cout << " Заранее введенные значения\n a = 0 \n b = 3 \n e = 0.0001 \n n = 10:" << endl;
			a = 0; b = 3; e = 0.0001; n = 10;
			break;
		default:
			cout << " Введите значения: ";
			cout << " a = "; a = input();
			cout << " b = "; b = input();
			if (a > b) {
				bufer = b; b = a; a = bufer;
			}
			cout << " e = "; e = input();
			while (e <= 0) {
				cout << " Введите положительное е! " << endl;
				cout << " e = "; e = input();
			}
			cout << " n = "; n = input();
			while (n <= 0 || n <= e) {
				cout << " n меньше нуля или е!" << endl;
				cout << " n = "; n = input();
			}
			break;
		}
		cout << " Метод трапеций: = " << trapeze(a, b, n);
		cout << "\n Метод Симпсона = " << Simps(a, b, n) << endl;
		cout << "\n Значение метода Симпсона при заданной точности = " << eps(Simps, a, b, e, n); cout << "\t количество разбиений = " << n << endl;
		cout << " Значение метода трапеций при заданной точности = " << eps(trapeze, a, b, e, n); cout << "\t количество разбиений = " << n << endl;

		string continue_str;
		cout << " Хотите решить еще пример? Если да, то введите 1 или yes: ";
		cin >> continue_str;
		if (!(continue_str == "1" || continue_str == "yes" || continue_str == "y")) {
			return 1;
		}
	}
}