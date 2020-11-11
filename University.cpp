#include <iostream>
#include <vector>
#include <fstream>
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
protected:
	vector<string> st_name;
	vector<string> st_surname;
	string name;
	string surname;
public:
	///
};

class Student : public Human {
private:
	string status;
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
		average_score = rand() % 10 + 1;
		st_average_score.push_back(average_score);
	}

	void receive_grants() {
		if (status == "p")
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
			cout << i << ") " << st_name[i] << " " << st_surname[i] << endl;
			cout << "Статус студента: " << st_status[i] << endl;
			cout << "Средний балл за сессию: " << st_average_score[i] << endl;
			cout << "Размер начисляемой стипендии: " << st_grants[i] << " BYN" << endl;
		}
	}
};

class Teacher : public Human {
private:
	string status;
	string specialty;
	int number_of_hours;
public:
	void count_number_of_hours() {
		///
	}
	void salary() {
		///
	}
};

int main() {
	setlocale(0, "rus");
	Human hu;
	Student st;
	int buff = 0;
	do
	{

		cout << "\tДобро пожаловать в университет!\n";
		cout << "1. Добавить студента\n";
		cout << "2. Вывод студентов\n";
		cout << "Выберете пункт меню и нажмите Enter: ";
		cin >> buff;
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
		}

	} while (true);

}