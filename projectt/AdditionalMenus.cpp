#include <iostream>
#include "StructuresAndEnum.h"
#include "Data.h"
using namespace std;

//PRESENTATION LAYER (PART 2)

//menu for choosing a day of the week when needed
WEEK_DAYS chooseDayOfTheWeek() {

	short int day;
	string message;

	cout << endl;
	cout << "Choose the day of the visit:" << endl;
	cout << endl;
	cout << "0. Monday" << endl;
	cout << "1. Tuesday" << endl;
	cout << "2. Wednesday" << endl;
	cout << "3. Thursday" << endl;
	cout << "4. Friday" << endl;
	cout << "5. Saturday" << endl;
	cout << "6. Sunday" << endl;
	cout << endl;

	message = "Your choice: ";
	cout << message;
	//checks if the input is acceptable
	day = readInt(message);

	while (day < 0 or day > 6) {

		cout << "There seems to be a problem with your input. ";
		cout << "Please try again." << endl;
		cout << endl;
		cout << message;
		day = readInt(message);
	}

	//returns the selected option
	switch (day) {

		case 0:
			return WEEK_DAYS::MON;
			break;

		case 1:
			return WEEK_DAYS::TUE;
			break;

		case 2:
			return WEEK_DAYS::WED;
			break;

		case 3:
			return WEEK_DAYS::THU;
			break;

		case 4:
			return WEEK_DAYS::FRI;
			break;

		case 5:
			return WEEK_DAYS::SAT;
			break;

		case 6:
			return WEEK_DAYS::SUN;
			break;

		default:
			//if there isn't a correct option chosen
			return WEEK_DAYS::UNKNOWN;
			break;
	}

}

//function that transforms enum to words providing the days of the week
string weekDayToString(WEEK_DAYS weekDay) {

	switch (weekDay) {

		//returns a string with the day name
		case WEEK_DAYS::MON:
			return "Monday";
			break;

		case WEEK_DAYS::TUE:
			return "Tuesday";
			break;

		case WEEK_DAYS::WED:
			return "Wednesday";
			break;

		case WEEK_DAYS::THU:
			return "Thursday";
			break;

		case WEEK_DAYS::FRI:
			return "Friday";
			break;

		case WEEK_DAYS::SAT:
			return "Saturday";
			break;

		case WEEK_DAYS::SUN:
			return "Sunday";
			break;

			//if there is an error
		case WEEK_DAYS::UNKNOWN:
			return "There seems to be an error.";
			break;

		default:
			break;
	}

	return " ";

}

