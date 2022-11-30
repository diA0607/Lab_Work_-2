#pragma once
#include "Student.h"
using namespace std;

class Group {
private:
	Student* Value;
	int size;
	int number;
	float av_grade;
	string subject;
public:
	Group();
	Group(const Group& obj);
	~Group();
	void SetGroup();
	int GetSize();
	void Add();
	void Del();
	void Calculate();
	void Red();
	void Ball();
	void Expulsion();
	friend ostream& operator<< (ostream& out, Group& obj);
	Group& operator= (Group& obj);
	void Print(ostream& out);
	void PrintStudents();
};