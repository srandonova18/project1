#include "StructuresAndEnum.h"
#include <iostream>
using namespace std;

//CRUD

//function which finds a particular visitor by a specific id 
int findVisitorById(VISITOR* visitors, int& visitorCount, int id) {

	for (int i = 0; i < visitorCount; i++) {

		//if statement that finds the visitor with the same id as the one entered
		if (visitors[i].id == id) {

			return i;
		}
	}

	//if the id entered isn't found in the array of visitors
	return -1;
}

//function which finds a particular visitor
VISITOR findVisitor(VISITOR* visitors, int& visitorCount, int id) {

	//calling the function for finding a visitor by entered ID
	int index = findVisitorById(visitors, visitorCount, id);
	return visitors[index];
}

//function for adding new visitors in the system
void newVisitor(VISITOR* visitors, int& visitorCount, VISITOR newVisitor, int& maxId) {

	//visitor's id assigns to the maximum id
	newVisitor.id = maxId;
	visitors[visitorCount] = newVisitor;
	//increasing the value for visitorCount and maxId with 1
	visitorCount++;
	maxId++;
}

//function which gives you the option to edit a particular visitor
void editVisitor(VISITOR* visitors, VISITOR newVisitor, int& visitorsCount, int& maxId) {

	//calling the function for finding a visitor by entered ID
	int index = findVisitorById(visitors, visitorsCount, maxId);
	visitors[index] = newVisitor;
}

//filter functions

//function for getting the books written by a specific author
int getBorrowedBooksByAuthor(VISITOR* visitors, int visitorCount, BOOK* results, string authorName) {

	int index = 0;

	for (int i = 0; i < visitorCount; i++) {

		for (int j = 0; j < visitors[i].numberOfBooks; j++) {

			if (visitors[i].books[j].authorName == authorName) {

				//adding the matches to a result array (if there are any)
				results[index++] = visitors[i].books[j];
			}
		}
	}

	return index;
}

//function for getting the books with a specific title
int getBorrowedBooksByTitle(VISITOR* visitors, int visitorCount, BOOK* result, string title) {

	int index = 0;

	for (int i = 0; i < visitorCount; i++) {

		for (int j = 0; j < visitors[i].numberOfBooks; j++) {

			if (visitors[i].books[j].title == title) {

				//adding the matches to a result array (if there are any)
				result[index++] = visitors[i].books[j];
			}
		}
	}

	return index;
}

//function for getting the books with a specific year of release
int getBorrowedBooksByYearOfRelease(VISITOR* visitors, int visitorCount, BOOK* result, short int yearOfRelease) {

	int index = 0;

	for (int i = 0; i < visitorCount; i++) {

		for (int j = 0; j < visitors[i].numberOfBooks; j++) {

			if (visitors[i].books[j].yearOfRelease == yearOfRelease) {

				//adding the matches to a result array (if there are any)
				result[index++] = visitors[i].books[j];
			}
		}
	}

	return index;
}

//function that "deletes" a particular visitor by pushing them away
void deleteVisitor(VISITOR* visitors, int& visitorCount, int id) {

	//the function about finding visitor assigns the index
	int index = findVisitorById(visitors, visitorCount, id);

	for (int i = index; i < visitorCount - 1; i++) {

		//visitor's index icreases with 1
		visitors[i] = visitors[i + 1];
	}

	//the last index is delested by decreasing the counter
	visitorCount--;
}

//function that gives you information about the number of visitors per day of the week
int getNumberOfVisitorsPerDay(VISITOR* visitors, int visitorCount, WEEK_DAYS dayOfTheWeek) {

	int howManyVisitors = 0;

	for (int i = 0; i < visitorCount; i++) {

		//condition that finds all visitors with the same day of visit as the one entered
		if (visitors[i].dayOfTheWeek == dayOfTheWeek) {

			//incresing the counter
			howManyVisitors++;
		}
	}

	return howManyVisitors;

}

//function that gives you information about the number of borrowed books per day
int getNumberOfBooksBorrowedPerDay(VISITOR* visitors, int visitorCount, WEEK_DAYS dayOfTheWeek) {

	int howManyBooks = 0;

	for (int i = 0; i < visitorCount; i++) {

		///condition that finds all visitors with the same day of visit as the one entered
		if (visitors[i].dayOfTheWeek == dayOfTheWeek) {

			//sums alll values from the numberOfBooks fields
			howManyBooks = howManyBooks + visitors[i].numberOfBooks;
		}
	}

	return howManyBooks;
}