//function for editing the borrowed book's details
void editBooksDetailsMenu(VISITOR* visitors, int& visitorCount) {

	int visitorId, bookIndex;
	short int bookDetail;
	string message;

	message = "Enter visitor's ID: ";
	cout << message;

	//checks if the input is acceptable
	visitorId = readInt(message);

	while (visitorId < 1 or visitorId > visitorCount) {

		cout << endl;
		cout << "There seems to be a problem with your input. ";
		cout << "Please try again." << endl;
		cout << endl;
		cout << message;
		visitorId = readInt(message);
	}

	VISITOR visitor = findVisitor(visitors, visitorCount, visitorId);

	//menu for choosing a book
	cout << endl;
	cout << "Which book's detail would you like to edit? " << endl;
	cout << endl;

	for (int i = 0; i < visitor.numberOfBooks; i++) {

		cout << i + 1 << ".\"" << visitor.books[i].title << "\" by ";
		cout << visitor.books[i].authorName << " released in " << visitor.books[i].yearOfRelease << endl;
	}

	cout << endl;
	message = "Your choice: ";
	cout << message;

	//checks if the input is acceptable
	bookIndex = readInt(message);

	while (bookIndex < 0 or bookIndex > visitor.numberOfBooks) {

		cout << endl;
		cout << "There seems to be a problem with your input. ";
		cout << "Please try again." << endl;
		cout << endl;
		cout << message;
		bookIndex = readInt(message);
	}
	bookIndex--;

	cout << endl;
	cout << "What would you like to edit?" << endl;
	cout << endl;
	cout << "1. Title" << endl;
	cout << "2. Author" << endl;
	cout << "3. Year of release" << endl;
	cout << endl;
	cout << message;

	 //checks if the input is acceptable
	bookDetail = readInt(message);

	while (bookDetail < 1 or bookDetail > 3) {

		cout << "There seems to be a problem with your input. ";
		cout << "Remember that your only options are either 1, 2 or 3." << endl;
		cout << "Please try again." << endl;
		cout << endl;
		cout << message;
		bookDetail = readInt(message);
	}
	cout << endl;

	cin.ignore();

	switch (bookDetail) {

		case 1:
			cout << "Title: ";
			getline(cin, visitor.books[bookIndex].title);
			editVisitor(visitors, visitor, visitorCount, visitorId);
			break;

		case 2:
			cout << "Author: ";
			getline(cin, visitor.books[bookIndex].authorName);
			editVisitor(visitors, visitor, visitorCount, visitorId);
			break;

		case 3:
			message = "Year of release: ";
			cout << message;

			//checks if the input is acceptable
			visitor.books[bookIndex].yearOfRelease = readInt(message);

			while (visitor.books[bookIndex].yearOfRelease < 1455 or visitor.books[bookIndex].yearOfRelease > 2020) {

				cout << "There seems to be something wrong with your input. Please try again." << endl;
				cout << endl;
				cout << message;
				visitor.books[bookIndex].yearOfRelease = readInt(message);
			}

			editVisitor(visitors, visitor, visitorCount, visitorId);
			break;

		default:
			cout << "There seems to be a problem with your input. Please try again later." << endl;
			break;
	}

}

//function for editing the visitor's profile
void editVisitorDetailsMenu(VISITOR* visitors, int& visitorCount) {

	string message;
	int visitorId, edit;

	message = "Enter visitor's ID: ";
	cout << message;

	//checks if the input is acceptable
	visitorId = readInt(message);

	while (visitorId < 1 or visitorId > visitorCount) {

		cout << "There seems to be a problem with your input. ";
		cout << "Please try again." << endl;
		cout << endl;
		cout << message;
		visitorId = readInt(message);
	}

	//getiing the visitor's profile
	VISITOR visitor = findVisitor(visitors, visitorCount, visitorId);

	cout << endl;
	cout << "What would you like to edit?" << endl;
	cout << endl;
	cout << "1. First name" << endl;
	cout << "2. Last name" << endl;
	cout << "3. Age" << endl;
	cout << "4. Day of visit" << endl;
	cout << endl;

	message = "Your choice: ";
	cout << message;

	//checks if the input is acceptable
	edit = readInt(message);

	while (edit < 0 or edit > 4) {

		cout << endl;
		cout << "There seems to be a problem with your input. " << endl;
		cout << "Remember that the options you can enter are the numbers from 1 to 4 (included)." << endl;
		cout << "Please try again." << endl;
		cout << endl;
		cout << message;
		edit = readInt(message);
	}
	cout << endl;

	cin.ignore();

	switch (edit) {

		case 1:
			cout << "First name: ";
			getline(cin, visitor.firstName);
			editVisitor(visitors, visitor, visitorCount, visitorId);
			break;

		case 2:
			cout << "Last name: ";
			getline(cin, visitor.lastName);
			editVisitor(visitors, visitor, visitorCount, visitorId);
			break;

		case 3:
			message = "Age: ";
			cout << message;
			//checks if the input is acceptable
			visitor.age = readInt(message);

			while (visitor.age < 10 or visitor.age > 117) {

				cout << endl;
				cout << "There seems to be a problem with your input. " << endl;
				cout << "Please notice that the visitor should be at least 10 years old." << endl;
				cout << endl;
				cout << "Age: ";
				visitor.age = readInt(message);
			}

			editVisitor(visitors, visitor, visitorCount, visitorId);
			break;

		case 4:
			visitor.dayOfTheWeek = chooseDayOfTheWeek();

			//checks if the input is acceptable
			while (visitor.dayOfTheWeek == WEEK_DAYS::UNKNOWN) {

				cout << endl;
				cout << "There seems to be a problem with your input. ";
				cout << "Please enter the number of a valid day of the week from the list." << endl;
				visitor.dayOfTheWeek = chooseDayOfTheWeek();
			}
			editVisitor(visitors, visitor, visitorCount, visitorId);
			break;

		default:
			cout << "There seems to be a problem with your input. Please try again later." << endl;
			break;
	}
}

