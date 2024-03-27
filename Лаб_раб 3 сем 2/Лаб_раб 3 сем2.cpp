#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <conio.h>

using namespace std;

struct lin_spisok {
    int chislo;
    lin_spisok* next, *prev;
};


//cout << "Просмотр с начала:"; prosmotr(tail, 0);
//cout << "Просмотр с конца:"; prosmotr(head, 1);

void prosmotr(lin_spisok* t) {

    cout << "From Begin" << endl;
    while (t->next) {
        cout << t->chislo << "\t";
        t = t->next;
    }
    cout << t->chislo << "\n";
    cout << "From End" << endl;
       while (t) {
            cout << t->chislo << "\t";
            t = t->prev;
        }
       cout << endl;
    }

//void prosmotr(lin_spisok* tail, lin_spisok* head) {
//    cout << "Просмотр с начала:";
//    while (tail) {
//        cout << " " << tail->chislo << "\t";
//        tail = tail->next;
//    }
//    cout << "Просмотр с конца:";
//    while (tail) {
//        cout << " " << head->chislo << "\t";
//        head = head->prev;
//    }
//    cout << endl;
//}
//
//void prosmotr_end(lin_spisok* t) {
//    while (t) {
//        cout << " " << t->chislo << "\t";
//        t = t->prev;
//    }
//    cout << endl;
//}

int max_element(lin_spisok* t) {
    int n = t->chislo, m = 0, number = 0;
    while (t) {
        if (n < t->chislo) { n = t->chislo; number = m; }
        t = t->next;
        m++;
    }
    return number;
}
int min_element(lin_spisok* t) {
    int n = t->chislo, m = 0, number = 0;
    while (t) {
        if (n > t->chislo) { n = t->chislo; number = m; }
        t = t->next;
        m++;
    }
    return number;
}

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
            cout << "Введите число!" << endl;
        }
    }
    return a;
}

void Del_All(lin_spisok*& head) {
    lin_spisok* t = 0;
    while (head) {
        t = head;
        head = head->next;
        delete t;
    }
}

void add_element(lin_spisok*& p, int in, int choise) {
    lin_spisok* t = new lin_spisok;
    t->chislo = in;
    if (choise == 2) {              
        t->prev = nullptr;
        t->next = p;
        p->prev = t;  
        p = t;
    }
    else {
        t->next = nullptr;
        t->prev = p;
        p->next = t;
        p = t;
    }
}

void first_element(lin_spisok*& head, lin_spisok*& tail, int in) {
    lin_spisok* t = new lin_spisok;
    if (head == nullptr) {
        t->chislo = in;
        t->next = t->prev = nullptr;
        head = tail = t;
    }
    else {
        t->chislo = in;
        head->next = t;
        t->prev = head;
        head = t;
        t->next = nullptr;
    }
}

void DelElements(lin_spisok*& top) {
    lin_spisok* p = top, * t = top->next;
    int max, min, bufer;
    max = max_element(top); min = min_element(top);
    cout << "\nНомер максимального элемента: " << max << ", " << "Номер минимального элемента: " << min << endl;
    if (min > max) {
        bufer = min; min = max; max = bufer;
    }  
    if (max == min) {
        cout << "Все цифры в списке одинаковы! Удаление не произошло!" << endl;
        return;
    }
    if (max - 1 == min) {
        cout << "Нет элементов между максималным и минимальным значением!" << endl;
        return;
    }
    cout << "Количество элементов между максимальным и минимальным: " << max - min - 1 << endl;
    max--;
        for (int k = 0; k < max; k++) {
            if (k >= min) {
                p->next = t->next;
                p->next->prev = t->prev;
                delete t;
                t = p->next;
            }
            else {
                p = t;
                t = t->next;
            }
        }  
}

int main()
{
    setlocale(LC_ALL, "ru");
    
        int size, i, choise, k=0;
        lin_spisok* head = nullptr, * tail = nullptr;
        
        while (true) {
            cout << " 1 - Создание списка\n 2 - Добавление элементов в список\n 3 - Решение задания\n 4 - Удаление всего списка \n 0 - Выход" << endl;
            cout << "Введите номер желаемого пункта:";
            choise = array_size();
            if (choise == 0) { break; }

            switch (choise) {
            case 1:
                if (head != nullptr) {
                    cout << "Уже был создан список! Если хотите удалить предыдущий и создать новый нажмите 1, иначе другие клавиши!" << endl;
                    if (_getch() == '1') { Del_All(head); }
                    else { break; }
                }

                cout << "Количество элементов списка: ";
                size = array_size();
                cout << "Если хотите заполнить список случайными числами, то нажмите 1, иначе любую другую клавишу:" << endl;
                if (_getch() == '1') {
                    for (int k = 0; k < size; k++) {
                        i = 100 - rand() % 200;
                        first_element(head, tail, i);
                    }
                }
                else {
                    for (int k = 0; k < size; k++) {
                        cout << "Введите значение: ";
                        i = array_size(); first_element(head, tail, i);
                    }
                }
                cout << "Просмотр с начала:"; prosmotr(tail);

                continue;
            case 2:
                cout << "Количество элементов которые вы хотите добавить: ";
                cin >> size;
                cout << "Добавить в начало - 1; Добавить в конец - 2: ";
                cin >> choise;
                for (int k = 0; k < size; k++){
                    if (choise == 1) {
                        cout << "Число: "; cin >> i, add_element(head, i, choise);
                    }
                    else {                        
                        cout << "Число: "; cin >> i, add_element(tail, i, choise);
                    }
                }
                
                cout << "Просмотр с начала:"; prosmotr(tail);
                cout << "Просмотр с конца:"; prosmotr(head);

                continue;
            case 3:
                DelElements(tail);
                cout << "Просмотр с начала:"; prosmotr(tail);
                cout << "Просмотр с конца:"; prosmotr(head);
                continue;
            case 4:
                Del_All(head);
                cout << "Удаление произошло!" << endl;
                continue;
            default:
                break;
            }
        }
        
        Del_All(head);  
    return 0;
}