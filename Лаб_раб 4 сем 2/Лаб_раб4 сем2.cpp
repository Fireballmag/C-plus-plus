#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <conio.h>
#include <iomanip>

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
            cout << "Введите циферки, пожалуйста!" << endl;
            cout << "Значение переменной=";
        }


    }
    return a;
}

struct lin_spisok {
    char bukva;
    lin_spisok* next;
};

int prior(char a) {
    switch (a) {
    case '*': case '/': return 3;
    case '+': case'-': return 2;
    case '(': return 1;
    default: return 0;
    }
}

void Ins(lin_spisok*& p, char& out) {
    lin_spisok* t = new lin_spisok;
    t->bukva = out;
    t->next = p;
    p = t;
}

void Outs(lin_spisok*& p, char& s){
    lin_spisok* t = p;
    s = p->bukva;
    p = p->next;
    delete t;
}

double result(char* str, int choise) {  
    int chek, r = 1;
    lin_spisok* begin = nullptr;
    char ss1, ss2, ssR = 'z' + 1, letters[81];     
    double op1, op2, res, mas[100];   

    if (choise == 1) {
        mas[0] = 8.6; mas[1] = 2.4; mas[2] = 5.1; mas[3] = 0.3; mas[4] = 7.9;
    }
    else {
        cout << " Введите значения переменных:" << endl;
        for (int k = 0; str[k] != '\0'; ++k) {
            if (str[k] >= 'a' && str[k] <= 'z') {
                if (k == 0) {
                    letters[k] = str[k];
                    letters[1] = '\0';
                    continue;
                }
                for (int i = 0; letters[i] != '\0'; ++i) {
                    if (letters[i] == str[k]) {
                        chek = 0;
                        break;
                    }
                    else { chek = 1; }
                }
                if (chek != 0) {
                    letters[r] = str[k];
                    letters[r + 1] = '\0';
                    r++;
                }
            }
        }

        for (int i = 0; letters[i] != '\0'; ++i) {
            cout << " " << letters[i] << " = ";
            mas[int(letters[i] - 'a')] = input();
            /*cin >> mas[int(letters[i] - 'a')];*/
        }
    }

    for (int i = 0; str[i] != '\0'; ++i) {
        if (!(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')) {
            Ins(begin, str[i]);
        }                
        else {
            Outs(begin, ss2);
            Outs(begin, ss1);
            op2 = mas[int(ss2 - 'a')];
            op1 = mas[int(ss1 - 'a')];
            switch (str[i]) {
                case '+': 	res = op1 + op2;   break;
                case '-': 	res = op1 - op2;   break;
                case '*': 	res = op1 * op2;   break;
                case '/': 	
                    if (op2 == 0) {
                        cout << "Один из делителей равен 0, т.к. деление на 0 невозможно, то 0 был заменен на 1!" << endl;
                        op2 = 1;
                    }
                    res = op1 / op2;   break;
            }
            mas[int(ssR - 'a')] = res;
            Ins(begin, ssR);
            ssR++;
        }		   
    }			   
    return res;
}

int main()
{
    setlocale(LC_ALL, "ru");
    while (1) {

    lin_spisok* t, * op = nullptr;
    char a, in[101], out[101], bufer, vvod ='\0';
    int k = 0, l = 0, amount_scobka=0, amount_close_scobka=0, choise;

    cout << " Если вы хотите проверить код на примере из методички - нажмите 1; \n Ввести свой пример - нажать 2;  " << endl;
    cout << " Введите номер желаемого пункта: "; cin >> choise;

    switch (choise) {
    case 1:
        cout << " Пример из методички: a/(b–c)*(d+e), со значениями a = 8.6, b = 2.4, c = 5.1, d= 0.3, e = 7.9;" << endl;
        in[0] = 'a'; in[1] = '/'; in[2] = '('; in[3] = 'b'; in[4] = '-'; in[5] = 'c'; in[6] = ')'; in[7] = '*'; in[8] = '('; in[9] = 'd'; in[10] = '+'; in[11] = 'e'; in[12] = ')'; in[13] = '\0';
        break;
    default:
        cout << " Введите формулу: ";
        for (int k = 0; vvod != 13; k++) {
            vvod = _getch();
            if (vvod == 13) {// enter
                if (amount_close_scobka < amount_scobka) {// Если есть не закрытые скобки
                    cout << "\n Не хватает закрывающих скобок! Добавляю!" << endl;
                    for (; amount_close_scobka != amount_scobka; k++) {
                        in[k] = ')';
                        amount_close_scobka++;
                    }
                    in[k] = '\0';
                }
                in[k] = '\0';
                continue;
            }
            if (vvod == 8 && k != 0) {// delete
                k--;
                if (in[k] == '(') { --amount_scobka; }
                if (in[k] == ')') { --amount_close_scobka; }
                in[k] = '\0';
                cout << "\n Введите формулу: ";
                for (int i = 0; in[i] != '\0'; i++) {
                    cout << in[i];
                }
                k--;
                continue;
            }
            if (k == 0 && ((vvod >= 'a' && vvod <= 'z') || vvod == '(')) {// первый символ
                if (vvod == '(') { amount_scobka++; }
                in[k] = vvod;
                cout << in[k];
                continue;
            }
            else { if (k == 0) { k--; continue; } }
            if (k > 0 && in[k - 1] == vvod && vvod != '(' && vvod != ')') {// не дает вводить два одинаковых символа
                k--;
                continue;
            }
            if (((in[k - 1] >= 'a' && in[k - 1] <= 'z') || (in[k - 1] == ')')) && (vvod >= 'a' && vvod <= 'z')) { //Знак между буквами
                k--;
                continue;
            }
            if ((in[k - 1] == '+' || in[k - 1] == '-' || in[k - 1] == '*' || in[k - 1] == '/') && vvod == ')') {// Чтобы нельзя было в скобках после знаков вместо переменной поставить сразу скобку
                k--;
                continue;
            }
            if (vvod == ')' && (in[k - 1] >= 'a' && in[k - 1] <= 'z') && in[k - 2] == '('){ k--; continue; }// (буква)
            if ((vvod == '(' && in[k - 1] == ')') || (vvod == ')' && in[k - 1] == '(')) { k--; continue; } // знак между скобками 
            if(((in[k - 1] == '+' || in[k - 1] == '-' || in[k - 1] == '*' || in[k - 1] == '/') || in[k - 1] == '(') && (vvod == '+' || vvod == '-' || vvod == '*' || vvod == '/')){ k--; continue; }// +- +/ -* и тд (+-
            if ((in[k - 1] >= 'a' && in[k - 1] <= 'z') && vvod == '(') { k--; continue; } // a(

            if (vvod == '(') { //Все со скобками
                amount_scobka++;
            }
            if (vvod == ')') {
                amount_close_scobka++;
            }
            if (vvod == ')' && amount_close_scobka > amount_scobka) {// нельзя чтобы этих ) было больше чем вот этих (
                amount_close_scobka--;
                k--;
                continue;
            }  

            if (k != 0 && ((vvod >= 'a' && vvod <= 'z') || vvod == '+' || vvod == '-' || vvod == '*' || vvod == '/' || vvod == '(' || vvod == ')')) {// все остальное 
                in[k] = vvod;
                in[k + 1] = '\0';
                cout << in[k];
            }
            else {
                k--;
                continue;
            }
        }    
        break;
    }


    for(int k = 0; in[k] != '\0';k++){
        if (in[k] >= 'a' && in[k] <= 'z') {
            bufer = '1';
        }
        else {
            bufer = in[k];
        }
        switch (bufer) {
        case '1': 	out[l] = in[k]; l++;   break;
        case '(': 	Ins(op, in[k]);   break;
        case ')': 	
            while (op->bukva != '(') {
                Outs(op, a);
                out[l] = a;
                l++;
            }
            t = op;
            op = op->next;
            delete t;
            break;
        default:
            while (op != nullptr && prior(op->bukva) >= prior(in[k])) {
                Outs(op, a);
                out[l] = a;
                l++;
            }
            Ins(op, in[k]);
            break;
        }
    }

    while (op != nullptr) {
        Outs(op, a);
        out[l] = a;
        l++;
    }

    out[l] = '\0';
    cout << "\n Обратная польская запись = " << out << endl;
    cout << " Результат ОПЗ = " << result(out, choise) << endl << endl;

    string continue_str;
    cout << "Хотите решить еще пример? Если да, то введите 1 или yes: ";
    cin >> continue_str;
    if (!(continue_str == "1" || continue_str == "yes" || continue_str == "y")) {        
        return 1;
    }
    else {
        in[0] = '\0';
    }
    }
    return 0;
}

