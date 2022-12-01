#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef struct FIO {
	string Name;
	string SurName;
	string LastName;
};

class Student {
private:
	FIO Value;
	int grade[5];
public:
	Student();
	Student(const Student& obj);
	~Student();
	friend ostream& operator<< (ostream& out, Student& obj);//�������� ����� � �����
	friend istream& operator>>(istream& in, Student& obj); // �������� ���������� �� ������
	/*void SetStudent();*/
	float GetGrade();
	void Print(ostream& out);
};