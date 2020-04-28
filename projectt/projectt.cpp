#include <iostream>
#include <string>
using namespace std;
//the idea behind the code is a library

//structure with information about the books
struct BOOK {

	string title = "";
	string authorName = "";
	short int yearOfRelease = 0;
};

//declaring the enum with the days of the week
enum class WEEK_DAYS {

	UNKNOWN,
	MON,
	TUE,
	WED,
	THU,
	FRI,
	SAT,
	SUN
};

//structure with information about the visitors
struct VISITOR {

	string firstName = "";
	string lastName = "";
	short int age = 0;
	WEEK_DAYS dayOfTheWeek = WEEK_DAYS::MON;
	short int numberOfBooks = 0;
	BOOK books[7];
	int id = 0;
};

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

//function which finds a particular visitor by a specific year of release
int getBorrowedBooksByYearOfRelease(VISITOR* visitors, int visitorCount, BOOK* result, int resultCount, short int yearOfRelease)
{
	int index = 0;
	for (int i = 0; i < visitorCount; i++)
	{
		for (int j = 0; j < visitors[i].numberOfBooks; j++)
		{
			if (visitors[i].books[j].yearOfRelease == yearOfRelease)
			{
				result[index++] = visitors[i].books[j];
			}
		}
	}

	return index;
}


//function which finds a particular visitor
VISITOR findVisitor(VISITOR* visitors, int& visitorCount, int id) {

	int index = findVisitorById(visitors, visitorCount, id);
	return visitors[index];
}

//function for adding new visitors in the system
void newVisitor(VISITOR* visitors, int& visitorCount, VISITOR newVisitor, int& maxId) {
	//visitor's id assigns to the maximum id
	newVisitor.id = maxId;
	visitors[visitorCount] = newVisitor;
	visitorCount++;
	maxId++;
}

int getBorrowedBooksByTitle(VISITOR* visitors, int visitorCount, BOOK* result, int resultCount, string title)
{
	int index = 0;
	for (int i = 0; i < visitorCount; i++)
	{
		for (int j = 0; j < visitors[i].numberOfBooks; j++)
		{
			if (visitors[i].books[j].title == title)
			{
				result[index++] = visitors[i].books[j];
			}
		}
	}

	return index;
}

//function which gives you the option to edit a particular visitor
void editVisitor(VISITOR* visitors, VISITOR newVisitor, int& visitorsCount, int& maxId) {

	int index = findVisitorById(visitors, visitorsCount, maxId);
	visitors[index] = newVisitor;
}

//function that deletes a particular visitor by pushing him away
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

//function that gives you information about all the visitors per day
int getNumberOfVisitorsPerDay(VISITOR* visitors, int visitorCount, WEEK_DAYS dayOfTheWeek) {

	//giving value of variable that shows how many visitors the library had 
	int howManyVisitors = 0;

	for (int i = 0; i < visitorCount; i++) {

		//condition that checks if the day that the user has given is declarte in the structure WEEK_DAYS
		if (visitors[i].dayOfTheWeek == dayOfTheWeek) {

			//incresing the variable
			howManyVisitors++;
		}
	}

	return howManyVisitors;

}

int getBorrowedBooksByAuthor(VISITOR* visitors, int visitorCount, BOOK* results, int resultCount, string authorName)
{
	int index = 0;
	for (int i = 0; i < visitorCount; i++)
	{
		for (int j = 0; j < visitors[i].numberOfBooks; j++)
		{
			if (visitors[i].books[j].authorName == authorName)
			{
				results[index++] = visitors[i].books[j];
			}
		}
	}

	return index;
}


//function that gives you information about all the books that are borrowed per day
int getNumberOfBooksBorrowedPerDay(VISITOR* visitors, int visitorCount, WEEK_DAYS dayOfTheWeek) {

	//giving value of variable that shows how many books are boworred of the library 
	int howManyBooks = 0;

	for (int i = 0; i < visitorCount; i++) {

		//condition that checks if the day that the user has given is declarte in the structure WEEK_DAYS
		if (visitors[i].dayOfTheWeek == dayOfTheWeek) {

			howManyBooks = howManyBooks + visitors[i].numberOfBooks;
		}
	}

	return howManyBooks;
}

