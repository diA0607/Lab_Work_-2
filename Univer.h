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
	void AddStudent(int group);
	void Del();
	void DelStudent(int group);
	void Calculate(int group);
	void PrintStudents(int group);
	friend ostream& operator<< (ostream& out, Univer& obj);
};