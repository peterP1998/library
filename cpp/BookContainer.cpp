#include "BookContainer.h"
#include "Set.h"
#include "Author.h"
BookContainer::BookContainer(int capacity) :Set(capacity)
{

}

bool BookContainer::compareBooks(const Book* book1, const Book* book2)
{
	return  book1->getNumberOfPages() > book2->getNumberOfPages();
}

void BookContainer::sort(bool(*compareBooks)(const Book* book1, const Book* book2))
{
	for (int i = 0; i < this->getSize()-1; i++)
	{
		for (int j = i; j < this->getSize() - 1; j++)
		{
			if (compareBooks(getObjects()[j],getObjects()[j+1]))
			{
				Book *tmp = getObjects()[j];
				getObjects()[j] = getObjects()[j+1];
				getObjects()[j+1] = tmp;
			}
		}
	}
	for (int i = 0; i <this->getSize(); i++)
	{
		this->getObjects()[i]->print();
	}
}
BookContainer BookContainer:: byAuthor(const  Author& author)
{

	BookContainer c;
	for (int i = 0; i < this->getSize(); i++)
	{
	if (&author ==(*this)[i].getAuthor())
		{
			c.insert(*this->getObjects()[i]);
		}
	}
	cout << c.getSize() << endl;

	return c;
	
}