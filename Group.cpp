#include "Group.h"

Group::Group() {
	Value = nullptr;
	size = 0;
	number = 0;
	av_grade = 0;
	subject = "";
}

Group::Group(const Group& obj) {
	Value = obj.Value;
	size = obj.size;
	number = obj.number;
	av_grade = obj.av_grade;
	subject = obj.subject;
}

Group::~Group() {

}

void Group::SetGroup() {
	setlocale(LC_ALL, "Rus");
	cout << "Введите номер группы:";
	cin >> this->number;
	cout << "Введите изучаемый предмет:";
	cin.ignore(256, '\n');
	getline(cin, this->subject);
}

int Group::GetSize() {
	return size;
}

void Group::Add() {
	
	Student* temp = new Student[size + 1];
	int i = 0;
	while (i < size) {
		temp[i] = Value[i];
		i++;
	}
	
	temp[size].SetStudent();
	size++;
	if (Value)
		delete[] Value;
	Value = temp;
}

void Group::Del() {
	if (size == 0) {
		cout << "Группа пуста!" << endl;
		return;
	}
	if (size == 1) {
		delete[] Value;
		Value = nullptr;
		size--;
	}
	else {
		Student* temp = new Student[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++)
			temp[j++] = Value[i];
		delete[] Value;
		Value = temp;
		size--;
	}
}

void Group::Calculate() {
	for (int i = 0; i < size; i++)
		av_grade += Value[i].GetGrade();
	av_grade /= size;
}

ostream& operator<< (ostream& out, Group& obj) {
	for (int i = 0; i < obj.size; i++) {
		obj.Value[i].Print(out);
	}
	return out;
}


Group& Group::operator= (Group& obj) {
	Value = obj.Value;
	size = obj.size;
	number = obj.number;
	av_grade = obj.av_grade;
	subject = obj.subject;
	return *this;
}

void Group::Print(ostream& out) {
	//setlocale(LC_ALL, "Rus");
	out << endl << "Номер группы: " << number << endl
		<< "Изучаемый предмет: " << subject << endl
		<< "Размер группы: " << size << endl
		<< "Средний балл: " << av_grade << endl;
}

void Group::PrintStudents() {
	for (int i = 0; i < this->size; i++)
	{
		cout << Value[i];
	}
	
	//cout << Value;
	
}