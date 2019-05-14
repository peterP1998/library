#define _CRT_SECURE_NO_WARNINGS
#include "Author.h"
#include<cstring>
#include "Set.h"
Author::Author(const char* name, const char* nationality, int age) :Reader(name,nationality,age)
{


}

void Author::print()const
{
    this->Person::print();
	this->writtenBooks.print();

}
void Author::writeBook(Book& book)
{
	this->writtenBooks.insert(book);

}
int Author:: getWrittenBooks()const
{
	return this->writtenBooks.getSize();
}
int Author::getWritingRank()const
{
	return this->getReadBooksCount();
}





