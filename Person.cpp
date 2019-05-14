#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
using namespace std;
#include "Person.h"
Person::~Person()
{
	delete[] this->name;
	delete[] this->nationality;
}
void Person::setNationality(const char* nationality)
{
	if (!nationality)nationality = "";

	delete[] this->nationality;
	this->nationality = new char[strlen(nationality) + 1];
	strcpy(this->nationality, nationality);
}
void Person::setName(const char* name) 
{
	if (!name) name = "";

	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Person::setAge(int age)
{
	if (age >= 0)
	{
		this->age = 0;
	}
}
void Person::copy(const Person& other)
{
	this->setAge(other.age);
	this->setName(other.name);
	this->setNationality(other.nationality);
}
Person::Person(const char*name, const char* nationality, int age):name(NULL),nationality(NULL)
{
	this->setAge(age);
	this->setName(name);
	this->setNationality(nationality);
}
Person::Person(const Person& other):name(NULL),nationality(NULL)
{
	copy(other);
}
Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}
bool Person::operator<(const Person& other)const
{
	if (this->age < other.age&& strcmp(this->name,other.name)<0&& strcmp(this->nationality, other.nationality)<0)
	{
		return true;
	}
	return false;
}
bool Person::operator>(const Person& other)const
{
	return (!(*this < (other)));
}
bool Person::operator<=(const Person& other)const
{
	return (*this == other) || (*this < other);
}
bool Person::operator>=(const Person& other)const
{
	return (*this == other) || (*this > other);
}
bool Person::operator==(const Person& other)const
{
	if (this->age == other.age && strcmp(this->name, other.name) == 0 && strcmp(this->nationality, other.nationality) == 0)
	{
		return true;
	}
	return false;
}
bool Person::operator!=(const Person& other)const
{
	return !(*this == other);
}
istream& operator>>(istream& is, Person& p)
{
	is >> p.name >> p.nationality >> p.age;
	return is;
}
ostream& operator<<(ostream& os, const Person& p)
{
	os << "Name:" << p.name << " Nationality" << p.nationality << " NumberOfBooks:" << p.age;
	return os;
}
bool Person::operator()()const
{
	return this->age == 0;
}
bool Person::operator!()const
{
	return this->age != 0;
}
void Person::print()const
{
	cout << this->age << "  " << this->name << "   " << this->nationality << endl;
}
