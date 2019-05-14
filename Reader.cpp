#include "Reader.h"
#include "Set.h"
Reader::Reader(const char* name, const char* nationality, int age) :Person(name, nationality, age)
{

}
Reader::Reader()
{
	this->setNationality("");
	this->setName("");
	this->setAge(0);
}
void Reader::readBook(Book& book)
{
	this->readBooks.insert(book);
}
int Reader::getReadBooksCount()const
{
	return this->readBooks.getSize();
}
void Reader::print()const
{
	this->Person::print();
	this->readBooks.print();
}
int Reader::getReadingRank() const
{
	return this->getReadBooksCount();
}