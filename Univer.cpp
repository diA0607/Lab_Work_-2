#include "Univer.h"

Univer::Univer() {
	Value = nullptr;
	size = 0;
}

Univer::~Univer() {

}

int Univer::GetSize() {
	return size;
}

void Univer::Add() {
	Group** temp = new Group*[size + 1];
	int i = 0;
	while (i < size) {
		temp[i] = Value[i];
		i++;
	}
	temp[size].SetGroup();
	size++;
	if (Value)
		delete[] Value;
	Value = temp;
}

void Univer::AddStudent(int group) {
	Value[group].Add();
}

void Univer::Del() {
	if (size == 0) {
		cout << "Группы отсутствуют!" << endl;
		return;
	}
	if (size == 1) {
		delete[] Value;
		Value = nullptr;
		size--;
	}
	else {
		Group** temp = new Group*[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++)
			temp[j++] = Value[i];
		delete[] Value;
		Value = temp;
		size--;
	}
}

void Univer::DelStudent(int group) {
	Value[group].Del();
}

void Univer::Calculate(int group) {
	Value[group].Calculate();
}

void Univer::PrintStudents(int group) {
	Value[group].PrintStudents();
}

ostream& operator<< (ostream& out, Univer& obj) {
	for (int i = 0; i < obj.size; i++) {
		obj.Value[i].Print(out);
	}
	return out;
}