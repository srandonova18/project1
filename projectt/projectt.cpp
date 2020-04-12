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

void newVisitor(VISITOR* visitors){}

void editVisitor(VISITOR* visitors, VISITOR newVisitor, int& visitorsCount, int& maxId) {}

void deleteVisitor(){}

VISITOR findVisitor(VISITOR*visitor,int& VisitorCount,string FirstName,string LastName){
    {
        for (int i = 0; i < VisitorCount; i++)
        {
            if (visitor[i].firstName > FirstName && visitor[i].lastName == LastName)
            {
                showVisitor(visitor[i]);
            }
        }
    }
}

int getNumberOfVisitorsPerDay(){}

int getNumberOfBooksBorrowedPerDay(){}

//Presentation layer



//testPush
//PushTest2

void showVisitor(VISITOR visitor)
{
    {
            cout << "Visitor First Name: " << visitor.firstName << endl;
            cout << "Vistor Last Name: " << visitor.lastName << endl;
            cout << "Visitor Age: " << visitor.age << endl;
    }
}

void newVisitorMenu(){}

void showVisitorMenu(){}

void deleteVisitorMenu(){}

void showReportsMenu(){}

void editVisitorMenu(VISITOR* visitors, int& visitorsCount) {}

bool showMainMenu(VISITOR* visitors, int& visitorCount, int& maxId){

    int choice;

    cout << "\nMAIN MENU" << endl;
    cout << "1. Register a new visitor" << endl;
    cout << "2. Show all visitors' profiles" << endl;
    cout << "3. Edit an existing visitor's profile" << endl;
    cout << "4. Delete an existing visitor's profile" << endl;
    cout << "5. Reports" << endl;
    cout << "6. Exit" << endl;
    cout << "Your choice is: ";

    cin >> choice;

    switch (choice) {

    case 1: {

        newVisitorMenu();
        break;
    }

    case 2: {

        showVisitorMenu();
        break;
    }

    case 3: {

        editVisitorMenu(visitors, visitorCount);
        break;
    }

    case 4: {

        deleteVisitorMenu();
        break;
    }

    case 5: {

        showReportsMenu();
        break;
    }

    case 6: {

        return false;
    }

    default: break;

    }
}

int main() {}




