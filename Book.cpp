#define _CRT_SECURE_NO_WARNINGS
#include "Author.h"
#include<iostream>
#include<cstring>

Book::Book() :title(NULL)
{
	this->setTitle("Harry Potter and the Order of the Phoenix");
	this->setNumberOfPages(870);
	this->author = NULL;
	this->setYear(2003);
	this->setGenre(Fantasy);
	this->setPrice(15.5);
}
Book::Book(const char*title, int pages, int year, const Author* author, Genre genre, double price) :title(NULL)
{
	this->setTitle(title);
	this->setNumberOfPages(pages);
	this->setYear(year);
	this->setAuthor(author);
	this->setGenre(genre);
	this->setPrice(price);
}
Book::~Book()
{
	delete[]this->title;
}
Book::Book(const Book&other) :title(NULL)
{
	this->setTitle(other.title);
	this->setNumberOfPages(other.numberOfPages);
	this->setYear(other.year);
	this->setAuthor(other.author);
	this->setGenre(other.genre);
	this->setPrice(other.price);
}
Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		this->setTitle(other.title);
		this->setNumberOfPages(other.numberOfPages);
		this->setYear(other.year);
		this->setAuthor(other.author);
		this->setGenre(other.genre);
		this->setPrice(other.price);
	}
	return *this;
}
const char* Book::getTitle()const
{
	return this->title;
}
void Book::setTitle(const char*title)
{
	if (!title) title = "";
	int len = strlen(title);
	if (this->title != nullptr)
	{
		delete[]this->title;
	}
	this->title = new char[len + 1];
	strcpy(this->title, title);
}
void Book::setGenre(Genre genre)
{
	this->genre = genre;
}
void Book::setNumberOfPages(int numberOfPages)
{
	this->numberOfPages = numberOfPages;
}
void Book::setYear(int year)
{
	this->year = year;
}
void Book::setAuthor(const Author* author)
{
	this->author = author;
}
void Book::setPrice(double price)
{
	this->price = price;
}
bool Book :: operator==(const Book&other)const
{
	return strcmp(this->title, other.title) == 0 && this->numberOfPages == other.numberOfPages && this->year == other.year 
		&&  this->genre == other.genre && this->price == other.price;
}
bool Book::operator!=(const Book&other)const
{
	return(!(this == &other));
}
bool Book::operator<(const Book&other)const
{
	return strcmp(this->title, other.title)<0 && this->numberOfPages<other.numberOfPages && this->year<other.year
		&& *(this->author)<*(other.author) && this->genre<other.genre && this->price < other.price;
}

bool Book::operator<=(const Book&other)const
{
	return((this<&other) || (this == &other));
}
bool Book::operator>(const Book&other)const
{
	return(!(this <= &other));
}
bool Book::operator>=(const Book&other)const
{
	return ((this>&other) || (this == &other));
}

std::ostream& operator<<(std::ostream&os, const Book&output)
{
	os << output.title << "\n" << output.numberOfPages << "\n" << output.year << "\n" << *(output.author) << "\n";

	switch (output.genre)
	{
	case NotSpecified:os << "NotSpecified" << "\n";
		break;
	case Drama:os << "Drama" << "\n";
		break;
	case Comedy:os << "Comedy" << "\n";
		break;
	case Lyric:os << "Lyric" << "\n";
		break;
	case Thriller:os << "Thriller" << "\n";
		break;
	case Fantasy:os << "Fantasy" << "\n";
	default:
		break;
	}
	os << output.price;
	return os;
}
std::istream& operator>>(std::istream&is, Book&input)
{
	char bookTitle[20];
	char bookGenre[15];
	cout << "Enter Book Title:" << endl;
	std::cin.getline(bookTitle, 20);
	input.setTitle(bookTitle);
	cout << "Enter Number of Pages and year:" << endl;
	is >> input.numberOfPages >> input.year;
	
	cout << "Enter Genre:" << endl;
	std::cin.getline(bookGenre, 15);
	if (strcmp(bookGenre, "Not Specified") == 0)input.setGenre(NotSpecified);
	if (strcmp(bookGenre, "Drama") == 0)input.setGenre(Drama);
	if (strcmp(bookGenre, "Comedy") == 0)input.setGenre(Comedy);
	if (strcmp(bookGenre, "Lyric") == 0)input.setGenre(Lyric);
	if (strcmp(bookGenre, "Thriller") == 0)input.setGenre(Thriller);
	if (strcmp(bookGenre, "Fantasy") == 0)input.setGenre(Fantasy);
	is >> input.price;
	input.author = NULL;
	return is;
}

void Book::print()const
{
	std::cout << "Title: " << this->title << std::endl;
	std::cout << "Pages: " << this->numberOfPages << std::endl;
	std::cout << "Year: " << this->year << std::endl;
	std::cout << "Price: " << this->price << std::endl;
	switch (this->genre)
	{
	case 0: std::cout << "Genre: Drama" << std::endl;
	case 1:	std::cout << "Genre: Comedy" << std::endl;
	case 2:	std::cout << "Genre: Lyric" << std::endl;
	case 3:	std::cout << "Genre: Thriller" << std::endl;
	case 4:std::cout << "Genre: Fantasy" << std::endl;
	}
	std::cout << "Information about the Author: " << std::endl;
	author->print();
	std::cout << std::endl;
}