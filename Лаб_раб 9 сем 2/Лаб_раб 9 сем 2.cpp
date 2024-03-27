#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <conio.h>

using namespace std;
int vvod() {
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

struct hashing_array {
    int key;
    int info;
    hashing_array* next;
};

//void prosmotr(hashing_array* t) {
//    while (t) {
//        cout << " " << t->chislo << "\t";
//        t = t->next;
//    }
//    cout << endl;
//}

//int hash_f(int a) {
//    /*int sum = 0;
//    for (int i = 0; i < a.length(); ++i) {
//        char c = a[i];
//        sum += c - '0';
//    }*/
//    return abs(a % 10);
//}

int hash_f(int a) {
    int hash = 0, b;
    int len = to_string(a).size();
    for (int i = 0; i < len; i++) {
        b = a % 10;
        a = floor( a / 10);
        hash += b * (i + 1);
    }
    return hash;
}

hashing_array* add(int info, int key, hashing_array* head, int choise) {
    int check = 0;
    hashing_array* h = head;
    if (choise == 0) {
        while (h != nullptr) {
            if (h->key == key) {
                check = 1;
                break;
            }
            h = h->next;
        }
        if (check == 0) {
            delete h;
            hashing_array* t = new hashing_array;
            t->key = key;  t->info = info;
            t->next = head;

            return t;
        }
    }
    else {
        while (h != nullptr) {
            if (h->key == key) {
                check = 1;
                break;
            }
            h = h->next;
        }
        if (check == 0) {
            delete h;
            hashing_array* t = new hashing_array;
            t->key = key;  t->info = info;
            t->next = head;

            return t;
        }
        else {
            cout << " Такой элемент уже существует!" << endl;
            return head;
        }
    }
    
    
    
}

int search(int key, hashing_array* head, int choise) {// Проблемка
    int check = 0;
    if (choise == 0) {
        while (head != nullptr) {
            if (head->key == key) {
                cout << " Информационная часть: " << head->info << ";\t ключ: " << head->key << endl;
                head = head->next;
                check = 1;
            }
            else {
                head = head->next;
            }
        }
    }
    else {
        while (head != nullptr) {
            if (head->key == key) {
                return 1;
            }
            else {
                head = head->next;
            }
        }
    }
    return check;
}

//hashing_array* del_element(int key, hashing_array* head) {
//    int check = search(key, head, 1);
//    hashing_array * t = head->next, *p = head;
//    if (check == 1) {
//        while (head != nullptr) {
//            if (p->key != key) {
//                delete p;
//                p = t;
//                t = t->next;
//                continue;
//            }
//            if (p->key == key) {
//                delete p;
//                p = t;
//                t = t->next;
//                head->next = p;
//            }
//            if (p->key == key && t == nullptr) {
//                delete p;
//
//            }
//            
//            if(p->key != key){
//                head->next = p;
//                delete p;
//                p = t;
//                t = t->next;
//            }
//        }
//    }
//    else {
//        cout << "Такого элемента нет!" << endl;
//    }
//    return p;
//}

hashing_array* remove(int key, hashing_array* head) {
    int check = search(key, head, 1);
    if (check == 1) {       
        if (head->key == key) {
            hashing_array* p = head;
            head = p->next;
            delete p;
            return head;
        }
        else{
            hashing_array* slow = head;
            hashing_array* fast = head->next;
            while (fast && fast->key != key) {
                fast = fast->next;
                slow = slow->next;
            }
            slow->next = fast->next;
            delete fast;
        }   
    }
    else {
        cout << "Элемент не найден!" << endl;
        
    }
    return head;
}

void Del_All(hashing_array* head) {
    hashing_array* t = 0;   
        while (head != nullptr) {
            t = head;
            head = head->next;
            delete t;
        }
}


int main()
{
    setlocale(LC_ALL, "ru");
    while (1) {
        int size, key, choise, info, m = 0, check = 0;
        /*string first_key;        
        cout << "Введите ключ! Внимание: максимальная длина ключа 20 символов!" << endl;
        cin.width(20);
        cin >> first_key;
        cout << "Введите размер хэш таблицы: " << endl;
        array_size = vvod();*/

        hashing_array *head[450];
        for (int i = 0; i < 450; i++) {
            head[i] = nullptr;
        }
        //for (int i = 0; i< 2147483647; i+=17) {
        //    hash = hash_f(i);
        //    if (max_hash < hash) {
        //        max_hash = hash;
        //        cout << max_hash << endl;
        //    }
        //}

        while (true) {
            cout << "\n 1 - Ввести данные\n 2 - Вывод информации по ключу\n 3 - Удаление элемента по ключу\n 4 - Вывести всю информацию\n 5 - Вывести количество элементов в каждой ячейке \n 6 - Удаление всех данных \n 0 - Выход" << endl;
            cout << "Введите номер желаемого пункта:";
            choise = vvod();
            if (choise == 0) { break; }

            switch (choise) {
            case 1:
                cout << "Количество элементов которые хотите добавить: ";
                cin >> size;
                cout << "Ввести всю информацию своими руками или полностью случайно, случайно - нажмите 1, иначе другие клавиши: ";
                if (_getch() == '1') {
                    for (int k = 0; k < size; k++) {
                        info = 100 - rand() % 200;
                        key = 100 - rand() % 200;
                        key = abs(key);
                        m = hash_f(key);
                        head[m] = add(info, key, head[m], 0);
                    }
                    for (int i = 0; i < 450; i++) {
                        hashing_array* p = head[i];
                        while (p != nullptr) {
                            cout << " Информационная часть: " << p->info << ";\t ключ: " << p->key << endl;
                            p = p->next;
                        }
                        delete p;
                    }
                }
                else {
                    for (int k = 0; k < size; k++) {
                        cout << "\n Информация: "; info = vvod();
                        cout << " Ключ: "; key = vvod();
                        key = abs(key);
                        m = hash_f(key);
                        head[m] = add(info, key, head[m], 1);
                    }
                }               
                continue;
            case 2:
                cout << "Введите ключ: "; key = vvod();
                m = hash_f(key);
                check = search(key, head[m], 0);
                if (check == 0) {
                    cout << "Такого элемента нет!" << endl;
                }
                continue;
            case 3:
                cout << "Введите ключ: "; key = vvod();
                m = hash_f(key);
                head[m] = remove(key, head[m]);
                continue;
            case 4:
                
                for (int i = 0; i < 450; i++) {
                    hashing_array* p = head[i];
                    while (p != nullptr) {
                        cout << " Информационная часть: " << p->info << ";\t ключ: " << p->key << endl;
                        p = p->next;
                    }
                    delete p;
                }

                continue;
            case 5:
                for (int i = 0; i < 450; i++) {
                    hashing_array* p = head[i];
                    while (p != nullptr) {
                        check++;
                        p = p->next;
                    }
                    if (head[i] != nullptr) {
                        cout << "Номер в таблице: " << i << "<-" << check << endl;
                    }
                    check = 0;
                    delete p;
                }
                continue;
            case 6:
            cout << "\n Вы точно в этом уверены? Есди да, то нажмите 1." << endl;
            if (_getch() == '1') { 
                for (int i = 0; i < 450; i++) {
                    Del_All(head[i]);
                    head[i] = nullptr;
                }
                cout << "\n Удаление произошло!" << endl;
            }                
            continue;
            default:
                break;
            }
        }

        for (int i = 0; i < 450; i++) {
            Del_All(head[i]);
            head[i] = nullptr;
        }

        string continue_str;
        cout << "\nПовторить? Если да, то введите 1 или y: ";
        cin >> continue_str;
        if (!(continue_str == "1" || continue_str == "y")) {
            return 1;
        }
    }
    return 0;
}