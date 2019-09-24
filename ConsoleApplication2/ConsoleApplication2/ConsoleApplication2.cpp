#include "stdafx.h"
#include <iostream>
#include <fstream>
#define N 3
#define M 20
using namespace std;
struct Identification_of_students_by_gender
{
	char surname[M], name[M], gender[M], course[M], group[M];


};
struct Identification_of_students_by_age
{
	char surname1[M], name1[M];

	struct
	{
		unsigned int day, month, year;
	} birthday;
};

void CreateData(struct Identification_of_students_by_gender *student, int i)
{

	for (int j = 0; j < i; j++)
	{
		Identification_of_students_by_gender *st = &student[j];
		cout << endl << "Student" << j + 1 << endl;
		cout << "Surname : " << endl;
		cin >> st->surname;
		cout << "Name : " << endl;
		cin >> st->name;
		cout << "Gender : " << endl;
		cin >> st->gender;
		cout << "Course : " << endl;
		cin >> st->course;
		cout << "Group : " << endl;
		cin >> st->group;
	}
}


void CreateData1(struct Identification_of_students_by_age *person, int i)
{

	for (int j = 0; j < i; j++)
	{
		Identification_of_students_by_age *pr = &person[j];
		cout << endl << "Person" << j + 1 << endl;
		cout << "Surname : " << endl;
		cin >> pr->surname1;
		cout << "Name : " << endl;
		cin >> pr->name1;
		cout << "Day of birthday : " << endl;
		cin >> pr->birthday.day;
		cout << "Month of birthday : " << endl;
		cin >> pr->birthday.month;
		cout << "Year of birthday : " << endl;
		cin >> pr->birthday.year;
	}

}

void RW(struct Identification_of_students_by_gender *student, int i, int j) //Функція запису RW() у типізований файл INFO.TXT у вигляді структури
{
	ofstream info("INFO.TXT");

	for (j = 0; j < i; j++)
	{
		Identification_of_students_by_gender *st = &student[j];
		info << st->surname << endl << st->name << endl << st->gender << st->course << endl << st->group << endl;


	}
}

void RD(struct Identification_of_students_by_gender *student1, int i, int m) //Функція читання RD() з файлу INFO.TXT для виведення вмісту файлу на екран
{
	struct Identification_of_students_by_gender t1;
	char gender[M];
	cout << endl << " Please, enter the gender : " << endl;
	cin >> gender;
	ifstream file;
	file.open("INFO.TXT");

	cout << endl << " Male students : " << endl;

	for (int j = 0; j < i; j++)
	{
		Identification_of_students_by_gender *st = &student1[j];
		file.getline(st->surname, 20);

		file.getline(st->name, 20);

		file.getline(st->course, 20);

		file.getline(st->group, 20);
	}
	for (int n = 0; n < i; n++)
	{
		if (strstr(student1[n].gender, gender) != NULL)
		{
			Identification_of_students_by_gender *st = &student1[n];
			cout << endl << st->surname << endl;

			cout << st->name << endl;

			cout << st->course << endl;

			cout << st->group << endl;

		}
	}

}


void RW(struct Identification_of_students_by_age *person, int i) //Функція запису RW() у типізований файл INFO.DAT у вигляді структури
{
	ofstream info("INFO.DAT");

	for (int j = 0; j < i; j++)
	{

		Identification_of_students_by_age *pr = &person[j];
		info << pr->surname1 << endl << pr->name1 << endl << pr->birthday.day << endl << pr->birthday.month << endl << pr->birthday.year << endl;
	}



}

void RD(struct Identification_of_students_by_age *person1, int i)//Функція читання RD() з файлу INFO.DAT для виведення вмісту файлу на екран
{

	ifstream file;
	file.open("INFO.DAT");

	cout << endl << " The oldest student: " << endl;

	for (int j = 0; j < i; j++)
	{
		Identification_of_students_by_age *pr = &person1[j];
		file >> pr->surname1;
		file >> pr->name1;
		file >> pr->birthday.day;
		file >> pr->birthday.month;
		file >> pr->birthday.year;
	}




	for (i = 0; i < N; i++)
	{
		for (int g = i + 1; g<N; g++)
		{
			if (person1[i].birthday.year > person1[g].birthday.year)
			{
				Identification_of_students_by_age tmp = person1[i];
				person1[i] = person1[g];
				person1[g] = tmp;
			}
		}

	}
	for (i = 0; i < N; i++)
	{
		Identification_of_students_by_age *pr = &person1[i];
		cout << endl << pr->surname1 << endl;
		cout << pr->name1 << endl;
	}


}



void main()
{
	struct Identification_of_students_by_gender student[N];
	struct Identification_of_students_by_age person[N];
	CreateData(student, N);
	CreateData1(person, N);
	RW(student, N, 0);
	RD(student, N, 0);
	RW(person, N);
	RD(person, N);
	cin.get();
}