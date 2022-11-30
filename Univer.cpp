#include "Univer.h"

Univer::Univer() {
	Value = nullptr;
	size = 0;
	//count = 1;

}

Univer::~Univer() {

}

int Univer::GetSize() {
	return size;
}

void Univer::Add() {
	//size = GetSize();
	Group* temp = new Group  [size + 1];
	//int i = 0;
	
	for (int i = 0; i < size; i++)
	{
		temp[i] = Value[i];
	}
	/*if (size == 0)
	{
		temp[0].SetGroup();
	}*/
	
	temp[size].SetGroup();
	
	if (Value)
		delete[] Value;
	Value = temp;
	size++;
	

}

void Univer::AddStudent(int group) {
	Value[group].Add();
}

void Univer::Del(int group) {
	if (size == 0) {
		cout << "������ �����������!" << endl;
		return;
	}
	if (size == 1) {
		delete[] Value;
		Value = nullptr;
		size--;
	}
	else {
		Group* temp = new Group[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (i != group)
				temp[j++] = Value[i];
		}	
		delete[] Value;
		Value = temp;
		size--;
	}
}
void Univer::Reduct(int group)
{
	Group* temp = new Group[size];
	
	for (int i = 0; i < size; i++)
	{
		temp[i] = Value[i];
	}

	temp[group].SetGroup();

	if (Value)
		delete[] Value;
	Value = temp;
	//Value[group].Red();
}
void Univer::DelStudent(int group) {
	Value[group].Del();
}

void Univer::Calculate(int group) {
	Value[group].Calculate();
}

void Univer::PrintStudents(int group) {
	Value[group].PrintStudents();
	//cout<<
	//Value[group].Print(out);
}
void Univer::SRBall(int group) {
	Value[group].Ball();
}
void Univer::Ball_2(int group)
{
	Value[group].Expulsion();//����������
}
ostream& operator<< (ostream& out, Univer& obj) {
	for (int i = 0; i < obj.size; i++) {
		obj.Value[i].Print(out);
	}
	return out;
}