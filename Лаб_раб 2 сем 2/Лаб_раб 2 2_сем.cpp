#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <conio.h>

using namespace std;


struct lin_spisok {
    int chislo;
    lin_spisok* next;
};

void prosmotr(lin_spisok* t) {
    while (t) {
        cout << " " << t->chislo << "\t";
        t = t->next;
    }
    cout << endl;
}

//void kolichistvo(lin_spisok* t) {
//    int n=0;
//    while (t) {
//        n++;
//        t = t->next;
//    }
//    cout << n << endl;
//}

int max_element(lin_spisok* t) {
    int n = t->chislo, m=0, number=0;
    while (t) {
        if (n < t->chislo) { n = t->chislo; number = m; }
        t = t->next;
        m++;
    }
    return number;
}
int min_element(lin_spisok* t) {
    int n = t->chislo, m = 0, number=0;
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

void DelElements(lin_spisok* top) {
    lin_spisok* p = top, *t = top->next;
    int max, min, bufer;
    max = max_element(top); min = min_element(top);
    cout << "\nНомер максимального элемента: " << max << ", " << "Номер минимального элемента: " << min << endl;
    if (min > max) {
        bufer = min; min = max; max = bufer;
    }
    cout << "Количество элементов между максимальным и минимальным: " << max - min - 1 << endl;
        if (max == min) {
            cout << "Все цифры в списке одинаковы! Удаление не произошло!" << endl;
        }
        if (max - 1 == min) {
            cout << "Нет элементов между максималным и минимальным значением!" << endl;
        }
        max--;
        for (int k = 0; k < max; k++) {
            if (k >= min) {
                p->next = t->next;
                delete t;
                t = p->next;
            }
            else {
                p = t;
                t = t->next;
            }
        }
    }

void Del_All(lin_spisok*& head) {
    lin_spisok* t = 0;
    while (head) {
        t = head;
        head = head->next;
        delete t;
    }
}

lin_spisok* InStack(lin_spisok* p, int in) {
    lin_spisok* t = new lin_spisok;
    t->chislo = in;
    t->next = p;
    return t;
}

int main()
{
    setlocale(LC_ALL, "ru");
    while (1) {
        int size, i, choise;
        
        lin_spisok* head = nullptr;
        
        while (true) {
            cout << " 1 - Создание списка\n 2 - Добавление элементов в список\n 3 - Решение задания\n 4 - Удаление всего списка \n 0 - Выход" << endl;
            cout << "Введите номер желаемого пункта:";
            choise = array_size();
            if (choise == 0) {break; }

        switch (choise) {
        case 1:
            if (head != nullptr) {
                cout << "Уже был создан список! Если хотите удалить предыдущий и создать новый нажмите 1, иначе другие клавиши!" << endl;
                if (_getch() == '1') { Del_All(head); }
                else { break; }         
            }

            cout << "Количество элементов списка: ";
            cin >> size;
            cout << "Если хотите заполнить список случайными числами, то нажмите 1, иначе любую другую клавишу:" << endl;
            if (_getch() == '1') {
                for (int k = 0; k < size; k++) {
                    i = 100 - rand() % 200;
                    head = InStack(head, i);
                }
            }
            else {
                for (int k = 0; k < size; k++) {
                    cin >> i, head = InStack(head, i);
                }
            }
            prosmotr(head);
            continue;
        case 2:
            cout << "Количество элементов которые вы хотите добавить: ";
            cin >> size;
            for (int k = 0; k < size; k++) {
                cout << "Число: "; cin >> i, head = InStack(head, i);
            }
            prosmotr(head);
            continue;
        case 3:
            //cout << "Количество элементов до удаления: "; kolichistvo(head);
            DelElements(head);
            //cout << "Количество элементов после удаления: "; kolichistvo(head);
            prosmotr(head);
            continue;
        case 4:
            Del_All(head);
            continue;
        default:
            break;            
            }
        }    

        Del_All(head);        

        string continue_str;
        cout << "\nПовторить? Если да, то введите 1 или y: ";
        cin >> continue_str;
        if (!(continue_str == "1" || continue_str == "y")) {
            return 1;
        }
    }
    return 0;
}