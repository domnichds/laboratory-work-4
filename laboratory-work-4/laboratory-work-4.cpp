#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

const int MAX_STUDENTS = 15;
const int MAX_GROUP = 3;
const int MAX_DISCIPLINE = 5;

struct Discipline
{
	string name;
	double mark;
};

struct Student
{
	string fullName;
	int groupNumber;
	vector<Discipline> Disciplines;
	int numberOfDisciplines;
};


int main()
{
	map<int, string> studentsMap =
	{
		{0, "������ ���� ��������"}, {1, "������ ���� ��������"}, {2, "������� ������ ���������"}, {3, "�������� ������� ����������"},
		{4, "������� ������� ����������"}, {5, "������� ������ ����������"}, {6, "������� ������ ���������"}, {7, "������ �������� ������������"},
		{8, "������� ����� ���������"}, {9, "������� ��������� �������������"}, {10, "����� ����� ��������"}, {11, "������� ������� ����������"},
		{12, "������ ����� ���������"}, {13, "������� ����� ���������"}, {14, "������ ������ ����������"}, {15, "�������� ������� ����������"},
		{16, "������ ������� ����������"}, {17, "������� ����� ��������"}, {18, "�������� ���� ��������"}, {19, "�������� ����� ���������"},
		{20, "������ ����� ���������"}, {21, "�������� ����� ���������"}, {22, "����� ������� ����������"}, {23, "������� ��������� �������������"},
		{24, "������� ������� ����������"}, {25, "������� ������� ����������"}, {26, "����� ������ ����������"}, {27, "������� ���������� ��������������"},
		{28, "�������� ���� �������"}, {29, "�������� ������ ����������"}
	};
	map<int, int> groupMap =
	{
		{0, 11},
		{1, 12},
		{2, 13},
		{3, 14},
		{4, 15}
	};
	map<int, string> markMap =
	{	{0, "�������������������"},
		{1, "�����������������"},
		{2, "������"},
		{3, "�������"}
	};
	setlocale(LC_ALL, "Russian");
	int numberOfStudents, numberOfGroup, numberOfDiscipline;
	cout << "������� ���������� ���������: ";
	cin >> numberOfStudents;
	cout << "������� ���������� �����: ";
	cin >> numberOfGroup;
	cout << "������� ���������� ���������: ";
	cin >> numberOfDiscipline;
	if (numberOfStudents > MAX_STUDENTS || numberOfGroup > MAX_GROUP || numberOfDiscipline > MAX_DISCIPLINE)
	{
		cout << "������ �����!";
		return 0;
	}
}