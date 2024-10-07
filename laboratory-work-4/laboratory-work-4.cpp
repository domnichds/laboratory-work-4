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
	Discipline* disciplines;
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
		student.disciplines = new Discipline[numberOfDiscipline];
		for (int j = 0; j < numberOfDiscipline; j++)
		{
			Discipline discipline;
			discipline.name = disciplineMap[j];
			discipline.mark = markMap[rand() % 4];
			student.disciplines[j] = { discipline.name, discipline.mark };
		}
		students_vector.push_back(student);
	}
	cout << "------------------------------------------------------------" << endl;
	for (int i = 0; i < numberOfStudents; i++)
	{
		cout << setw(14) << left << "���: " << students_vector[i].fullName << endl;
		cout << "����� ������: " << students_vector[i].groupNumber << endl;
		cout << setw(14) << left << "����������: " << endl << endl;
		for (int j = 0; j < numberOfDiscipline; j++)
		{
			cout << setw(35) << left << students_vector[i].disciplines[j].name << setw(25) << right << students_vector[i].disciplines[j].mark << endl;
		}
		cout << "------------------------------------------------------------" << endl;
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
	
	for (int i = 0; i < numberOfDiscipline; i++)
	{
		for (int j = 0; j < numberOfGroup; j++)
		{
			for (int k = 0; k < numberOfStudents; k++)
			{
				int score;
				string getMark = students_vector[k].disciplines[i].mark;
				if (getMark == "�������������������") { score = 2; }
				else if (getMark == "�����������������") { score = 3; }
				else if (getMark == "������") { score = 4; }
				else if (getMark == "�������") { score = 5; }
				if ((students_vector[k].disciplines[i].name == disciplineMap[i]) && (students_vector[k].groupNumber == groupMap[j]))
				{
					matrix[i][j][0] += score;
					matrix[i][j][1] += 1;
				}
			}
		}
	}

	cout << endl << "������� ���� �� �������" << endl << endl;
	cout << "------------------------------------------------------------" << endl;
	for (int i = 0; i < numberOfGroup; i++)
	{
		cout << "������ " << groupMap[i] << endl;
		for (int j = 0; j < numberOfDiscipline; j++)
		{
			cout << setw(35) << left << disciplineMap[j] << setw(25) << right << (double)matrix[j][i][0] / matrix[j][i][1] << endl;
		}
		cout << "------------------------------------------------------------" << endl;
	}
	
}