#ifndef BookContainer_H_INCLUDED
#define BookContainer_H_INCLUDED
#include "Book.h"
#include "Set.h"
class BookContainer:public Set<Book>
{
private:
	bool compareBooks(const Book* book1, const Book* book2);
	int cap;
public :
	BookContainer(int cap = 1);
	void sort(bool(*compareBooks)(const Book* book1, const Book* book2));
BookContainer byAuthor(const  Author& author);
};
#endif BookContainer_H_INCLUDED