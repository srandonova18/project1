#include <iostream>
#include "StructuresAndEnum.h"
#include "Data.h"
#include "AdditionalMenus.h"

using namespace std;

//PRESENTATION LAYER (PART 1)

//function that adds new visitor
void newVisitorMenu(VISITOR* visitors, int& visitorCount, int& maxId) {

	VISITOR visitor;
	string message;

	cin.ignore();

	//entering values for the struct fields
	cout << "First name: ";
	getline(cin, visitor.firstName);

	cout << "Last name: ";
	getline(cin, visitor.lastName);

	message = "Age: ";
	cout << message;
	//checks if the input is acceptable
	visitor.age = readInt(message);

	while (visitor.age < 10 or visitor.age > 117) {

		cout << "There seems to be a problem with your input. " << endl;
		cout << "Please notice that the visitor should be at least 10 years old. " << endl;
		cout << endl;
		cout << "Age: ";
		visitor.age = readInt(message);
	}

	visitor.dayOfTheWeek = chooseDayOfTheWeek();

	//if the input isn't acceptable
	while (visitor.dayOfTheWeek == WEEK_DAYS::UNKNOWN) {

		cout << "There seems to be a problem with your input. ";
		cout << "Please enter the number of a valid day of the week from the list." << endl;
		visitor.dayOfTheWeek = chooseDayOfTheWeek();
	}

	cout << endl;

	message = "How many books did they borrow?: ";
	cout << message;
	//checks if the input is acceptable
	visitor.numberOfBooks = readInt(message);

	while (visitor.numberOfBooks <= 0 or visitor.numberOfBooks > 7) {

		cout << "There seems to be a problem with your input. " << endl;
		cout << "Please notice that the minimum amount of books a visitor can borrow is 1 ";
		cout << "and the maximum amount is 7. " << endl;
		cout << endl;
		cout << message;
		visitor.numberOfBooks = readInt(message);
	}

	cout << endl;

	cout << ".::BOOKS::." << endl;

	cout << endl;

	cin.ignore();

	for (int i = 0; i < visitor.numberOfBooks; i++) {

		cout << "Title: ";
		getline(cin, visitor.books[i].title);

		cout << "Author: ";
		getline(cin, visitor.books[i].authorName);

		message = "Year of release: ";
		cout << message;
		//checks if the input is acceptable
		visitor.books[i].yearOfRelease = readInt(message);

		while (visitor.books[i].yearOfRelease < 1455 or visitor.books[i].yearOfRelease > 2020) {

			cout << "There seems to be something wrong with your input. Please try again." << endl;
			cout << endl;
			cout << message;
			visitor.books[i].yearOfRelease = readInt(message);
		}

		cin.ignore();

		cout << endl;
	}

	newVisitor(visitors, visitorCount, visitor, maxId);
}

//function that shows all visitors
void showVisitorsMenu(VISITOR* visitors, int& visitorCount, int& maxId) {

	cout << ".::All VISITORS::. " << endl;

	cout << endl;

	for (int i = 0; i < visitorCount; i++) {


		cout << i + 1 << ". " << visitors[i].firstName << " " << visitors[i].lastName << ", ";
		cout << visitors[i].age << " years old ";
		cout << "visited on " << weekDayToString(visitors[i].dayOfTheWeek) << endl;

		cout << endl;
		cout << ".::LIST OF BORROWED BOOKS::." << endl;
		cout << endl;

		for (int j = 0; j < visitors[i].numberOfBooks; j++) {

			cout << "\"" << visitors[i].books[j].title << "\" by " << visitors[i].books[j].authorName;
			cout << " released in " << visitors[i].books[j].yearOfRelease << endl;
		}

		cout << endl;
	}

}

//function for choosing what to be edited
void editVisitorMenu(VISITOR* visitors, int& visitorCount) {

	short int edit;
	string message;

	cout << "What would you like to edit?" << endl;
	cout << endl;
	cout << "1. Visitor's profile details" << endl;
	cout << "2. Visitor's borrowed books' details" << endl;
	cout << endl;

	message = "Your choice: ";
	cout << message;

	//checks if the input is acceptable
	edit = readInt(message);

	while (edit < 1 or edit > 2) {

		cout << endl;
		cout << "There seems to be a problem with your input. " << endl;
		cout << "Remember that your only options are either 1 or 2." << endl;
		cout << "Please try again." << endl;
		cout << endl;
		cout << message;
		edit = readInt(message);
	}
	cout << endl;

	switch (edit) {

		case 1:
			//calling the function for editing a visitor
			editVisitorDetailsMenu(visitors, visitorCount);
			break;

		case 2:
			//calling the function for editing a book
			editBooksDetailsMenu(visitors, visitorCount);
			break;

		default:
			cout << "There seems to be a problem with your input. Please try again later. " << endl;
			break;
	}

}

//function that shows all borrowed books
void showAllBorrowedBooksMenu(VISITOR* visitors, int& visitorCount) {

	int bookNumber = 1;

	cout << endl;
	cout << ".::LIST OF ALL BORROWED BOOKS::." << endl;
	cout << endl;

	for (int i = 0; i < visitorCount; i++) {

		for (int j = 0; j < visitors[i].numberOfBooks; j++) {

			cout << bookNumber << ". \"" << visitors[i].books[j].title << "\" by ";
			cout << visitors[i].books[j].authorName << " released in " << visitors[i].books[j].yearOfRelease << endl;
			bookNumber++;
		}
	}
}

