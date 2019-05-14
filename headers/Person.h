#ifndef _PERSON_H
#define _PERSON_H
#include<iostream>
class Person
{
private:
	char* name;
	char* nationality;
	void copy(const Person&);
	int age;
public:
	Person(const char* name="", const char*nationality="", int age=0);
	 ~Person();
	Person(const Person&);
	Person& operator=(const Person&);

	const char* getName()const { return (!this->name) ? "" : this->name; }
	void setName(const char*);

	int getAge()const { return this->age; }
	void setAge(int);

	const char* getNationality()const { return (!this->nationality) ? "" : this->nationality; }
	void setNationality(const char*);

	bool operator<(const Person&)const;
	bool operator>(const Person&)const;
	bool operator<=(const Person&) const;
	bool operator>=(const Person&) const;
	 bool operator!=(const Person&) const;
 bool operator==(const Person&) const;

	friend std::istream& operator>>(std::istream& is, Person& p);
	friend std::ostream& operator << (std::ostream &os, const  Person& p);

	bool operator()()const;
	bool operator!() const;

	 void print()const;
};
#endif