//function that gives you information about the average age of the visitors for the week
int getAverageOfVisitorsAgesForTheWeek(VISITOR* visitors, int visitorCount) {

	short int ages = 0;

	for (int i = 0; i < visitorCount; i++) {

		//sums all the values form the age fields
		ages = ages + visitors[i].age;
	}

	//divides the sum by the number of visitors
	ages = ages / visitorCount;

	return ages;
}

//function that checks if the value entered is an integer
int readInt(string message) {

	int number;

	//while loop until the value entered is an integer
	while (!(cin >> number)) {

		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << endl;
		cout << "There seems to be a problem with your input. " << endl;
		cout << "Please keep in mind that you should enter a number." << endl;
		cout << endl;
		//shows different messages depending on the function it is used in
		cout << message;
	}

	return number;
}

//function for initializing already entered data
void initializingData(VISITOR* visitors, int& visitorCount, int& maxId) {

	//adds new visitors to the main array with the newVisitor() function

	newVisitor(visitors, visitorCount, { "Mark", "Jones", 23, WEEK_DAYS::SAT, 1,
		{"The Silent Patient", "Alex Michaelides", 2019} }, maxId);

	newVisitor(visitors, visitorCount, { "Miles", "Pace", 45, WEEK_DAYS::MON, 2,
		{{"A Heartbreaking Work of Staggering Genius", "Dave Eggers", 2000},
		{"Watership Down", "Richard Adams", 1972}} }, maxId);

	newVisitor(visitors, visitorCount, { "Jessica", "Smith", 16, WEEK_DAYS::FRI, 1,
		{"The Fault in Our Stars", "John Green", 2012} }, maxId);

	newVisitor(visitors, visitorCount, { "Jay", "Horton", 47, WEEK_DAYS::SUN, 3,
		{{"The Stand", "Sthephen King", 1978},
		{"Confession of a Buddhist Atheist", "Stephen Batchelor", 2010},
		{"Of Mice and Men", "John Steinbeck", 1937}} }, maxId);

	newVisitor(visitors, visitorCount, { "Rebecca", "Pugh", 30, WEEK_DAYS::TUE, 1,
		{"The Book Thief", "Markus Zusak ", 2005} }, maxId);

	newVisitor(visitors, visitorCount, { "Lissette", "Fite", 52, WEEK_DAYS::FRI, 2,
		{{"Memoirs of a Geisha", "Arthur Golden", 1997},
		{"Lord of the Flies", "William Golding", 1954}} }, maxId);

	newVisitor(visitors, visitorCount, { "John", "Deer", 50, WEEK_DAYS::SUN, 1,
		{"Crime and Punishment", " Fyodor Dostoyevsky", 1886} }, maxId);

	newVisitor(visitors, visitorCount, { "Jessica", "Rose", 18, WEEK_DAYS::WED, 1,
		{"The Perks of Being a Wallflower", "Stephen Chbosky", 1999} }, maxId);

	newVisitor(visitors, visitorCount, { "Ken", "Raynolds", 12, WEEK_DAYS::TUE, 4,
		{{"Harry Potter and the Sorcerer's Stone", " J.K. Rowling", 1999},
		{"Harry Potter and the Prisoner of Azkaban", "J.K. Rowling", 1999},
		{"Harry Potter and the Order of the Phoenix", "J.K. Rowling", 2003},
		{"Fantastic Beasts and Where to Find Them", "J.K. Rowling", 2001}} }, maxId);

	newVisitor(visitors, visitorCount, { "Clara", "Graham", 15, WEEK_DAYS::MON, 1,
		{"The Lovely Bones", " Alice Sebold", 2002} }, maxId);

	newVisitor(visitors, visitorCount, { "Jose", "Boardman", 13, WEEK_DAYS::SAT, 2,
		{{"The Blood of Olympus", "Rick Riordan", 2014},
		{"The Little Prince", "Antoine de Saint-Exupery", 1943}} }, maxId);

}