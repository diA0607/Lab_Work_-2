/*
1. Стандартные потоки
Определить классы с именем STUDENT и GROUP.
STUDENT содержит следующие поля :
	● фамилия и инициалы;
	● успеваемость(массив из нескольких элементов).
Определить объединение объектов типа STUDENT в GROUP.
Классов GROUP может быть несколько, заранее число не известно,
определяется пользователем.
GROUP определяет такие параметры как :
	● средний балл в группы;
	● предметы группы;
	● номер группы и пр.
Перегрузить операции извлечения и вставки для объектов типа STUDENT.
Определить полноценное меню для работы пользователя с программой.
Написать программу, выполняющую следующие действия :
	● Определить ввод с клавиатуры данных STUDENT в GROUP,
		записи должны быть упорядочены по возрастанию номера группы;
	● вывод на дисплей фамилий и номеров групп для всех студентов,
		включенных в массив, если средний балл студента больше 4.0;
	● если таких студентов нет, вывести соответствующее сообщение.
2. Файловые и строковые потоки
С использованием файловых и строковых потоков написать программу,
которая считывает текст из файла и выводит его на экран,
меняя местами каждые два соседних слова.*/


#include "Univer.h"

#include <iostream>
#include <fstream>
#include <Windows.h>


using namespace std;
int Potok() {
	string s1;
	string s[30];
	ifstream ifs("text.txt");
	int count = 0;
	while (getline(ifs, s1, ' ')) {
		s[count] = s1;
		count++;
	}
	ifs.close();
	string temp;
	for (int i = 0; i < 30; i += 2) {
		temp = s[i];
		s[i] = s[i + 1];
		s[i + 1] = temp;
	}
	for (int i = 0; i < 30; i++) {
		cout << s[i] << " ";
	}
	return 0;
}

int main() {
	
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "Rus");
	Univer un1;

	char menu;
	do {
		cout << "[1] Добавить группу." << endl
			<< "[2] Добавить студента." << endl
			<< "[3] Удалить группу." << endl
			<< "[4] Удалить студента." << endl
			<< "[5] Вычислить средний балл (при наличии студентов в группах)" << endl
			<< "[6] Показать группы." << endl
			<< "[7] Показать студентов." << endl
			<< "[X] Поменять слова текста из файла местами (2-е задание)." << endl
			<< "[0] Выход." << endl
			<< ">> ";
		cin >> menu;
		switch (menu) {
		case '0':
			break;
		case '1':
			un1.Add();
			break;
		case '2':
			if (un1.GetSize() >= 2) {
				int group;
				cout << "Выберите группу:" << endl;
				for (int i = 0; i < un1.GetSize(); i++)
					cout << "[" << i + 1 << "]" << endl;
				cout << ">> ";
				cin >> group;
				un1.AddStudent(group-1);
			}
			else if (un1.GetSize() == 1)
				un1.AddStudent(0);
			else
				cout << "Группы отсутствуют!" << endl;
			break;
		case '3':
			un1.Del();
			break;
		case '4':
			if (un1.GetSize() >= 2) {
				int group;
				cout << "Выберите группу:" << endl;
				for (int i = 0; i < un1.GetSize(); i++)
					cout << "[" << i + 1 << "]" << endl;
				cout << ">> ";
				cin >> group;
				un1.DelStudent(group);
			}
			else if (un1.GetSize() == 1)
				un1.DelStudent(1);
			else
				cout << "Группы отсутствуют!" << endl;
			break;
		case '5':
			if (un1.GetSize() >= 2) {
				int group;
				cout << "Выберите группу:" << endl;
				for (int i = 0; i < un1.GetSize(); i++)
					cout << "[" << i + 1 << "]" << endl;
				cout << ">> ";
				cin >> group;
				un1.Calculate(group);
			}
			else if (un1.GetSize() == 1)
				un1.Calculate(0);
			else
				cout << "Группы отсутствуют!" << endl;
			break;
		case '6':
			cout << un1;
			break;
		case '7':
			if (un1.GetSize() >= 2) {
				int group;
				cout << "Выберите группу:" << endl;
				for (int i = 0; i < un1.GetSize(); i++)
					cout << "[" << i + 1 << "]" << endl;
				cout << ">> ";
				cin >> group;
				un1.PrintStudents(group);
				//cout << un1;
			}
			//else if (un1.GetSize() == 1)
			//	//cout << un1;
			//	un1.PrintStudents(0);
			else
				cout << "Студенты отсутствуют!" << endl;
			break;
		case 'x':
			Potok();
			cout << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (menu != '0');
	return 0;
}