#pragma once
#include "Group.h"
using namespace std;

class Univer {
private:
	Group* Value;
	int size;
	int count;
public:
	Univer();
	~Univer();
	int GetSize();
	void Add();
	void Reduct(int group,int ch);//��������������
	void AddStudent(int group);
	void Del(int group);
	void DelStudent(int group);
	void Calculate(int group);
	void PrintStudents(int group); 
	void SRBall(int group);//������� ����
	void Ball_2(int group);//����� ��������� �� ����������
	
	friend ostream& operator<< (ostream& out, Univer& obj);
};