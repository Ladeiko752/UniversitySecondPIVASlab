#include <iostream>
#include <vector>
using namespace std;

class Human {
protected:
	string name;
	string surname;
	int cash_account;
public:
	void have_name() {
		cout << name << " " << surname;
	}
};

class Student : public Human {
private:
	int group_number;
	int CT_score;
	string status;
protected:
	double average_score;
public:
	void receive_scholarship(double average_score, string name) {
		if (average_score < 4.0)
		{
			cout << "Не получает стипендию!";
		}
		else
		{
			cout << "Получает стипендию!";
			if (average_score >= 4.0 && average_score <= 6.0)
			{
				cash_account = 70;
				cout << "Размер стипендии составляет " << cash_account << "BYN" << endl;
			}
			if (average_score > 6.0 && average_score <= 8.0)
			{
				cash_account = 80;
				cout << "Размер стипендии составляет " << cash_account << "BYN" << endl;
			}
			if (average_score > 8.0)
			{
				cash_account = 120;
				cout << "Размер стипендии составляет " << cash_account << "BYN" << endl;
			}
		}
	}
};

class Teachers : public Human {
private:
	string science_degree;
	string specialty;
	int hours_at_work_in_week;
public:
	void recieve_payment(int hours_at_work_in_week) {
		if (hours_at_work_in_week < 15)
		{
			cash_account = 400;
			cout << name << " работая преподователем зарабатывает " << cash_account << "BYN" << endl;
		}
		if (hours_at_work_in_week > 15 && hours_at_work_in_week < 35)
		{
			cash_account = 700;
			cout << name << " работая преподователем зарабатывает " << cash_account << "BYN" << endl;
		}
		if (hours_at_work_in_week > 35)
		{
			cash_account = 1200;
			cout << name << " работая преподователем зарабатывает " << cash_account << "BYN" << endl;
		}
	}
};

class Extramural_student : public Student {
	// заочник не получает стипендию
	//
};

class Graduate_student : public Teachers {
	// 
};

int main()
{
	setlocale(0, "rus");

	int buff, student_buff, teacher_buff = 0;
	double middle_val = 0;
	int salary = 0;
	string student_name;
	string teacher_name;
	Student baby;
	Teachers mentor;

	vector<string> mystudents;
	vector<double> students_marks;
	vector<string> myteachers;
	vector <int> teachers_salary;
	do
	{
		cout << "\tMENU\n";
		cout << "1. Ученик\n";
		cout << "2. Преподователь\n";
		cout << "Выберете пункт меню и нажмите Enter: ";
		cin >> buff;
		cout << "\n\n";
		switch (buff)
		{
		case 1: {
			do
			{
				cout << "1. Добавить студента" << endl;
				cout << "2. Вывод информации о студентах" << endl;
				cout << "3. Выход" << endl;
				cout << "Выберете пункт меню и нажмите Enter: ";
				cin >> student_buff;
				cout << endl;
				switch (student_buff)
				{
				case 1: {
					cout << "Введите имя и фамилию студента: ";
					cin >> student_name;
					cout << "Введите средний балл студента: ";
					cin >> middle_val;
					mystudents.push_back(student_name);
					students_marks.push_back(middle_val);
					system("pause");
					system("cls");
					break;
				}
				case 2: {
					for (int i = 0; i < mystudents.size() && students_marks.size(); i++)
					{
						cout << i + 1 << ")" << mystudents[i] << endl;
						cout << "Средний балл за семестр: " << students_marks[i] << endl;
						baby.receive_scholarship(middle_val, student_name);
						cout << endl;
					}
					system("pause");
					system("cls");
					break;
				case 3: {
					return 0;
				}
				}
				}

			} while (true);
		}
		case 2: {
			do
			{
				cout << "1. Добавить преподавателя" << endl;
				cout << "2. Вывод информации о преподавателе" << endl;
				cout << "3. Выход" << endl;
				cout << "Выберете пункт меню и нажмите Enter: ";
				cin >> teacher_buff;

				switch (teacher_buff)
				{
				case 1: {
					cout << "Введите имя и фамилию преподавателя: ";
					cin >> teacher_name;
					cout << "Введите выработку часов в неделю: ";
					cin >> salary;
					myteachers.push_back(teacher_name);
					teachers_salary.push_back(salary);
					system("pause");
					system("cls");
					break;
				}
				case 2:
					for (int i = 0; i < myteachers.size() && teachers_salary.size(); i++)
					{
						cout << i + 1 << ")" << myteachers[i] << endl;
						cout << "Выработка часов в неделю: " << teachers_salary[i] << endl;
						mentor.recieve_payment(salary);
						cout << endl;
					}
				}
		case 3: {
			return 0;
		}
			} while (true);
		}

		}
	} while (true);
}