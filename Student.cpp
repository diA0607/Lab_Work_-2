#include "Student.h"

Student::Student() {
	for(int i=0;i<5;i++)
		grade[i] = 0;
}

Student::Student(const Student& obj) {
	Value = obj.Value;
	for (int i = 0; i < 5; i++)
		grade[i] = obj.grade[i];

}

Student::~Student() 
{

}

void Student::Reduct()
{
	cout << " �������� ������:";


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
	for(int i=0;i<5;i++)
		cin >> this->grade[i];
	cout << "������� ��������!" << endl;
}

float Student::GetGrade() {
	float sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += grade[i];
	}
	return (float)sum/5.0;
}


void Student::Print(ostream& out) {
	out << this->Value.Name
		<< " " << this->Value.SurName
		<< " " << this->Value.LastName << endl;

}

ostream& operator<< (ostream& out, Student& obj) {
	
	out << obj.Value.Name
		<< " " << obj.Value.SurName
		<< " " << obj.Value.LastName << endl;
	
	return out;
}