//filter functions

//function which shows all books with the same title as entered
void getBorrowedBooksByTitleMenu(VISITOR* visitors, int& visitorCount) {

	cin.ignore();
	string title;
	BOOK results[30];
	int bookNumber = 1;

	cout << "Enter title: ";
	getline(cin, title);

	//calling the function for finding the wanted books 
	int resultsSize = getBorrowedBooksByTitle(visitors, visitorCount, results, title);

	//shows the wanted books 
	if (resultsSize == 0) {

		cout << endl;
		cout << "There are none results that match your search." << endl;
		cout << endl;
	} else {

		for (int i = 0; i < resultsSize; i++) {

			cout << bookNumber << ". \"" << results[i].title << "\" by ";
			cout << results[i].authorName << " released in " << results[i].yearOfRelease << endl;
			bookNumber++;
		}
	}
	
}

//function which shows all books with the same author as entered
void getBorrowedBooksByAuthorMenu(VISITOR* visitors, int& visitorCount) {

	cin.ignore();
	BOOK results[30];
	string authorName;
	int bookNumber = 1;

	cout << "Enter author name: ";
	getline(cin, authorName);

	//calling the function for finding the wanted books 
	int resultsSize = getBorrowedBooksByAuthor(visitors, visitorCount, results, authorName);

	//shows the wanted books
	if (resultsSize == 0) {

		cout << endl;
		cout << "There are none results that match your search." << endl;
		cout << endl;
	} else {

		for (int i = 0; i < resultsSize; i++) {

			cout << bookNumber << ". \"" << results[i].title << "\" by ";
			cout << results[i].authorName << " released in " << results[i].yearOfRelease << endl;
			bookNumber++;
		}

	}
}

//function which shows all books with the same year of release as entered
void getBorrowedBooksByYearOfReleaseMenu(VISITOR* visitors, int& visitorCount) {

	BOOK results[30];
	int year, bookNumber = 1;

	cout << "Enter year of release: ";
	cin >> year;

	//calling the function for finding the wanted books 
	int resultsSize = getBorrowedBooksByYearOfRelease(visitors, visitorCount, results, year);

	//shows the wanted books
	if (resultsSize == 0) {

		cout << endl;
		cout << "There are none results that match your search." << endl;
		cout << endl;
	} else {

		for (int i = 0; i < resultsSize; i++) {

			cout << bookNumber << ". \"" << results[i].title << "\" by ";
			cout << results[i].authorName << " released in " << results[i].yearOfRelease << endl;
			bookNumber++;
		}

	}
}

//function that reports the number of visitors per day for the week
void numberOfVisitorsPerDayReportsMenu(VISITOR* visitors, int& visitorCount) {

	//calling the function for choosing a day
	WEEK_DAYS day = chooseDayOfTheWeek();
	cout << endl;
	//calling the function for converting enum to string
	cout << "The total number of visitors for " << weekDayToString(day) << " is: ";
	//calling the function for getting the number
	cout << getNumberOfVisitorsPerDay(visitors, visitorCount, day) << endl;
}

//function that shows the borrowed books per day of the week
void numberOfBooksPerDayReportsMenu(VISITOR* visitors, int& visitorCount) {

	//calling the function for choosing a day
	WEEK_DAYS day = chooseDayOfTheWeek();
	cout << endl;
	//calling the function for converting enum to string
	cout << "The total number of borrowed books for " << weekDayToString(day) << " is: ";
	//calling the function for getting the number
	cout << getNumberOfBooksBorrowedPerDay(visitors, visitorCount, day) << endl;
}