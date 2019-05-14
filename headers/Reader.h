#pragma once
#include "BookContainer.h"
#include "Person.h"
#include "ReadingRankable.h"
class Reader:public Person,public ReadingRankable
{
private:
	BookContainer readBooks;
public:
	Reader(const char* name, const char* nationality, int age);
	Reader();
	void readBook(Book&);
	int getReadBooksCount()const;
	void print()const;
	int getReadingRank() const;
	Reader* clone()const { return new Reader(*this); }
};