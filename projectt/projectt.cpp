#include <iostream>
using namespace std;

struct BOOK {

    string title = "";
    string authorName = "";
    int yearOfRelease = 0;
};

enum WEEK_DAYS {

    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};

struct VISITOR {

    string firstName = "";
    string lastName = "";
    int age;
    int numberOfBooks = 0;
    WEEK_DAYS dayOfTheWeek;
    BOOK books[100];
};

//CRUD

int findVisitorById(VISITOR* visitors, int& visitorsCount, int id) {}

void newVisitor(){}

void editVisitor(VISITOR* visitors, VISITOR newVisitor, int& visitorsCount, int& maxId) {}

void deleteVisitor(){}

VISITOR findVisitor(){}

int getNumberOfVisitorsPerDay(){}

int getNumberOfBooksBorrowedPerDay(){}

//Presentation layer

void showVisitor(){}

void newVisitorMenu(){}

void showVisitorMenu(){}

void deleteVisitorMenu(){}

void editVisitorMenu(VISITOR* visitors, int& visitorsCount) {}

bool showMainMenu(VISITOR* visitors, int& visitorCount, int& maxId){}

int main() {}




