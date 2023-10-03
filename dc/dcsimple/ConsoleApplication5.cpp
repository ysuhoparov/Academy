#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <vector>
#include <exception>
#include<windows.h>
using namespace std;


class Cat
{
	string name;
	int flat{}, age{}, id{};
public:
	void setAge(int age)
	{
		if (age > 15)
		{
			age = 15;
		}
		this->age = age;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setFlat(int flat)
	{
		this->flat = flat;
	}
	void setID(int id)
	{
		this->id = id;
	}
	int getAge()
	{
		return age;
	}
	string getName()
	{
		return name;
	}
	Cat(int id, int flat, string name, int age)
	{
		setID(id);
		setFlat(flat);
		setName(name);
		setAge(age);
	}
};
void LoadFrom(vector<Cat>& cat)
{
	int id, flat, age;
	string name;
	ifstream openFile("cats.txt");
	if (!openFile)
	{
		throw exception("Не удалось открыть файл!");
	}
	while (!openFile.eof())
	{
		openFile >> id >> flat >> name >> age;
		if (!openFile.eof())
		{
			cat.push_back(Cat(id, flat, name, age));
		}
	}
}
void List(vector<Cat>& cat)
{
	ifstream openFile("cats.txt");
	if (!openFile)
	{
		throw exception("Не удалось открыть файл!");
	}
	if (!openFile.eof())
	{
		for (vector<Cat>::iterator it = cat.begin(); it != cat.end(); it++)
		{
			cout << *it << " ";
		}
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	return 0;
}