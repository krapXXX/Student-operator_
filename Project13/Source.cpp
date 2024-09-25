#include<iostream>
#include<Windows.h>
using namespace std;

class Student
{
	char* name;
	int age;
public:
	////  prototype 
	Student();
	Student(const char*, int); // construct by 2 param
	void Output();
	~Student();
	Student& operator=(const Student& a);
	Student(const Student& a);
};
Student::Student()
{
	name = nullptr;
	age = 0;
}
Student::Student(const char* Name, int Age)
{
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
	age = Age;
}
Student::Student(const Student& a)
{
	name = new char[strlen(a.name) + 1];
	strcpy_s(name, strlen(a.name) + 1, a.name);
	age = a.age;
}
void Student::Output()
{
	cout << "Name: " << name << endl
		<< "Age: " << age << endl << endl;
}
Student::~Student()
{

	delete[] name;

	cout << "Destruct\n";
	Sleep(1000);

}
Student& Student::operator=(const Student& a)
{
	if (this == &a)
	{
		return *this;
	}
	if (name != nullptr)
	{
		delete[]name;
	}
	name = new char[strlen(a.name) + 1];
	strcpy_s(name, strlen(a.name) + 1, a.name);
	age = a.age;

	return *this;
}

int main()
{
	Student obj1("Oleg", 21);
	obj1.Output();

	Student mas[2]{ {"Alena",20 }, {"Maksim", 22} };
	for (int i = 0; i < 2; i++)
	{
		mas[i].Output();
	}
	Student obj2("Ann", 19);
	Student obj3 = obj2;
	obj2.Output();
	obj3.Output();
	obj2 = obj1;
	obj2.Output();

	system("pause");
}