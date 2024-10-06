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
		{3, 14},
		{4, 15}
	};
	map<int, string> markMap =
	{	{0, "Неудовлетворительно"},
		{1, "Удовлетворительно"},
		{2, "Хорошо"},
		{3, "Отлично"}
	};
	setlocale(LC_ALL, "Russian");
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
}