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
		{0, "Иванов Иван Иванович"}, {1, "Петров Петр Петрович"}, {2, "Сидоров Сергей Сергеевич"}, {3, "Кузнецов Николай Николаевич"},
		{4, "Смирнов Алексей Алексеевич"}, {5, "Морозов Виктор Викторович"}, {6, "Киселев Андрей Андреевич"}, {7, "Волков Владимир Владимирович"},
		{8, "Федоров Федор Федорович"}, {9, "Соколов Александр Александрович"}, {10, "Попов Павел Павлович"}, {11, "Лебедев Дмитрий Дмитриевич"},
		{12, "Козлов Артем Артемович"}, {13, "Новиков Антон Антонович"}, {14, "Зайцев Михаил Михайлович"}, {15, "Белоусов Василий Васильевич"},
		{16, "Егоров Алексей Алексеевич"}, {17, "Баранов Игорь Игоревич"}, {18, "Медведев Олег Олегович"}, {19, "Горбунов Семен Семенович"},
		{20, "Чернов Денис Денисович"}, {21, "Соловьев Роман Романович"}, {22, "Жуков Валерий Валерьевич"}, {23, "Борисов Станислав Станиславович"},
		{24, "Поляков Аркадий Аркадьевич"}, {25, "Макаров Евгений Евгеньевич"}, {26, "Титов Кирилл Кириллович"}, {27, "Антонов Константин Константинович"},
		{28, "Васильев Юрий Юрьевич"}, {29, "Николаев Виктор Викторович"}
	};

	map<int, int> groupMap =
	{
		{0, 11},
		{1, 12},
		{2, 13},
	};

	map<int, string> markMap =
	{	{0, "Неудовлетворительно"},
		{1, "Удовлетворительно"},
		{2, "Хорошо"},
		{3, "Отлично"}
	};

	map<int, string> disciplineMap =
	{
		{0, "Математический анализ"},
		{1, "Аналитическая геометрия"},
		{2, "Алгоритмические языки"},
		{3, "Теоретическая информатика"},
		{4, "Физическая культура"}
	};

	int numberOfStudents, numberOfGroup, numberOfDiscipline;
	cout << "Введите количество студентов: ";
	cin >> numberOfStudents;
	cout << "Введите количество групп: ";
	cin >> numberOfGroup;
	cout << "Введите количество дисциплин: ";
	cin >> numberOfDiscipline;
	if (numberOfStudents > MAX_STUDENTS || numberOfGroup > MAX_GROUP || numberOfDiscipline > MAX_DISCIPLINE)
	{
		cout << "Ошибка ввода!";
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
		cout << "ФИО: " << students_vector[i].fullName << endl;
		cout << "Номер группы: " << students_vector[i].groupNumber << endl;
		cout << "Дисциплины: " << endl;
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