//function for choosing a filter
void showBorrowedBooksByADetailMenu(VISITOR* visitors, int& visitorCount) {

	short int choice;
	string message;

	cout << "Choose a detail: " << endl;
	cout << endl;
	cout << "1. Show all borrowed books by title" << endl;
	cout << "2. Show all borrowed books by author" << endl;
	cout << "3. Show all borrowed books by year of release" << endl;
	cout << endl;
	message = "Your choice: ";
	cout << message;

	//checks if the input is acceptable
	choice = readInt(message);

	while (choice < 1 or choice > 3) {

		cout << endl;
		cout << "There seems to be a problem with your input. " << endl;
		cout << "Remember that your only options are either 1, 2 or 3." << endl;
		cout << "Please try again." << endl;
		cout << endl;
		cout << message;
		choice = readInt(message);
	}
	cout << endl;

	switch (choice) {

		case 1:
			//calling the function for showing books by title
			getBorrowedBooksByTitleMenu(visitors, visitorCount);
			break;

		case 2:
			//calling the function for showing books by author
			getBorrowedBooksByAuthorMenu(visitors, visitorCount);
			break;

		case 3:
			//calling the function for showing books by year of release
			getBorrowedBooksByYearOfReleaseMenu(visitors, visitorCount);
			break;

		default:
			cout << "There seems to be a problem with your input. Please try again later." << endl;
			break;
	}

}

//menu function for deleting a visitor's profile 
void deleteVisitorMenu(VISITOR* visitors, int& visitorCount, int& maxId) {

	int visitorId;
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

	//calling the CRUD function for deleting a visitor
	deleteVisitor(visitors, visitorCount, visitorId);
}

//menu function for choosing a wanted report
void showReportsMenu(VISITOR* visitors, int& visitorCount, int& maxId) {

	short int choice;
	string message;

	cout << "Choose a report: " << endl;
	cout << endl;
	cout << "1. Get number of visitors per day" << endl;
	cout << "2. Get number of books borrowed per day" << endl;
	cout << "3. Get average of visitors' ages for the whole week" << endl;
	cout << endl;
	message = "Your choice: ";
	cout << message;
	//checks if the input is acceptable
	choice = readInt(message);

	while (choice < 1 or choice > 3) {

		cout << endl;
		cout << "There seems to be a problem with your input. " << endl;
		cout << "Remember that your only options are either 1, 2 or 3." << endl;
		cout << "Please try again." << endl;
		cout << endl;
		cout << message;
		choice = readInt(message);
	}
	cout << endl;

	switch (choice) {

		case 1:
			//calling the function for getting the number of visitors per day of the week
			numberOfVisitorsPerDayReportsMenu(visitors, visitorCount);
			break;

		case 2:
			//calling the function for getting the number of borrowed books per day of the week
			numberOfBooksPerDayReportsMenu(visitors, visitorCount);
			break;

		case 3:
			//calling the function for getting the average number of all visitors' ages for the week
			cout << "The average of the visitors' ages for the week is: ";
			cout << getAverageOfVisitorsAgesForTheWeek(visitors, visitorCount) << endl;
			break;

		default:
			cout << "There seems to be a problem with your input. Please try again later." << endl;
			break;
	}

}

//main menu function for choosing what to do
bool showMainMenu(VISITOR* visitors, int& visitorCount, int& maxId) {

	int choice;
	string message;

	cout << endl;
	cout << "----------------" << endl;
	cout << "   MAIN MENU" << endl;
	cout << "----------------" << endl;
	cout << endl;
	cout << "1. Register a new visitor" << endl;
	cout << "2. Show all visitors' profiles" << endl;
	cout << "3. Show all books borrowed for the week" << endl;
	cout << "4. Edit an existing visitor's profile" << endl;
	cout << "5. Delete an existing visitor's profile" << endl;
	cout << "6. Find a borrowed book by a detail" << endl;
	cout << "7. Reports" << endl;
	cout << "8. Exit" << endl;
	cout << endl;
	message = "Your choice: ";
	cout << message;

	//checks if the input is acceptable
	choice = readInt(message);

	while (choice < 1 or choice > 8) {

		cout << endl;
		cout << "There seems to be a problem with your input. " << endl;
		cout << "Remember that your only options are the number between 1 and 8 (included)." << endl;
		cout << "Please try again." << endl;
		cout << endl;
		cout << message;
		choice = readInt(message);
	}
	cout << endl;

	switch (choice) {

		case 1:
			//calling the function for creating a new visitor
			newVisitorMenu(visitors, visitorCount, maxId);
			break;

		case 2:
			//calling the function for showing all visitors
			showVisitorsMenu(visitors, visitorCount, maxId);
			break;

		case 3:
			//calling the function for showing all borrowed books
			showAllBorrowedBooksMenu(visitors, visitorCount);
			break;

		case 4:
			//calling the function for editing details
			editVisitorMenu(visitors, visitorCount);
			break;

		case 5:
			//calling the function for deleting a visitor's profile
			deleteVisitorMenu(visitors, visitorCount, maxId);
			break;

		case 6:
			//calling the function for showing all borrowed books by a detail
			showBorrowedBooksByADetailMenu(visitors, visitorCount);
			break;

		case 7:
			//calling the menu function for choosing a report wanted
			showReportsMenu(visitors, visitorCount, maxId);
			break;

		case 8:
			//goodbye message
			cout << "Thank you for using our program. See you soon!" << endl;
			return false;

		default:
			//if there is an error
			cout << "There seems to be a problem with your input. Please try again later." << endl;
			break;

	}

	//for continuous showing of the menu unless exit is chosen
	return true;
}