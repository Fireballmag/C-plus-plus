#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <conio.h>
#include <Windows.h>

using namespace std;

int input() {
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
			cout << "Число = ";
		}

	}
	return a;
}

struct Tree
{
	int ID;
	string name;
	Tree* left, * right;
};

Tree* List(int in, string fio)
{
	Tree* t = new Tree;
	t->ID = in;
	t->name = fio;
	t->left = t->right = NULL;
	return t;
}

void AddList(Tree** root, int in, string fio)
{
	Tree* prev = nullptr, * t = *root;
	if (*root == NULL)
	{
		*root = List(in, fio);
	}
	else {
		while (t)
		{
			if (in == t->ID)
			{
				cout << "Элемент " << fio << " имеет ID которой уже был использован! Введите ID заново: ";
				in = input();
			}
			prev = t;
			if (in > t->ID) t = t->right;
			else t = t->left;
		}
		t = List(in, fio);
		if (in > prev->ID) prev->right = t;
		else prev->left = t;
	}
}
Tree* getMinNode(Tree* node) {
	if (!node) return node;
	Tree* current = node;

	while (current && current->left)
		current = current->left;

	return current;
}
Tree* DeleteNode(Tree* root, int key) {

	if (!root) return root;

	if (key < root->ID)
		root->left = DeleteNode(root->left, key);

	else if (key > root->ID)
		root->right = DeleteNode(root->right, key);

	else {

		if (!root->left && !root->right)
			return nullptr;

		else if (!root->left) {
			Tree* temp = root->right;
			delete root;
			return temp;
		}
		else if (!root->right) {
			Tree* temp = root->left;
			delete root;
			return temp;
		}

		Tree* temp = getMinNode(root->right);

		root->ID = temp->ID;
		root->name = temp->name;

		root->right = DeleteNode(root->right, temp->ID);
	}
	return root;
}

void Veiw1(Tree* root)
{
	if (root != NULL)
	{
		Veiw1(root->left);
		cout << "Имя:" << root->name << "\tID:" << root->ID << endl;
		Veiw1(root->right);
	}
}

void Veiw2(Tree* root)
{
	if (root != NULL)
	{
		Veiw2(root->left);
		Veiw2(root->right);
		cout << "Имя:" << root->name << "\tID:" << root->ID << endl;
	}
}

void Veiw3(Tree* root)
{
	if (root != NULL)
	{
		cout << "Имя:" << root->name << "\tID:" << root->ID << endl;
		Veiw3(root->left);
		Veiw3(root->right);
	}

}

void Search(Tree* root, int key)
{
	while (root != NULL)
	{
		if (root->ID > key) root = root->left;
		else
		{
			if (root->ID < key) root = root->right;
			else
			{
				cout << "Имя:" << root->name << "\tID:" << root->ID << endl;
				return;
			}	
		}
	}
}

void Kolvo_Elementov(Tree* root, int* k)
{
	if (root != NULL)
	{
		(*k)++;
		Kolvo_Elementov(root->left, k);
		Kolvo_Elementov(root->right, k);
	}
}

void Tree_To_Arr(Tree* root, Tree* arr, int* n)
{
	if (root != NULL)
	{
		Tree_To_Arr(root->left, arr, n);
		arr[*n].name = root->name;
		arr[*n].ID = root->ID;
		(*n)++;

		Tree_To_Arr(root->right, arr, n);
	}

}

void Make_Balance(Tree** root, int n, int k, Tree* arr)
{
	if (n == k)
	{
		*root = NULL;
		return;
	}
	else
	{
		int m = (k + n) / 2;
		*root = new Tree;
		(*root)->ID = arr[m].ID;
		(*root)->name = arr[m].name;
		Make_Balance(&(*root)->left, n, m, arr);
		Make_Balance(&(*root)->right, m + 1, k, arr);
	}

}

void Delete_All_Tree(Tree* root)
{
	if (root)
	{
		Delete_All_Tree(root->left);
		Delete_All_Tree(root->right);
		delete root;
	}

}

void print(Tree* root, int tabs)
{

	if (root == nullptr) {
		return;
	}
	else {
		if(root->name == "\0" && root->left == nullptr && root->right == nullptr) {
			return;
		}	
		else {
			tabs += 5;
			print(root->right, tabs);
			for (int i = 0; i < tabs; i++) cout << " ";
			cout << root->ID << endl;


			print(root->left, tabs);

			tabs--;
			return;
		}
	}
}

