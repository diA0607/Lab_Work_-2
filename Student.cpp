#include "Student.h"

Student::Student() {
	grade = 0;
}

Student::Student(const Student& obj) {
	Value = obj.Value;
	grade = obj.grade;

}

Student::~Student() {

}

void Student::SetStudent() {
	cout << "������� ���:" << endl
		<< "���: ";
	cin.ignore(256, '\n');
	getline(cin, this->Value.Name);
	cout << "�������: ";
	getline(cin, this->Value.SurName);
	cout << "�������: ";
	getline(cin, this->Value.LastName);
	cout << "������� ������: " << endl;
	cin >> this->grade;
	cout << "������� ��������!" << endl;
}

int Student::GetGrade() {
	return grade;
}


void Student::Print(ostream& out) {
	out << this->Value.Name
		<< " " << this->Value.SurName
		<< " " << this->Value.LastName << endl;
}