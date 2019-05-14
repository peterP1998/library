#include "Author.h"
#include "Book.h"
#include "Set.h"
#include<iostream>
using namespace std;
int main()
{
	Author Jkr("","7567",8);
	Author *m = &Jkr;
    BookContainer arr(1);
	Author brown("brown", "en", 12);
	Author *k = &brown;
	Book harryPotter("7", 780, 2007, m, Drama, 4);
	Book inferno("31", 10, 20, m, Comedy, 15);
	Book inferno1("31", 2, 30, m, Comedy, 135);
	Book origin("Origin", 500, 360, k, Drama, 12);
	arr.insert(harryPotter);
	arr.insert(inferno);
	arr.insert(inferno1);
	arr.insert(origin);
    arr.remove(inferno);

	system("pause");
	return 0;
}

