#include <iostream>
#include <algorithm>
#include <iomanip>
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

double f(double x) {
	return x * x - 10 * sin(x) * sin(x);
}

double langr(double* x1, double* y, double x2, int n) {
	double p = 0;
	for (int k = 0; k < n; k++) {
		double e = 1;
		for (int i = 0; i < n; i++) {
			if (i != k) {
				e *= (x2 - x1[i]) / (x1[k] - x1[i]);
			}
		}
		p += e * y[k];		
	}
	return p;
}

double nwet(double* x1, double* y, double x2, int m) {
	double N = y[0], p = 1;
	double* d = new double[m + 1];
	for (int i = 1; i <= m; i++) {
		d[i] = y[i - 1];
	}
	for (int k = 1; k <= m - 1; k++) {
		for (int i = 1; i <= m - k; i++) {
			d[i] = (d[i] - d[i + 1]) / (x1[i - 1] - x1[i - 1 + k]);
		}
		p *= (x2 - x1[k - 1]);
		N += p * d[1];
	}
	delete[] d;
	return N;
}
//void output(TFun, double* m_x, double* m_y, double x, int m, double h1, double n, int choise) {
//	double y, maxr = 0, razn;
//	for (int i = 0; i < n; i++, x += h1) {
//		y = mn_langr(m_x, m_y, x, m);
//		razn = fabs(y - f(x));
//		if (razn > maxr) {
//			maxr = razn;
//		}
//		cout << " x = " << x << "\t\t f* = " << y << "\t\t |f* - f| = " << razn << endl;
//		cout << " Максимальная разница = " << maxr << endl;
//	}
//}

int main()
{
	setlocale(0, "ru");
	while (1) {
		double a, b, x, h, h1, y, bufer;
		int n, i, m, choise;
		cout << " Если вы хотите проверить код без ввода значений(значения из методички [0,3]) - нажмите 1; \n Ввести свои значения - нажать 2;  " << endl;
		cout << " Введите номер желаемого пункта: "; cin >> choise;
		switch (choise) {
		case 1:
			cout << " Заранее введенные значения\n a = 0 \n b = 3 \n m = 10 \n n = 10" << endl;
			a = 0; b = 3; m = 10, n = 10;
			break;
		default:
			cout << " Введите значения: ";
			cout << " a = "; a = input();
			cout << " b = "; b = input();
			if (a > b) {
				bufer = b; b = a; a = bufer;
			}
			cout << " m = "; m = input();
			while (m <= 0) {
				cout << " m меньше или равно нулю!" << endl;
				cout << " m = "; m = input();
			}
			cout << " n = "; n = input();
			while (n <= 0) {
				cout << " n меньше или равно нулю!" << endl;
				cout << " n = "; n = input();
			}
			break;
		}
		h = (b - a) / (m - 1.);
		h1 = (b - a) / (n - 1.);
		double *m_x = new double[m];
		double *m_y = new double[m];
		for (x = a, i = 0; i < m; i++) {
			m_x[i] = x;
			m_y[i] = f(x);
			x += h;
		}
		double maxr = 0, razn;
		setlocale(0, "en");
		for (x = a, i = 0; i < n; i++, x += h1) {
			y = langr(m_x, m_y,  x, m);
			razn = fabs(y - f(x));
			if (razn > maxr) {
				maxr = razn;
			}
			cout << " x = " << x << fixed << setprecision(5) << setw(10) << "\t\t f* = " << y << fixed << setprecision(5) << setw(10) << "\t\t |f* - f| = " << razn << endl;
			//string x_s = to_string(x);
			//string y_s = to_string(y);
			//replace(x_s.begin(), x_s.end(), '.', ',');
			system(("echo " + to_string(x) + " " + to_string(y) + " >> ./points_lagr").c_str());
			
		}
		setlocale(0, "ru");
		cout << " Максимальная разница = " << maxr << endl;

		maxr = 0;
		setlocale(0, "en");
		for (x = a, i = 0; i < n; i++, x += h1) {
			y = nwet(m_x, m_y, x, m);
			razn = fabs(y - f(x));
			if (razn > maxr) {
				maxr = razn;
			}
			cout << " x = " << x << fixed << setprecision(5) << setw(10) << " f* = " << y << fixed << setprecision(5) << setw(10) << "\t |f* - f| = " << razn << endl;
			system(("echo " + to_string(x) + " " + to_string(y) + " >> ./points_newt").c_str());
		}
		setlocale(0, "ru");
		cout << " Максимальная разница = " << maxr << endl;
		system(("echo plot [" + to_string((int)floor(a)) + ":" + to_string((int)ceil(b)) + +"] x * x - 10 * sin(x) * sin(x),0, \"points_newt\" with lines, \"points_lagr\" with lines | D:\\gnuplot\\bin\\gnuplot --persist").c_str());

		system("del points_newt");
		system("del points_lagr");

		delete[] m_x;
		delete[] m_y;
		string continue_str;
		cout << " Хотите решить еще пример? Если да, то введите 1 или yes: ";
		cin >> continue_str;
		if (!(continue_str == "1" || continue_str == "yes" || continue_str == "y")) {
			return 1;
		}
	}
}