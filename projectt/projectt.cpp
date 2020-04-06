#include <iostream>
using namespace std;

struct BOOK {

    string title = "";
    string authorName = "";
    int yearOfRelease = 0;
};

struct VISITOR {

    string firstName = "";
    string lastName = "";
    int age = 0;
    int numberOfBooks = 0;
    string dayOfVisit = "";
    BOOK books[100];
};

//CRUD

int findVisitorById(){}

void newVisitor(){}

void editVisitor(){}

void deleteVisitor(){}

VISITOR findVisitor(){}

int getNumberOfVisitorsPerDay(){}

int getNumberOfBooksBorrowedPerDay(){}

//Presentation layer

void showVisitor(){}

void newVisitorMenu(){}

void showVisitorMenu(){}

void deleteVisitorMenu(){}

void editVisitorMenu(){}

void showMainMenu(){}

int main(){}




