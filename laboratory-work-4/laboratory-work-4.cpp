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

vector<double> findMax(const vector<vector<double>>& vec)
{
	int maIndex = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i][1] > vec[maIndex][1])
		{
			maIndex = i;
		}
	}
	return vec[maIndex];
}

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
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	srand(unsigned(time(0)));

	map<int, string> studentMap =
	{
		{0, "Èâàíîâ Èâàí Èâàíîâè÷"}, {1, "Ïåòðîâ Ïåòð Ïåòðîâè÷"}, {2, "Ñèäîðîâ Ñåðãåé Ñåðãååâè÷"}, {3, "Êóçíåöîâ Íèêîëàé Íèêîëàåâè÷"},
		{4, "Ñìèðíîâ Àëåêñåé Àëåêñååâè÷"}, {5, "Ìîðîçîâ Âèêòîð Âèêòîðîâè÷"}, {6, "Êèñåëåâ Àíäðåé Àíäðååâè÷"}, {7, "Âîëêîâ Âëàäèìèð Âëàäèìèðîâè÷"},
		{8, "Ôåäîðîâ Ôåäîð Ôåäîðîâè÷"}, {9, "Ñîêîëîâ Àëåêñàíäð Àëåêñàíäðîâè÷"}, {10, "Ïîïîâ Ïàâåë Ïàâëîâè÷"}, {11, "Ëåáåäåâ Äìèòðèé Äìèòðèåâè÷"},
		{12, "Êîçëîâ Àðòåì Àðòåìîâè÷"}, {13, "Íîâèêîâ Àíòîí Àíòîíîâè÷"}, {14, "Çàéöåâ Ìèõàèë Ìèõàéëîâè÷"}, {15, "Áåëîóñîâ Âàñèëèé Âàñèëüåâè÷"},
		{16, "Åãîðîâ Àëåêñåé Àëåêñååâè÷"}, {17, "Áàðàíîâ Èãîðü Èãîðåâè÷"}, {18, "Ìåäâåäåâ Îëåã Îëåãîâè÷"}, {19, "Ãîðáóíîâ Ñåìåí Ñåìåíîâè÷"},
		{20, "×åðíîâ Äåíèñ Äåíèñîâè÷"}, {21, "Ñîëîâüåâ Ðîìàí Ðîìàíîâè÷"}, {22, "Æóêîâ Âàëåðèé Âàëåðüåâè÷"}, {23, "Áîðèñîâ Ñòàíèñëàâ Ñòàíèñëàâîâè÷"},
		{24, "Ïîëÿêîâ Àðêàäèé Àðêàäüåâè÷"}, {25, "Ìàêàðîâ Åâãåíèé Åâãåíüåâè÷"}, {26, "Òèòîâ Êèðèëë Êèðèëëîâè÷"}, {27, "Àíòîíîâ Êîíñòàíòèí Êîíñòàíòèíîâè÷"},
		{28, "Âàñèëüåâ Þðèé Þðüåâè÷"}, {29, "Íèêîëàåâ Âèêòîð Âèêòîðîâè÷"}
	};

	map<int, int> groupMap =
	{
		{0, 11},
		{1, 12},
		{2, 13},
	};

	map<int, string> markMap =
	{	{0, "Íåóäîâëåòâîðèòåëüíî"},
		{1, "Óäîâëåòâîðèòåëüíî"},
		{2, "Õîðîøî"},
		{3, "Îòëè÷íî"}
	};

	map<int, string> disciplineMap =
	{
		{0, "Ìàòåìàòè÷åñêèé àíàëèç"},
		{1, "Àíàëèòè÷åñêàÿ ãåîìåòðèÿ"},
		{2, "Àëãîðèòìè÷åñêèå ÿçûêè"},
		{3, "Òåîðåòè÷åñêàÿ èíôîðìàòèêà"},
		{4, "Ôèçè÷åñêàÿ êóëüòóðà"}
	};

	int numberOfStudents, numberOfGroup, numberOfDiscipline;
	cout << "Ââåäèòå êîëè÷åñòâî ñòóäåíòîâ: ";
	cin >> numberOfStudents;
	cout << "Ââåäèòå êîëè÷åñòâî ãðóïï: ";
	cin >> numberOfGroup;
	cout << "Ââåäèòå êîëè÷åñòâî äèñöèïëèí: ";
	cin >> numberOfDiscipline;
	if (numberOfStudents > MAX_STUDENTS || numberOfGroup > MAX_GROUP || numberOfDiscipline > MAX_DISCIPLINE)
	{
		cout << "Îøèáêà ââîäà!";
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
		cout << setw(14) << left << "ÔÈÎ: " << students_vector[i].fullName << endl;
		cout << "Íîìåð ãðóïïû: " << students_vector[i].groupNumber << endl;
		cout << setw(14) << left << "Äèñöèïëèíû: " << endl << endl;
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
				if (getMark == "Íåóäîâëåòâîðèòåëüíî") { score = 2; }
				else if (getMark == "Óäîâëåòâîðèòåëüíî") { score = 3; }
				else if (getMark == "Õîðîøî") { score = 4; }
				else if (getMark == "Îòëè÷íî") { score = 5; }
				if ((students_vector[k].disciplines[i].name == disciplineMap[i]) && (students_vector[k].groupNumber == groupMap[j]))
				{
					matrix[i][j][0] += score;
					matrix[i][j][1] += 1;
				}
			}
		}
	}

	cout << endl << "Ñðåäíèé áàëë ïî ãðóïïàì" << endl << endl;
	cout << "------------------------------------------------------------" << endl;
	for (int i = 0; i < numberOfGroup; i++)
	{
		cout << "Ãðóïïà " << groupMap[i] << endl;
		for (int j = 0; j < numberOfDiscipline; j++)
		{
			cout << setw(35) << left << disciplineMap[j] << setw(25) << right << (double)matrix[j][i][0] / matrix[j][i][1] << endl;
		}
		cout << "------------------------------------------------------------" << endl;
	}
	vector<vector<vector<double>>> avg_matrix(numberOfDiscipline, vector<vector<double>>(numberOfGroup, vector<double>(2)));
	for (int i = 0; i < numberOfDiscipline; i++)
	{
		for (int j = 0; j < numberOfGroup; j++)
		{
			avg_matrix[i][j][0] = j + 11;
			avg_matrix[i][j][1] = (double)matrix[i][j][0] / matrix[i][j][1];
		}
	}
	cout << endl << "Ëó÷øèå ãðóïïû" << endl << endl;
	cout << "------------------------------------------------------------" << endl;
	for (int i = 0; i < numberOfDiscipline; i++)
	{
		cout << left << setw(30) << disciplineMap[i]
			<< setw(10) << ("Ãðóïïà " + to_string((int)findMax(avg_matrix[i])[0])) <<
			setw(16) << right << fixed << setprecision(2) << "Áàëë " << findMax(avg_matrix[i])[1]
			<< endl;
	}
	cout << "------------------------------------------------------------" << endl;
}