void Oun_Task2(Tree* root, int key) {
	if (root) {
		Oun_Task2(root->left, key);
		Oun_Task2(root->right, key);
		if (key == root->ID) {
			Delete_All_Tree(root->left);
			root->left = NULL;
			Delete_All_Tree(root->right);
			root->right = NULL;
		}
	}
}
//Tree* deleteSubTree(Tree* root, int key) {
//	if (root == NULL) return NULL;
//	if (key < root->ID) root->left = deleteSubTree(root->left, key);
//	else if (key > root->ID) root->right = deleteSubTree(root->right, key);
//	else if (key == root->ID) {
//		if (root->left == NULL and root->right == NULL) {
//			delete root;
//			root = nullptr;
//		}
//		else if (root->left == NULL) {
//			root->right = deleteSubTree(root->right, root->right->ID);
//		}
//		else if (root->right == NULL) {
//			root->left = deleteSubTree(root->left, root->left->ID);
//		}
//		else {
//			while (root->left != NULL or root->right != NULL) {
//				if (root->left != NULL) root->left = deleteSubTree(root->left, root->left->ID);
//				if (root->right != NULL) root->right = deleteSubTree(root->right, root->right->ID);
//			}
//		}
//	}
//	return root;
//}
int chek(Tree* root, int kod) {
	while (root != NULL)
	{
		if (root->ID == kod) {
			return 1;
		}
		if (root->ID > kod) root = root->left;
		else {
			root = root->right;
		}
		if (root == NULL) {
			cout << "\nТакого элемента нет!\n" << endl;
			return 0;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	Tree* root = NULL;
	
	while (true)
	{
		int k = 0, kod, n, bufer=1;
		string name;
		cout << "1) Ввести информацию\n2) Сбалансирвать дерево\n3) Найти информацию по ID\n"
			<< "4) Удалить информацию по ID\n5) Вывести информацию прямым, обратным обходом и в порядке возрастания ключа\n6) Просмотреть дерево\n"
			<< "7) Удаление ветви по ID\n8) Удалить дерево\nВыход - любые другие символы\n";
		switch (_getch())
		{
		case '1': {
			cout << "Количество элементов которые хотити добавить:" << endl;
			kod = input();
			for (int i = 0; i < kod; i++)
			{
				cout << "Имя: ";
				cin >> name;
				cout << "ID: ";
				n = input();
				AddList(&root, n, name); cout << "\n";
			}
			break;
		}	
		case '2': {
			if (root == NULL) { system("cls"); cout << "Древо еще не создано!" << endl;  break; }
			n = 0;
			k = 0;
			Kolvo_Elementov(root, &k);
			Tree* arr = new Tree[k];
			Tree_To_Arr(root, arr, &n);
			Delete_All_Tree(root);
			root = NULL;
			Make_Balance(&root, 0, k, arr);
			delete[]arr;
			cout << "\n\n\nДрево сбалансировано!" << endl;
			break;			
		}
		case '3': {
			if (root == NULL) { system("cls"); cout << "Древо еще не создано!" << endl; break; }
			cout << "Введите ID:";
			kod = input();
			bufer = chek(root, kod);
			if (bufer == 1) {
				Search(root, kod);
			}
			break;
		}
		case '4': {
			if (root == NULL) { system("cls"); cout << "Древо еще не создано!" << endl; break; }
			cout << "Введите ID, который нужно удалить из дерева:";
			kod = input();
			bufer = chek(root, kod);
			if (bufer == 1) {
				root = DeleteNode(root, kod);
				cout << "\nУдаление произошло!\n" << endl;
			}			
			break;
		}
		case '5':
			if (root == NULL) { system("cls"); cout << "Древо еще не создано!" << endl; break; }
			cout << "1)Прямым обходом\n2)В порядке возрастания ключа\n3)Обратным обходом\n";
			cout << "Введите номер пункта: "; cin >> kod;
			if (kod == 1) Veiw3(root); cout << "\n\n";
			if (kod == 2) Veiw1(root); cout << "\n\n";
			if (kod == 3) Veiw2(root); cout << "\n\n";
			break;
		case '6':
			if (root == NULL) { system("cls"); cout << "Древо еще не создано!" << endl; break; }
			print(root, 5);
			break;
		case '7':
			if (root == NULL) { system("cls"); cout << "Древо еще не создано!" << endl; break; }
			cout << "Введите ID: ";
			kod = input();
			bufer = chek(root, kod);
			if (bufer == 1) {
				Oun_Task2(root, kod);
				cout << "\nУдаление произошло!\n" << endl;
			}						
			break;
		case '8':
			if (root == NULL) { system("cls"); cout << "Древо еще не создано!" << endl; break; }
			Delete_All_Tree(root);
			root = nullptr;
			break;
		default:
			Delete_All_Tree(root);
			root = nullptr;
			return 0;
		}
	}
}
