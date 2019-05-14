#ifndef _AUTHOR_H
#define _AUTHOR_H
#include "Reader.h"
#include "BookContainer.h"
#include "WritingRankable.h"
#include<iostream>
using namespace std;
class Author:public Reader,public WritingRankable
{
private:
	BookContainer writtenBooks;
	
public:
	Author(const char* name="" , const char* nationality="" , int age=0);
    void writeBook(Book&);

	int getWrittenBooks()const;

	void print()const;

	int getWritingRank() const;

};
#endif