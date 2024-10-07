#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <ctime>
#include <map>


using namespace std;

const int MAX_STUDENTS = 15;
const int MAX_GROUP = 3;
const int MAX_DISCIPLINE = 5;

struct Discipline
{
	string name;
	string mark;
};

struct Student
{
	string fullName;
	int groupNumber;
	vector<Discipline> disciplines;
};


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(unsigned(time(0)));

	map<int, string> studentMap =
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
	};

	map<int, string> markMap =
	{	{0, "�������������������"},
		{1, "�����������������"},
		{2, "������"},
		{3, "�������"}
	};

	map<int, string> disciplineMap =
	{
		{0, "�������������� ������"},
		{1, "������������� ���������"},
		{2, "��������������� �����"},
		{3, "������������� �����������"},
		{4, "���������� ��������"}
	};

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
	cout << endl;

	vector<Student> students_vector;
	for (int i = 0; i < numberOfStudents; i++)
	{
		Student student;
		student.fullName = studentMap[rand() % 30];
		student.groupNumber = groupMap[rand() % numberOfGroup];
		vector<Discipline> disciplines_vector;
		for (int j = 0; j < numberOfDiscipline; j++)
		{
			Discipline discipline;
			discipline.name = disciplineMap[rand() % numberOfDiscipline];
			discipline.mark = markMap[rand() % 4];
			disciplines_vector.push_back(discipline);
		}
		student.disciplines = disciplines_vector;
		students_vector.push_back(student);
	}

	for (int i = 0; i < numberOfStudents; i++)
	{
		cout << "���: " << students_vector[i].fullName << endl;
		cout << "����� ������: " << students_vector[i].groupNumber << endl;
		cout << "����������: " << endl;
		for (int j = 0; j < numberOfDiscipline; j++)
		{
			cout << j + 1 << ". " << students_vector[i].disciplines[j].name << " - " << students_vector[i].disciplines[j].mark << endl;
		}
		cout << endl;
	}
	
	vector<vector<vector<int>>> matrix(numberOfDiscipline, vector<vector<int>>(numberOfGroup, vector<int>(2)));
	for (int i = 0; i < numberOfDiscipline; i++)
	{
		for (int j = 0; j < numberOfGroup; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				matrix[i][j][k] = 0;
			}
		}
	}
}