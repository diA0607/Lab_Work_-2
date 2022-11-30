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
	cout << "������� ����� ������:";
	cin >> this->number;
	cout << "������� ��������� �������:";
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
	if (size == 0)
		throw string("Unable to delete student. Group is empty");

	int number; // ����� ��������

	cout << "������� ����� �������� ��� ��������: ";
	cin >> number; // ��������� �����

	// ���� ����� �� ������ � ������ ��������, ������� ����������
	if (number < 1 || number > size)
		throw string("����� �������� ������ ���� �� 1 ��" + to_string(size));

	// �������� ���������
	for (int i = number; i < size; i++) {
		Value[i - 1] = Value[i];
	}
	Student* temp = new Student[size];
	int j = 0;
	for (int i = 0; i < size; i++)
		temp[j++] = Value[i];
	delete[] Value;
	Value = temp;
	size--; // ��������� ������
	cout << "������� ������" << endl;


	/*int number;
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
	}*/
}

void Group::Calculate() {
	for (int i = 0; i < size; i++)
	{
		av_grade += Value[i].GetGrade();
	}
		
	av_grade /= size;
}
void Group::Ball() {
	int count = 0; // ����� ���������

	// ��������� ������� ��������
	cout<<number<<endl;
	for (int i = 0; i < GetSize(); i++) {
		// ���� ���� ���� 4, ������� ���
		
			if (Value[i].GetGrade() >= 4)
			{
				// ���� ��� ��� 1 �������, �� ������� ����
				cout << Value[i] << endl;
				count++;
			}
		
		
	}

	// ���� �� ���� �� ������ ��������, �� ������� ���
	if (count == 0)
		cout << endl << "��� ��������� �� ������� ������ ���� 4" << endl;
}
void Group::Expulsion()//�� ����������
{
	int count = 0; // ����� ���������

	// ��������� ������� ��������
	cout << number << endl;
	for (int i = 0; i < GetSize(); i++) {
		// ���� ���� ���� 4, ������� ���

		if (Value[i].GetGrade() < 3)
		{
			// ���� ��� ��� 1 �������, �� ������� ����
			cout << Value[i] << endl;
			count++;
		}
	}

	// ���� �� ���� �� ������ ��������, �� ������� ���
	if (count == 0)
		cout << endl << "��� ��������� �� ����������" << endl;
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
	out << endl << "����� ������: " << number << endl
		<< "��������� �������: " << subject << endl
		<< "������ ������: " << size << endl
		<< "������� ����: " << av_grade << endl;
}

void Group::PrintStudents() {
	for (int i = 0; i < this->size; i++)
	{
		cout << Value[i];
	}
	
	//cout << Value;
	
}
void Red() {

	//cout << Value[];

}