#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <windows.h>
using namespace std;

class University {
protected:
	/*string FITU = ("АСОИ", "ИИ", "ИТИУТС", "ПЭ", "ГеймДиз");
	string СSaN = ("ПОИТ", "ВМСиС", "ИиТП", "ЭВС");
	string IEF = ("ЭЭБ","ЭМ","ИСиТвЛог", "ИСиТвЭК");*/
	vector<string> FITU;
public:
	void expel_student() {
		///
	}
	void enroll_applicant() {
		///
	}
};

class Human {
public:
	string name;
	string surname;	
};

class Student : public Human {
private:
	string status;
	vector<string> st_name;
	vector<string> st_surname;
	char group;
	int grants;
	int number_of_passes;
	int average_score;
	vector <int> st_grants;
	vector <double> st_average_score;
	vector <string> st_status;
public:
	void create_stud() {
		cout << "Введите имя: ";
		cin >> name;
		cout << "Введите фамилию: ";
		cin >> surname;
		st_name.push_back(name);
		st_surname.push_back(surname);
		student_status();
		pass_exams();
		receive_grants();
	}

	void student_status() {
		cout << "Введите статус студента (бюджетник/платник): ";
		cin >> status;
		st_status.push_back(status);
	}

	void pass_exams() {
		srand(time(0));
		average_score = rand() % 10 + 1;
		st_average_score.push_back(average_score);
	}

	void receive_grants() {
		if (status == "платник")
		{
			grants = 0;
			st_grants.push_back(grants);
		}
		if (average_score > 4.0 && average_score <= 6.0)
		{
			grants = 50;
			st_grants.push_back(grants);
		}
		if (average_score > 6.0 && average_score <= 8.0)
		{
			grants = 100;
			st_grants.push_back(grants);
		}
		if (average_score > 8.0)
		{
			grants = 130;
			st_grants.push_back(grants);
		}
		if (average_score < 4.0)
		{
			grants = 0;
			st_grants.push_back(grants);
		}
	}

	void showStudents() {
		for (int i = 0; i < st_name.size(); i++)
		{
			cout << st_name[i] << " " << st_surname[i] << endl;
			cout << "Статус студента: " << st_status[i] << endl;
			cout << "Средний балл за сессию: " << st_average_score[i] << endl;
			cout << "Размер начисляемой стипендии: " << st_grants[i] << " BYN" << endl;
		}
	}
};

class Teacher : public Human {
private:
	string teach_status;
	string specialty;
	int number_of_hours;
	int salary = 0;
	vector<string> teacher_name;
	vector<string> teacher_surname;
	vector<int> teachrs_number_of_hours;
	vector<int> teachers_salary;
	vector<string> teachers_status;
public:
	void creat_taecher() {
		cout << "Введите имя: ";
		cin >> name;
		cout << "Введите фамилию: ";
		cin >> surname;
		teacher_name.push_back(name);
		teacher_surname.push_back(surname);
		status_of_teacher();
		working_hours();
		teach_salary();
	}

	void status_of_teacher() {
		cout << "Введите должность преподавателя: ";
		cin >> teach_status;
		teachers_status.push_back(teach_status);
	}

	void working_hours() {
		srand(time(0));
		number_of_hours = rand() % 21 + 15;
		teachrs_number_of_hours.push_back(number_of_hours);
	}

	void teach_salary() {
		/*if (teach_status == "p")
		{
			salary += 200;
		}*/
		//teachers_salary.push_back(salary);
		if (number_of_hours > 15 && number_of_hours < 20)
		{
			salary = 500;
			teachers_salary.push_back(salary);
		}
		if (number_of_hours > 20 && number_of_hours < 30)
		{
			salary = 800;
			teachers_salary.push_back(salary);
		}
		if (number_of_hours > 30 && number_of_hours <= 35)
		{
			salary = 1200;
			teachers_salary.push_back(salary);
		}
	}

	void showTeachers() {
		for (int i = 0; i < teacher_name.size(); i++)
		{
			cout << teacher_name[i] << " " << teacher_surname[i] << endl;
			cout << "Статус преподавателя: " << teachers_status[i] << endl;
			cout << "Выработка часов: " << teachrs_number_of_hours[i] << endl;
			cout << "Размер начисляемой зарплаты: " << teachers_salary[i] << " BYN" << endl;
		}
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "rus");
	Human hu;
	Student st;
	Teacher teacher;
	int buff = 0;
	do
	{

		cout << "\tДобро пожаловать в университет!\n";
		cout << "1. Добавить студента\n";
		cout << "2. Вывод студентов\n";
		cout << "3. Добавить преподавателя\n";
		cout << "4. Вывод преподавателей\n";
		cout << "Выберете пункт меню и нажмите Enter: ";
		cin >> buff;
		cout << "\n\n";
		switch (buff)
		{
		case 1: {
			st.create_stud();
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			st.showStudents();
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			teacher.creat_taecher();
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			teacher.showTeachers();
			system("pause");
			system("cls");
			break;
		}
		}

	} while (true);

}