//function that gives you information about the average age of the visitor for a week
int getAverageOfVisitorsAgesForTheWeek(VISITOR* visitors, int visitorCount) {

	//giving value of variable for the age
	short int ages = 0;

	for (int i = 0; i < visitorCount; i++) {

		ages = ages + visitors[i].age;
	}

	ages = ages / visitorCount;

	return ages;
}

int readInt(string message) {

	int number;

	while (!(cin >> number)) {

		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << endl;
		cout << "There seems to be a problem with your input. " << endl;
		cout << "Please keep in mind that you should enter a number." << endl;
		cout << endl;
		cout << message;
	}

	return number;
}

void initializingData(VISITOR* visitors, int& visitorCount, int& maxId) {

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

//PRESENTATION LAYER

WEEK_DAYS chooseDayOfTheWeek() {

	short int day;

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
	cout << "Your choice: ";

	cin >> day;

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
		return WEEK_DAYS::UNKNOWN;
		break;
	}

}

//function that helps the enum to transform in words providing the days of the week
string weekDayToString(WEEK_DAYS weekDay) {

	switch (weekDay) {

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

	default:
		break;
	}

	return " ";

}
//function that add new visitor
void newVisitorMenu(VISITOR* visitors, int& visitorCount, int& maxId) {

	VISITOR visitor;
	string message;

	cin.ignore();

	cout << "First name: ";
	getline(cin, visitor.firstName);

	cout << "Last name: ";
	getline(cin, visitor.lastName);

	cout << "Age: ";
	cin >> visitor.age;
	message = "Age: ";
	visitor.age = readInt(message);
	while (visitor.age < 10 or visitor.age > 117) {

		cout << "There seems to be a problem with your input. " << endl;
		cout << "Please notice that the visitor should be at least 10 years old. " << endl;
		cout << endl;
		cout << "Age: ";
		cin >> visitor.age;
	}

	visitor.dayOfTheWeek = chooseDayOfTheWeek();
	while (visitor.dayOfTheWeek == WEEK_DAYS::UNKNOWN) {

		cout << "There seems to be a problem with your input. ";
		cout << "Please enter the number of a valid day of the week from the list." << endl;
		visitor.dayOfTheWeek = chooseDayOfTheWeek();
	}

	cout << endl;
	cout << "How many books did they borrow? : ";
	cin >> visitor.numberOfBooks;
	message = "How many books did they borrow? : ";
	visitor.numberOfBooks = readInt(message);
	while (visitor.numberOfBooks < 1 or visitor.numberOfBooks > 7) {

		cout << "There seems to be a problem with your input. " << endl;
		cout << "Please notice that the minimum amount of books a visitor can borrow is 1 ";
		cout << "and the maximum amount is 7. " << endl;
		cout << endl;
		cout << "How many books did they borrow? : ";
		cin >> visitor.numberOfBooks;
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

		cout << "Year of release: ";
		cin >> visitor.books[i].yearOfRelease;
		message = "Year of release: ";
		visitor.books[i].yearOfRelease = readInt(message);
		while (visitor.books[i].yearOfRelease < 1455 or visitor.books[i].yearOfRelease > 2020) {

			cout << "There seems to be something wrong with your input. Please try again." << endl;
			cout << endl;
			cout << "Year of release: ";
			cin >> visitor.books[i].yearOfRelease;
		}

		cin.ignore();

		cout << endl;
	}

	newVisitor(visitors, visitorCount, visitor, maxId);
}
//function that show us all visitors
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
//function that edit the visitor's ID
void editVisitorDetailsMenu(VISITOR* visitors, int& visitorCount) {

	string message;
	int visitorId, edit;

	cout << "Enter visitor's ID: ";
	cin >> visitorId;

	VISITOR visitor = findVisitor(visitors, visitorCount, visitorId);

	cout << endl;
	cout << "What would you want to edit?" << endl;
	cout << endl;
	cout << "1. First name" << endl;
	cout << "2. Last name" << endl;
	cout << "3. Age" << endl;
	cout << "4. Day of visit" << endl;
	cout << endl;
	cout << "Your choice: ";

	cin >> edit;
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
		cout << "Age: ";
		cin >> visitor.age;
		message = "Age: ";
		visitor.age = readInt(message);
		while (visitor.age < 10 or visitor.age > 117) {

			cout << "There seems to be a problem with your input. " << endl;
			cout << "Please notice that the visitor should be at least 10 years old." << endl;
			cout << endl;
			cout << "Age: ";
			cin >> visitor.age;
		}

		editVisitor(visitors, visitor, visitorCount, visitorId);
		break;

	case 4:
		visitor.dayOfTheWeek = chooseDayOfTheWeek();
		while (visitor.dayOfTheWeek == WEEK_DAYS::UNKNOWN) {

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
// function that show us all the books who were borrowed
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

//function that edit book details to the visitor
void editBooksDetailsMenu(VISITOR* visitors, int& visitorCount) {

	int visitorId, bookIndex;
	short int bookDetail;
	string message;

	cout << "Enter visitor's ID: ";
	cin >> visitorId;

	VISITOR visitor = findVisitor(visitors, visitorCount, visitorId);

	cout << endl;
	cout << "Which book's detail would you want to edit? " << endl;
	cout << endl;

	for (int i = 0; i < visitor.numberOfBooks; i++) {

		cout << i + 1 << ".\"" << visitor.books[i].title << "\" by ";
		cout << visitor.books[i].authorName << " released in " << visitor.books[i].yearOfRelease << endl;
	}

	cout << "Your choice: ";
	cin >> bookIndex;
	bookIndex--;

	cout << "What would you want to edit?" << endl;
	cout << endl;
	cout << "1. Title" << endl;
	cout << "2. Author" << endl;
	cout << "3. Year of release" << endl;
	cout << endl;
	cout << "Your choice: ";

	cin >> bookDetail;

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
		cout << "Year of release: ";
		cin >> visitor.books[bookIndex].yearOfRelease;
		message = "Year of release: ";
		visitor.books[bookIndex].yearOfRelease = readInt(message);
		while (visitor.books[bookIndex].yearOfRelease < 1455 or visitor.books[bookIndex].yearOfRelease > 2020) {

			cout << "There seems to be something wrong with your input. Please try again." << endl;
			cout << endl;
			cout << "Year of release: ";
			cin >> visitor.books[bookIndex].yearOfRelease;
		}


		editVisitor(visitors, visitor, visitorCount, visitorId);
		break;

	default:
		cout << "There seems to be a problem with your input. Please try again later." << endl;
		break;
	}

}
//function that edit all the visitor's data.
void editVisitorMenu(VISITOR* visitors, int& visitorCount) {

	short int edit;

	cout << "What would you want to edit?" << endl;
	cout << endl;
	cout << "1. Visitor's profile details" << endl;
	cout << "2. Visitor's borrowed books' details" << endl;
	cout << endl;
	cout << "Your choice is: ";

	cin >> edit;
	cout << endl;

	switch (edit) {

	case 1:
		editVisitorDetailsMenu(visitors, visitorCount);
		break;

	case 2:
		editBooksDetailsMenu(visitors, visitorCount);
		break;

	default:
		cout << "There seems to be a problem with your input. Please try again later. " << endl;
		break;
	}

}

//function deleting by id
void deleteVisitorMenu(VISITOR* visitors, int& visitorCount, int& maxId) {

	int visitorId;

	cout << "Enter visitor ID: ";
	cin >> visitorId;

	deleteVisitor(visitors, visitorCount, visitorId);
}

//function that reports the visitors per day
void numberOfVisitorsPerDayReportsMenu(VISITOR* visitors, int& visitorCount) {

	WEEK_DAYS day = chooseDayOfTheWeek();
	cout << endl;
	cout << "The total number of visitors for " << weekDayToString(day) << " is: ";
	cout << getNumberOfVisitorsPerDay(visitors, visitorCount, day) << endl;
}
//function that show the borrowed books per day
void numberOfBooksPerDayReportsMenu(VISITOR* visitors, int& visitorCount) {

	WEEK_DAYS day = chooseDayOfTheWeek();
	cout << endl;
	cout << "The total number of borrowed books for " << weekDayToString(day) << " is: ";
	cout << getNumberOfBooksBorrowedPerDay(visitors, visitorCount, day) << endl;
}

void getBorrowedBooksByTitleMenu(VISITOR* visitors, int& visitorCount) {



}

void getBorrowedBooksByAuthorMenu(VISITOR* visitors, int& visitorCount) {



}

void getBorrowedBooksByYearOfReleaseMenu(VISITOR* visitors, int& visitorCount) {



}


void showBorrowedBooksByADetailMenu(VISITOR* visitors, int& visitorCount, int& maxId) {

	short int choice;

	cout << "Choose a detail: " << endl;
	cout << endl; 
	cout << "1. Show all borrowed books by title" << endl;
	cout << "2. Show all borrowed books by author" << endl;
	cout << "3. Show all borrowed books by year" << endl;
	cout << endl;
	cout << "Your choice: ";

	cin >> choice;

	cout << endl;

	switch (choice) {

	case 1:
		getBorrowedBooksByTitleMenu(visitors, visitorCount);
		break;

	case 2:
		getBorrowedBooksByAuthorMenu(visitors, visitorCount);
		break;

	case 3:
		getBorrowedBooksByYearOfReleaseMenu(visitors, visitorCount);
		break;

	default:
		cout << "There seems to be a problem with your input. Please try again later." << endl;
		break;
	}

}



void showReportsMenu(VISITOR* visitors, int& visitorCount, int& maxId) {

	short int choice;

	cout << "Choose a report: " << endl;
	cout << endl;
	cout << "1. Get number of visitors per day" << endl;
	cout << "2. Get number of books borrowed per day" << endl;
	cout << "3. Get average of visitors' ages for the whole week" << endl;
	cout << endl;
	cout << "Your choice: ";

	cin >> choice;

	cout << endl;

	switch (choice) {

	case 1:
		numberOfVisitorsPerDayReportsMenu(visitors, visitorCount);
		break;

	case 2:
		numberOfBooksPerDayReportsMenu(visitors, visitorCount);
		break;

	case 3:
		cout << "The average of the visitors' ages for the week is: ";
		cout << getAverageOfVisitorsAgesForTheWeek(visitors, visitorCount) << endl;
		break;

	default:
		cout << "There seems to be a problem with your input. Please try again later." << endl;
		break;
	}

}
//function where  you can choose what do you want to see
bool showMainMenu(VISITOR* visitors, int& visitorCount, int& maxId) {

	int choice;

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
	cout << "6.Find a borrowed book by a detail" << endl;
	cout << "7. Reports" << endl;
	cout << "8. Exit" << endl;
	cout << endl;
	cout << "Your choice is: ";

	cin >> choice;

	cout << endl;

	switch (choice) {

	case 1:
		newVisitorMenu(visitors, visitorCount, maxId);
		break;

	case 2:
		showVisitorsMenu(visitors, visitorCount, maxId);
		break;

	case 3:
		showAllBorrowedBooksMenu(visitors, visitorCount);
		break;

	case 4:
		editVisitorMenu(visitors, visitorCount);
		break;

	case 5:
		deleteVisitorMenu(visitors, visitorCount, maxId);
		break;

	case 6:
		showBorrowedBooksByADetailMenu(visitors, visitorCount,maxId);
		break;

	case 7:
		showReportsMenu(visitors, visitorCount, maxId);
		break;

	case 8:
		cout << "Thank you for using our program. See you soon!" << endl;
		return false;

	default:
		cout << "There seems to be a problem with your input. Please try again later." << endl;
		break;

	}

	return true;
}

int main() {

	int visitorCount = 0;
	int maxId = 1;
	VISITOR visitors[30];

	initializingData(visitors, visitorCount, maxId);

	bool doShowMenu = 1;

	do {

		doShowMenu = showMainMenu(visitors, visitorCount, maxId);
	} while (doShowMenu);

}