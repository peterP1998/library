#ifndef Book_H_INCLUDED
#define Book_H_INCLUDED
#include <iostream>
enum Genre { NotSpecified , Drama, Comedy, Lyric, Thriller,Fantasy };


class Author;

class Book {
	private:
	char* title;
	int numberOfPages;
	int year;
	const Author* author;
	Genre genre;
	double price;
public:
	Book();
	Book(const char*, int, int, const Author*, Genre, double);
	~Book();
	Book(const Book&);
	Book& operator=(const Book&);

	Book* clone() const { return new Book(*this); }
	const char* getTitle()const;
	void setTitle(const char*);

	int getNumberOfPages()const { return this->numberOfPages; }
	void setNumberOfPages(int);

	int getYear()const { return this->year; }
	void setYear(int);

	const Author* getAuthor() { return this->author; }
	void setAuthor(const Author*);

	Genre getGenre()const { return this->genre; }
	void setGenre(Genre);

	double getPrice()const { return this->price; }
	void setPrice(double);

	void print()const;
	friend std::istream& operator>>(std::istream&, Book&);
	friend std::ostream& operator<<(std::ostream&, const Book&);

	bool operator==(const Book&)const;
	bool operator!=(const Book&)const;
	bool operator<(const Book&)const;
	bool operator>(const Book&)const;
	bool operator<=(const Book&)const;
	bool operator>=(const Book&)const;
	operator bool() const
	{
		return title != NULL || numberOfPages != 0 || year != 0 || author != NULL || genre != 0 || price != 0;
	}
	bool operator!() const
	{
		return !(bool(*this));
	}
};
#endif


